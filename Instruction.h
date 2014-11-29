/*
Copyright (C) 2006 - 2014 Evan Teran
                          eteran@alum.rit.edu

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef INSTRUCTION_20070427_H_
#define INSTRUCTION_20070427_H_

#include "ModRM.h"
#include "Model.h"
#include "Operand.h"
#include "edisassm_exception.h"
#include "edisassm_types.h"
#include <cstddef>

#ifdef QT_CORE_LIB
#include <QtGlobal>
#ifdef QT_PLUGIN
#define EDB_EXPORT Q_DECL_IMPORT
#else
#define EDB_EXPORT Q_DECL_EXPORT
#endif
#else
#define EDB_EXPORT
#endif

#ifndef INVALID_BLOCK
#define INVALID_BLOCK \
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },\
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },\
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },\
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },\
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },\
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },\
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },\
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },\
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },\
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },\
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },\
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },\
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },\
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },\
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },\
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE }
#endif

namespace edisassm {

namespace {
	struct modrm_32 { static const int value = 32; };
	struct modrm_64 { static const int value = 64; };
}

template <class M>
class EDB_EXPORT Instruction {
	template <class U>
	friend bool operator==(const Instruction<U> &lhs, const Instruction<U> &rhs);

	template <class U>
	friend bool operator!=(const Instruction<U> &lhs, const Instruction<U> &rhs);

private:
	class stream_base {
	public:
		virtual ~stream_base() {}
		virtual uint8_t next() = 0;
		virtual uint8_t peek() const = 0;
		virtual bool empty() const = 0;
		virtual stream_base *clone() = 0;
	};

	template <class In>
	class stream_iterator : public stream_base {
	public:
		stream_iterator(In first, In last) : first_(first), last_(last) {
		}

	private:
		stream_iterator(const stream_iterator &);
		stream_iterator &operator=(const stream_iterator &);

	public:
		virtual uint8_t next()       { return *first_++; }
		virtual uint8_t peek() const { return *first_; }
		virtual bool empty() const   { return first_ == last_; }
		virtual stream_base *clone() { return new stream_iterator(first_, last_); }

	private:
		In first_;
		In last_;
	};

public:
	static const int MAX_OPERANDS = M::MAX_OPERANDS;
	static const int MAX_SIZE     = M::MAX_SIZE;
	static const int BITS         = M::BITS;

public:
	typedef Operand<M>               operand_type;
	typedef typename M::address_type address_type;
	typedef Instruction<M>           instruction_type;

public:
	typedef void (instruction_type::*decoder_t)();

public:
	template <class In>
	Instruction(In first, In last, address_type rva, const std::nothrow_t&) throw() :
			byte_stream_(new stream_iterator<In>(first, last)), byte_index_(0), byte1_(0x00), byte2_(0x00), byte3_(0x00),
			modrm_byte_(0x00), sib_byte_(0x00), rex_byte_(0x00), rva_(rva),
			opcode_(&Opcode_invalid), prefix_(0x00000000), mandatory_prefix_(0x00000000),
			operand_count_(0), modrm_size_(0), sib_size_(0), disp_size_(0), prefix_size_(0),
			immediate_size_(0), rex_size_(0) {

		try {
			disassemble();
		} catch(const invalid_instruction &) {
			opcode_ = &Opcode_invalid;
			//throw;
		}
	}


	template <class In>
	Instruction(In first, In last, address_type rva) :
			byte_stream_(new stream_iterator<In>(first, last)), byte_index_(0), byte1_(0x00), byte2_(0x00), byte3_(0x00),
			modrm_byte_(0x00), sib_byte_(0x00), rex_byte_(0x00), rva_(rva),
			opcode_(&Opcode_invalid), prefix_(0x00000000), mandatory_prefix_(0x00000000),
			operand_count_(0), modrm_size_(0), sib_size_(0), disp_size_(0), prefix_size_(0),
			immediate_size_(0), rex_size_(0) {

		disassemble();
	}

	~Instruction();

public:
	Instruction(const Instruction &);
	Instruction &operator=(const Instruction &);

public:
	void swap(Instruction &other);

private:
	void disassemble();

public:
	enum Flags {
		FLAG_NONE           = 0x00000000,
		FLAG_R_FLAGS        = 0x00000001,
		FLAG_W_FLAGS        = 0x00000002,
		FLAG_RW_FLAGS       = (FLAG_R_FLAGS | FLAG_W_FLAGS),
		FLAG_STACK          = 0x00000004,
		FLAG_RING0          = 0x00000008,
		FLAG_UNDOCUMENTED   = 0x00000010,
		FLAG_AMD            = 0x00000020,
		FLAG_INTEL          = 0x00000040,
		FLAG_32BIT_ONLY     = 0x00000080,
		FLAG_64BIT_ONLY     = 0x00000100,
		FLAG_FPU            = 0x00000200,
		FLAG_286_ONLY       = 0x00000400,
		FLAG_MMX            = 0x00000800,
		FLAG_SSE            = 0x00001000,
		FLAG_SSE2           = 0x00002000,
		FLAG_SSE3           = 0x00004000,
		FLAG_SSSE3          = 0x00008000,
		FLAG_SSE4           = 0x00010000,
		FLAG_SSE4a          = 0x00020000,
		FLAG_SSE4_1         = 0x00040000,
		FLAG_SSE4_2         = 0x00080000,
		FLAG_PENTIUM_PRO    = 0x00100000,
		FLAG_VMX            = 0x00200000
	};

	enum Prefix {
		PREFIX_NONE             = 0x00000000,
		PREFIX_LOCK             = 0x00000001,
		PREFIX_REPNE            = 0x00000002,
		PREFIX_REP              = 0x00000004,

		PREFIX_CS               = 0x00000100,
		PREFIX_SS               = 0x00000200,
		PREFIX_DS               = 0x00000400,
		PREFIX_ES               = 0x00000800,
		PREFIX_FS               = 0x00001000,
		PREFIX_GS               = 0x00002000,
		PREFIX_BRANCH_NOT_TAKEN = 0x00004000,
		PREFIX_BRANCH_TAKEN     = 0x00008000,

		PREFIX_OPERAND          = 0x00010000,

		PREFIX_ADDRESS          = 0x01000000
	};

	enum Type {
		// invalid
		OP_INVALID = 0x00000000,

		// data transfer
		OP_MOV,
		OP_CMOVCC,
		OP_XCHG,
		OP_BSWAP,
		OP_XADD,
		OP_CMPXCHG,
		OP_PUSH,
		OP_PUSHA,
		OP_POP,
		OP_POPA,
		OP_CWD,
		OP_CDQ,
		OP_CQO,
		OP_CDQE,
		OP_CBW,
		OP_CWDE,
		OP_MOVSX,
		OP_MOVZX,
		OP_MOVSXD,
		OP_MOVBE,

		// arithmetic
		OP_AAA,
		OP_AAD,
		OP_AAM,
		OP_AAS,
		OP_ADC,
		OP_ADD,
		OP_CMP,
		OP_DAA,
		OP_DAS,
		OP_DEC,
		OP_DIV,
		OP_IDIV,
		OP_IMUL,
		OP_INC,
		OP_MUL,
		OP_NEG,
		OP_SALC,
		OP_SBB,
		OP_SUB,

		// logic
		OP_AND,
		OP_OR,
		OP_XOR,
		OP_NOT,

		// shift/rotate
		OP_SAR,
		OP_SAL,
		OP_SHR,
		OP_SHL,
		OP_SHRD,
		OP_SHLD,
		OP_ROR,
		OP_ROL,
		OP_RCR,
		OP_RCL,

		// bit/byte
		OP_BT,
		OP_BTS,
		OP_BTR,
		OP_BTC,
		OP_BSF,
		OP_BSR,
		OP_SETCC,
		OP_TEST,

		// control flow
		OP_JMP,
		OP_JCC,
		OP_LOOP,
		OP_LOOPE,
		OP_LOOPNE,
		OP_CALL,
		OP_RET,
		OP_RETF,
		OP_IRET,
		OP_INT,
		OP_INT3,
		OP_INTO,
		OP_BOUND,
		OP_ENTER,
		OP_LEAVE,

		// string
		OP_MOVS,
		OP_CMPS,
		OP_CMPSW,
		OP_SCAS,
		OP_LODS,
		OP_STOS,

		// I/O
		OP_IN,
		OP_OUT,
		OP_INS,
		OP_OUTS,

		// flag control
		OP_STC,
		OP_CLC,
		OP_CMC,
		OP_CLD,
		OP_STD,
		OP_LAHF,
		OP_SAHF,
		OP_PUSHF,
		OP_POPF,
		OP_STI,
		OP_CLI,

		// segment manipulation
		OP_LDS,
		OP_LES,
		OP_LFS,
		OP_LGS,
		OP_LSS,
		OP_SWAPGS,

		// misc
		OP_PEXTRQ,
		OP_PINSRQ,
		OP_LEA,
		OP_NOP,
		OP_UD,
		OP_UD2,
		OP_XLAT,
		OP_CPUID,
		OP_CRC32,
		OP_XSAVE,
		OP_XRSTOR,
		OP_GETSEC,
		OP_PBLENDVB,
		OP_BLENDVPS,
		OP_BLENDVPD,
		OP_PTEST,
		OP_PMOVSXBW,
		OP_PMOVSXBD,
		OP_PMOVSXBQ,
		OP_PMOVSXWD,
		OP_PMOVSXWQ,
		OP_PMOVSXDQ,
		OP_PMULDQ,
		OP_PCMPEQQ,
		OP_MOVNTDQA,
		OP_PACKUSDW,
		OP_PMOVZXBW,
		OP_PMOVZXBD,
		OP_PMOVZXBQ,
		OP_PMOVZXWD,
		OP_PMOVZXWQ,
		OP_PMOVZXDQ,
		OP_PCMPGTQ,
		OP_PMINSB,
		OP_PMINSD,
		OP_PMINUW,
		OP_PMINUD,
		OP_PMAXSB,
		OP_PMAXSD,
		OP_PMAXUW,
		OP_PMAXUD,
		OP_PMULLD,
		OP_PHMINPOSUW,
		OP_NVEPT,
		OP_NVVPID,
		OP_ROUNDPS,
		OP_ROUNDPD,
		OP_ROUNDSS,
		OP_ROUNDSD,
		OP_BLENDPS,
		OP_BLENDPD,
		OP_PBLENDW,
		OP_PEXTRB,
		OP_PEXTRD,
		OP_EXTRACTPS,
		OP_PINSRB,
		OP_INSERTPS,
		OP_PINSRD,
		OP_DPPS,
		OP_DPPD,
		OP_MPSADBW,
		OP_PCMPESTRM,
		OP_PCMPESTRI,
		OP_PCMPISTRM,
		OP_PCMPISTRI,

		// misc
		OP_CMPXCHG8B,
		OP_CMPXCHG16B,


		// VM
		OP_VMCALL,
		OP_VMCLEAR,
		OP_VMLAUNCH,
		OP_VMPTRLD,
		OP_VMPTRST,
		OP_VMRESUME,
		OP_VMXOFF,
		OP_VMXON,
		OP_VMREAD,
		OP_VMWRITE,
		OP_XGETBV,
		OP_XSETBV,

		// system
		OP_LGDT,
		OP_SGDT,
		OP_LLDT,
		OP_SLDT,
		OP_LTR,
		OP_STR,
		OP_LIDT,
		OP_SIDT,
		OP_LMSW,
		OP_SMSW,
		OP_CLTS,
		OP_ARPL,
		OP_LAR,
		OP_LSL,
		OP_VERR,
		OP_VERW,
		OP_INVD,
		OP_WBINVD,
		OP_INVLPG,
		OP_HLT,
		OP_RSM,
		OP_RDMSR,
		OP_WRMSR,
		OP_RDPMC,
		OP_RDTSC,
		OP_SYSENTER,
		OP_SYSEXIT,
		OP_SYSCALL,
		OP_SYSRET,

		// MMX
		OP_EMMS,
		OP_MOVD,
		OP_MOVQ,
		OP_PABSD,   // intel says this is both MMX and SSSE3!
		OP_PACKSSDW,
		OP_PACKSSWB,
		OP_PACKUSWB,
		OP_PADDB,
		OP_PADDD,
		OP_PADDSB,
		OP_PADDSW,
		OP_PADDUSB,
		OP_PADDUSW,
		OP_PADDW,
		OP_PAND,
		OP_PANDN,
		OP_PCMPEQB,
		OP_PCMPEQD,
		OP_PCMPEQW,
		OP_PCMPGTB,
		OP_PCMPGTD,
		OP_PCMPGTW,
		OP_PMADDWD,
		OP_PMULHW,
		OP_PMULLW,
		OP_POR,
		OP_PSLLD,
		OP_PSLLQ,
		OP_PSLLW,
		OP_PSRAD,
		OP_PSRAW,
		OP_PSRLD,
		OP_PSRLQ,
		OP_PSRLW,
		OP_PSUBB,
		OP_PSUBD,
		OP_PSUBSB,
		OP_PSUBSW,
		OP_PSUBUSB,
		OP_PSUBUSW,
		OP_PSUBW,
		OP_PUNPCKHBW,
		OP_PUNPCKHDQ,
		OP_PUNPCKHWD,
		OP_PUNPCKLBW,
		OP_PUNPCKLDQ,
		OP_PUNPCKLWD,
		OP_PXOR,


		// SSE
		OP_MOVAPS,
		OP_MOVUPS,
		OP_MOVHPS,
		// TODO: MOVHLPS? where is it?
		OP_MOVLPS,
		// TODO: MOVLHPS? where is it?
		OP_MOVMSKPS,
		OP_MOVSS,
		OP_ADDPS,
		OP_ADDSS,
		OP_SUBPS,
		OP_SUBSS,
		OP_MULPS,
		OP_MULSS,
		OP_DIVPS,
		OP_DIVSS,
		OP_RCPPS,
		OP_RCPSS,
		OP_SQRTPS,
		OP_SQRTSS,
		OP_RSQRTPS,
		OP_RSQRTSS,
		OP_MAXPS,
		OP_MAXSS,
		OP_MINPS,
		OP_MINSS,
		OP_CMPPS,
		OP_CMPSS,
		OP_COMISS,
		OP_UCOMISS,
		OP_ANDPS,
		OP_ANDNPS,
		OP_ORPS,
		OP_XORPS,
		OP_SHUFPS,
		OP_UNPCKHPS,
		OP_UNPCKLPS,
		OP_CVTPI2PS,
		OP_CVTSI2SS,
		OP_CVTPS2PI,
		OP_CVTTPS2PI,
		OP_CVTSS2SI,
		OP_CVTTSS2SI,
		OP_LDMXCSR,
		OP_STMXCSR,
		OP_PAVGB,
		OP_PAVGW, // Introduced in MMX?
		OP_PEXTRW,
		OP_PINSRW,
		OP_PMAXUB,
		OP_PMAXSW,
		OP_PMINUB,
		OP_PMINSW,
		OP_PMOVMSKB,
		OP_PMULHUW,
		OP_PSADBW,
		OP_PSHUFW,
		OP_MASKMOVQ,
		OP_MOVNTQ,
		OP_MOVNTPS,
		OP_PREFETCHH,
		OP_SFENCE,

		// SSE2
		OP_ADDPD,
		OP_ADDSD,
		OP_ANDNPD,
		OP_ANDPD,
		OP_CLFLUSH,
		OP_CMPPD,
		OP_CMPSD,
		OP_COMISD,
		OP_CVTDQ2PD,
		OP_CVTDQ2PS,
		OP_CVTPD2DQ,
		OP_CVTPD2PI,
		OP_CVTPD2PS,
		OP_CVTPI2PD,
		OP_CVTPS2DQ,
		OP_CVTPS2PD,
		OP_CVTSD2SI,
		OP_CVTSD2SS,
		OP_CVTSI2SD,
		OP_CVTSS2SD,
		OP_CVTTPD2DQ,
		OP_CVTTPD2PI,
		OP_CVTTPS2DQ,
		OP_CVTTSD2SI,
		OP_DIVPD,
		OP_DIVSD,
		OP_LFENCE,
		OP_MASKMOVDQU,
		OP_MAXPD,
		OP_MAXSD,
		OP_MFENCE,
		OP_MINPD,
		OP_MINSD,
		OP_MOVAPD,
		OP_MOVDQ2Q,
		OP_MOVDQA,
		OP_MOVDQU,
		OP_MOVHPD,
		OP_MOVLPD,
		OP_MOVMSKPD,
		OP_MOVNTDQ,
		OP_MOVNTI,
		OP_MOVNTPD,
		OP_MOVQ2DQ,
		OP_MOVSD,
		OP_MOVUPD,
		OP_MULPD,
		OP_MULSD,
		OP_ORPD,
		OP_PADDQ,
		OP_PAUSE,
		OP_PMULUDQ,
		OP_PSHUFD,
		OP_PSHUFHW,
		OP_PSHUFLW,
		OP_PSLLDQ,
		OP_PSRLDQ,
		OP_PSUBQ,
		OP_PUNPCKHQDQ,
		OP_PUNPCKLQDQ,
		OP_SHUFPD,
		OP_SQRTPD,
		OP_SQRTSD,
		OP_SUBPD,
		OP_SUBSD,
		OP_UCOMISD,
		OP_UNPCKHPD,
		OP_UNPCKLPD,
		OP_XORPD,

		// SSE3
		OP_ADDSUBPD,
		OP_ADDSUBPS,
		OP_FISTTP,
		OP_HADDPD,
		OP_HADDPS,
		OP_HSUBPD,
		OP_HSUBPS,
		OP_LDDQU,
		OP_MONITOR,
		OP_MOVDDUP,
		OP_MOVSHDUP,
		OP_MOVSLDUP,
		OP_MWAIT,

		// SSSE3
		OP_PABSB,
		OP_PABSW,
		OP_PALIGNR,
		OP_PHADDD,
		OP_PHADDSW,
		OP_PHADDW,
		OP_PHSUBD,
		OP_PHSUBSW,
		OP_PHSUBW,
		OP_PMADDUBSW,
		OP_PMULHRSW,
		OP_PSHUFB,
		OP_PSIGNB,
		OP_PSIGND,
		OP_PSIGNW,

		// SSE4a
		OP_LZCNT,   // TODO: implement in tables..
		OP_MOVNTSD, // TODO: implement in tables..
		OP_MOVNTSS, // TODO: implement in tables..
		OP_POPCNT,

		// TODO: 3DNow!
		// TODO: EMMI
		// TODO: Athlon
		// TODO: Geode GX
		// TODO: Intel AVX FMA
		// TODO: Intel AES

		// FPU ops
		OP_F2XM1,
		OP_FABS,
		OP_FADD,
		OP_FADDP,
		OP_FBLD,
		OP_FBSTP,
		OP_FCHS,
		OP_FCLEX,
		OP_FCMOVB,
		OP_FCMOVBE,
		OP_FCMOVE,
		OP_FCMOVNB,
		OP_FCMOVNBE,
		OP_FCMOVNE,
		OP_FCMOVNU,
		OP_FCMOVU,
		OP_FCOM,
		OP_FCOMI,
		OP_FCOMIP,
		OP_FCOMP,
		OP_FCOMPP,
		OP_FCOS,
		OP_FDECSTP,
		OP_FDISI,
		OP_FDIV,
		OP_FDIVP,
		OP_FDIVR,
		OP_FDIVRP,
		OP_FENI,
		OP_FFREE,
		OP_FIADD,
		OP_FICOM,
		OP_FICOMP,
		OP_FIDIV,
		OP_FIDIVR,
		OP_FILD,
		OP_FIMUL,
		OP_FINCSTP,
		OP_FINIT,
		OP_FIST,
		OP_FISTP,
		OP_FISUB,
		OP_FISUBR,
		OP_FLD,
		OP_FLD1,
		OP_FLDCW,
		OP_FLDENV,
		OP_FLDL2E,
		OP_FLDL2T,
		OP_FLDLG2,
		OP_FLDLN2,
		OP_FLDPI,
		OP_FLDZ,
		OP_FMUL,
		OP_FMULP,
		OP_FNCLEX,
		OP_FNDISI,
		OP_FNENI,
		OP_FNINIT,
		OP_FNOP,
		OP_FNSAVE,
		OP_FNSETPM,
		OP_FNSTCW,
		OP_FNSTENV,
		OP_FNSTSW,
		OP_FPATAN,
		OP_FPREM,
		OP_FPREM1,
		OP_FPTAN,
		OP_FRNDINT,
		OP_FRSTOR,
		OP_FSAVE,
		OP_FSCALE,
		OP_FSETPM,
		OP_FSIN,
		OP_FSINCOS,
		OP_FSQRT,
		OP_FST,
		OP_FSTCW,
		OP_FSTENV,
		OP_FSTP,
		OP_FSTPNCE,
		OP_FSTSW,
		OP_FSUB,
		OP_FSUBP,
		OP_FSUBR,
		OP_FSUBRP,
		OP_FTST,
		OP_FUCOM,
		OP_FUCOMI,
		OP_FUCOMIP,
		OP_FUCOMP,
		OP_FUCOMPP,
		OP_FXAM,
		OP_FXCH,
		OP_FXRSTOR,
		OP_FXSAVE,
		OP_FXTRACT,
		OP_FYL2X,
		OP_FYL2XP1,
		OP_WAIT,

		// AMD extensions
		OP_CLGI,
		OP_INVLPGA,
		OP_RDTSCP,
		OP_SKINIT,
		OP_STGI,
		OP_VMLOAD,
		OP_VMMCALL,
		OP_VMRUN,
		OP_VMSAVE,

		// undocumented


		// these aren't really valid, should never been seen in any external API
		OP_GROUP,
		OP_PREFIX,
		OP_2BYTE,
		OP_3BYTE,
		OP_FPU
	};

private:
	void process_prefixes();
	operand_type &next_operand();
	uint8_t next_byte();

private:
	// convenience binders,
	template <decoder_t F1, decoder_t F2, decoder_t F3>
	void decode3() {
		(this->*F1)();
		(this->*F2)();
		(this->*F3)();
	}

	template <decoder_t F1, decoder_t F2>
	void decode2() {
		(this->*F1)();
		(this->*F2)();
	}

	template <decoder_t F1>
	void decode1() {
		(this->*F1)();
	}

	void decode0() {
	}

private:

	template <class T>
	void decode_size_sensitive(const T(&opcodes)[3]) {
		switch(operand_size()) {
		case 16: opcode_ = &opcodes[0]; break;
		case 32: opcode_ = &opcodes[1]; break;
		case 64: opcode_ = &opcodes[2]; break;
		}
		(this->*(opcode_->decoder))();
	}

	// special FPU variants..
	void wait_or_wait_prefix();

	// special cased names
	void decode_cwd_cdq_cqo();
	void decode_stosw_stosd_stosq();
	void decode_lodsw_lodsd_lodsq();
	void decode_cbw_cwde_cdqe();
	void decode_scasw_scasd_scasq();
	void decode_iretw_iret_iretq();
	void decode_pushfw_pushfd_pushfq();
	void decode_popfw_popfd_popfq();
	void decode_movsw_movsd_movsq();
	void decode_jcxz_jecxz_jrcxz();

	void decode_invalid_cmpxchg8b_cmpxchg16b();

	// no 64-bit variant
	void decode_cmpsw_cmpsd_cmpsq();
	void decode_outsw_outsd_invalid();
	void decode_insw_insd_invalid();
	void decode_pushaw_pushad_invalid();
	void decode_popaw_popad_invalid();

private:
	// groups
	void decode_group1();
	void decode_group2();
	void decode_group2D();
	void decode_group3();
	void decode_group4();
	void decode_group5();
	void decode_group6();
	void decode_group7();
	void decode_group8();
	void decode_group9();
	void decode_group10();
	void decode_group11();
	void decode_group12();
	void decode_group13();
	void decode_group14();
	void decode_group15();
	void decode_group16();
	void decode_group17();

private:
	// invalid handler
	void decode_invalid();

private:
	// multibyte encodings
	void decode_x87();
	void decode_2byte();
	void decode_3byte_38();
	void decode_3byte_3A();

private:
	uint8_t get_modrm();
	uint8_t get_sib();

	template <typename operand_type::Register REG>
	void decode_Reg();

	template <int64_t IMM>
	void decode_const_Iq();

	template <int32_t IMM>
	void decode_const_Id();

	template <int16_t IMM>
	void decode_const_Iw();

	template <int8_t IMM>
	void decode_const_Ib();

	int8_t   get_immediate_s8();
	int16_t  get_immediate_s16();
	int32_t  get_immediate_s32();
	int64_t  get_immediate_s64();
	uint8_t  get_immediate_u8();
	uint16_t get_immediate_u16();
	uint32_t get_immediate_u32();
	uint64_t get_immediate_u64();

	int8_t  get_displacement_s8();
	int16_t get_displacement_s16();
	int32_t get_displacement_s32();
	int64_t get_displacement_s64();

	template <int index>
	void decode_STi();

	template <typename operand_type::Register (*REG_DECODE)(uint8_t)>
	void decode_Gx();

	template <typename operand_type::Type TYPE, typename operand_type::Register (*REG_DECODE)(uint8_t)>
	void decode_ModRM_0_16(uint8_t modrm_byte, operand_type &op);

	template <typename operand_type::Type TYPE, typename operand_type::Register (*REG_DECODE)(uint8_t)>
	void decode_ModRM_1_16(uint8_t modrm_byte, operand_type &op);

	template <typename operand_type::Type TYPE, typename operand_type::Register (*REG_DECODE)(uint8_t)>
	void decode_ModRM_2_16(uint8_t modrm_byte, operand_type &op);

	template <typename operand_type::Type TYPE, typename operand_type::Register (*REG_DECODE)(uint8_t), class DecodeMode>
	void decode_ModRM_0_32(uint8_t modrm_byte, operand_type &op);

	template <typename operand_type::Type TYPE, typename operand_type::Register (*REG_DECODE)(uint8_t), class DecodeMode>
	void decode_ModRM_1_32(uint8_t modrm_byte, operand_type &op);

	template <typename operand_type::Type TYPE, typename operand_type::Register (*REG_DECODE)(uint8_t), class DecodeMode>
	void decode_ModRM_2_32(uint8_t modrm_byte, operand_type &op);

	template <typename operand_type::Type TYPE, typename operand_type::Register (*REG_DECODE)(uint8_t), class DecodeMode>
	void decode_ModRM_3_32(uint8_t modrm_byte, operand_type &op);

	template <typename operand_type::Type TYPE, typename operand_type::Register (*REG_DECODE)(uint8_t)>
	void decode_ModRM_Invalid(uint8_t modrm_byte, operand_type &op);

	template <typename operand_type::Type TYPE, typename operand_type::Register (*REG_DECODE)(uint8_t)>
	void decode_Ex();

private:
	// ModRM Reg or Memory
	void decode_Eb() { decode_Ex<operand_type::TYPE_EXPRESSION8,  &Instruction<M>::index_to_reg_8>(); }
	void decode_Ew() { decode_Ex<operand_type::TYPE_EXPRESSION16, &Instruction<M>::index_to_reg_16>(); }
	void decode_Ed() { decode_Ex<operand_type::TYPE_EXPRESSION32, &Instruction<M>::index_to_reg_32>(); }
	void decode_Eq() { decode_Ex<operand_type::TYPE_EXPRESSION64, &Instruction<M>::index_to_reg_64>(); }
	void decode_Ev();
	void decode_Qd() { decode_Ex<operand_type::TYPE_EXPRESSION32,  &Instruction<M>::index_to_reg_mmx>(); }
	void decode_Qq() { decode_Ex<operand_type::TYPE_EXPRESSION64,  &Instruction<M>::index_to_reg_mmx>(); }
	void decode_Qo() { decode_Ex<operand_type::TYPE_EXPRESSION128, &Instruction<M>::index_to_reg_mmx>(); }
	void decode_Ww() { decode_Ex<operand_type::TYPE_EXPRESSION16,  &Instruction<M>::index_to_reg_xmmx>(); }
	void decode_Wd() { decode_Ex<operand_type::TYPE_EXPRESSION32,  &Instruction<M>::index_to_reg_xmmx>(); }
	void decode_Wq() { decode_Ex<operand_type::TYPE_EXPRESSION64,  &Instruction<M>::index_to_reg_xmmx>(); }
	void decode_Wo() { decode_Ex<operand_type::TYPE_EXPRESSION128, &Instruction<M>::index_to_reg_xmmx>(); }


	// special cases for things like SMSW Rv/Mw
	template <decoder_t F1, decoder_t F2>
	void decode_Reg_Mem() {
		const uint8_t modrm_byte = get_modrm();

		if(modrm::mod(modrm_byte) == 0x03) {
			(this->*F1)();
		} else {
			(this->*F2)();
		}
	}

	void decode_Rv_Mw() { decode_Reg_Mem<&instruction_type::decode_Rv, &instruction_type::decode_Mw>(); }
	void decode_Rq_Mw() { decode_Reg_Mem<&instruction_type::decode_Rq, &instruction_type::decode_Mw>(); }
	void decode_Rd_Mw() { decode_Reg_Mem<&instruction_type::decode_Rd, &instruction_type::decode_Mw>(); }
	void decode_Rd_Mb() { decode_Reg_Mem<&instruction_type::decode_Rd, &instruction_type::decode_Mb>(); }
	void decode_Uo_Mw() { decode_Reg_Mem<&instruction_type::decode_Uo, &instruction_type::decode_Mw>(); }
	void decode_Uo_Md() { decode_Reg_Mem<&instruction_type::decode_Uo, &instruction_type::decode_Md>(); }
	void decode_Uo_Mq() { decode_Reg_Mem<&instruction_type::decode_Uo, &instruction_type::decode_Mq>(); }

	// TODO: throw an error if any of these return REG_INVALID
	// ModRM Memory Only
	void decode_Mo()   { decode_Ex<operand_type::TYPE_EXPRESSION128, &Instruction<M>::index_to_reg_invalid>(); }
	void decode_M()    { decode_Ex<operand_type::TYPE_EXPRESSION, &Instruction<M>::index_to_reg_invalid>(); }
	void decode_Ms()   { decode_Ex<operand_type::TYPE_EXPRESSION, &Instruction<M>::index_to_reg_invalid>(); }
	void decode_M108() { decode_Ex<operand_type::TYPE_EXPRESSION, &Instruction<M>::index_to_reg_invalid>(); }  // Note this can be 108 or 98, but we just say "expression"
	void decode_M512() { decode_Ex<operand_type::TYPE_EXPRESSION, &Instruction<M>::index_to_reg_invalid>(); }  // Note this can be 512 or 256, but we just say "expression"
	void decode_M28()  { decode_Ex<operand_type::TYPE_EXPRESSION, &Instruction<M>::index_to_reg_invalid>(); }  // Note this can be 28 or 14, but we just say "expression"
	void decode_Mw()   { decode_Ex<operand_type::TYPE_EXPRESSION16, &Instruction<M>::index_to_reg_invalid>(); }
	void decode_Mp()   { decode_Ep();}
	void decode_Mdq()  { decode_Ex<operand_type::TYPE_EXPRESSION128, &Instruction<M>::index_to_reg_invalid>(); }
	void decode_Mq()   { decode_Ex<operand_type::TYPE_EXPRESSION64, &Instruction<M>::index_to_reg_invalid>(); }
	void decode_Md()   { decode_Ex<operand_type::TYPE_EXPRESSION32, &Instruction<M>::index_to_reg_invalid>(); }
	void decode_Mb()   { decode_Ex<operand_type::TYPE_EXPRESSION8, &Instruction<M>::index_to_reg_invalid>(); }
	void decode_Ma()   { if(prefix_ & PREFIX_OPERAND) { decode_Ex<operand_type::TYPE_EXPRESSION32, &Instruction<M>::index_to_reg_invalid>(); } else { decode_Ex<operand_type::TYPE_EXPRESSION64, &Instruction<M>::index_to_reg_invalid>(); } }
	void decode_Mv();
	void decode_Ep()   { if(prefix_ & PREFIX_OPERAND) { decode_Ex<operand_type::TYPE_EXPRESSION32, &Instruction<M>::index_to_reg_invalid>(); } else { decode_Ex<operand_type::TYPE_EXPRESSION48, &Instruction<M>::index_to_reg_invalid>(); } }


	// FPU memory only
	void decode_WordInteger()  { decode_Ex<operand_type::TYPE_EXPRESSION16, &Instruction<M>::index_to_reg_invalid>(); }
	void decode_SingleReal()   { decode_Ex<operand_type::TYPE_EXPRESSION32, &Instruction<M>::index_to_reg_invalid>(); }
	void decode_ShortInteger() { decode_Ex<operand_type::TYPE_EXPRESSION32, &Instruction<M>::index_to_reg_invalid>(); }
	void decode_DoubleReal()   { decode_Ex<operand_type::TYPE_EXPRESSION64, &Instruction<M>::index_to_reg_invalid>(); }
	void decode_LongInteger()  { decode_Ex<operand_type::TYPE_EXPRESSION64, &Instruction<M>::index_to_reg_invalid>(); }
	void decode_ExtendedReal() { decode_Ex<operand_type::TYPE_EXPRESSION80, &Instruction<M>::index_to_reg_invalid>(); }
	void decode_PackedBCD()    { decode_Ex<operand_type::TYPE_EXPRESSION80, &Instruction<M>::index_to_reg_invalid>(); }

	// ModRM selects a register only (mod must be 0x3)
	// TODO: throw an error if any of these return TYPE_INVALID
	void decode_Rv();
	void decode_Rw() { decode_Ex<operand_type::TYPE_INVALID, &Instruction<M>::index_to_reg_16>(); }
	void decode_Rd() { decode_Ex<operand_type::TYPE_INVALID, &Instruction<M>::index_to_reg_32>(); }
	void decode_Rq() { decode_Ex<operand_type::TYPE_INVALID, &Instruction<M>::index_to_reg_64>(); }
	void decode_Nq() { decode_Ex<operand_type::TYPE_INVALID, &Instruction<M>::index_to_reg_mmx>(); }
	void decode_Uo() { decode_Ex<operand_type::TYPE_INVALID, &Instruction<M>::index_to_reg_xmmx>(); }
	void decode_Uq() { decode_Ex<operand_type::TYPE_INVALID, &Instruction<M>::index_to_reg_xmmx>(); }

	// ModRM Reg Field
	void decode_Gv();
	void decode_Gb() { decode_Gx<&Instruction<M>::index_to_reg_8>(); }
	void decode_Gw() { decode_Gx<&Instruction<M>::index_to_reg_16>(); }
	void decode_Gd() { decode_Gx<&Instruction<M>::index_to_reg_32>(); }
	void decode_Gq() { decode_Gx<&Instruction<M>::index_to_reg_64>(); }
	void decode_Gz() { if(prefix_ & PREFIX_OPERAND) { decode_Gx<&Instruction<M>::index_to_reg_16>(); } else { decode_Gx<&Instruction<M>::index_to_reg_32>(); } }
	void decode_Vo() { decode_Gx<&Instruction<M>::index_to_reg_xmmx>(); }
	void decode_Vd() { decode_Gx<&Instruction<M>::index_to_reg_xmmx>(); }
	void decode_Vq() { decode_Gx<&Instruction<M>::index_to_reg_xmmx>(); }
	void decode_Pq() { decode_Gx<&Instruction<M>::index_to_reg_mmx>(); }
	void decode_Pd() { decode_Gx<&Instruction<M>::index_to_reg_mmx>(); }

	// Decode [S/C/D/T]Rx from ModRM reg
	void decode_Sw() { decode_Gx<&Instruction<M>::index_to_reg_seg>(); }
	void decode_Cd() { decode_Gx<&Instruction<M>::index_to_reg_cr>(); }
	void decode_Dd() { decode_Gx<&Instruction<M>::index_to_reg_dr>(); }
	void decode_Td() { decode_Gx<&Instruction<M>::index_to_reg_tr>(); }

	// Immediate
	void decode_Ib();
	void decode_Iw();
	void decode_Id();
	void decode_Iq();
	void decode_Iv();
	void decode_Iz() { if(prefix_ & PREFIX_OPERAND) { decode_Iw(); } else { decode_Id(); } }

	// EIP relative
	void decode_Jb();
	void decode_Jw();
	void decode_Jd();
	void decode_Jq();
	void decode_Jz() { if(prefix_ & PREFIX_OPERAND) { decode_Jw(); } else { decode_Jd(); } }

	// Direct offset
	void decode_Ob();
	void decode_Ow();
	void decode_Od();
	void decode_Ov();

	// Absolute address
	void decode_Ap();

	// Decode Specific Register
	void decode_eAX();
	void decode_rAX();
	void decode_rAX_NOREX();
	void decode_rCX();
	void decode_rDX();
	void decode_rBX();
	void decode_rSP();
	void decode_rBP();
	void decode_rSI();
	void decode_rDI();
	void decode_AL();
	void decode_CL();
	void decode_DL();
	void decode_BL();
	void decode_AH();
	void decode_CH();
	void decode_DH();
	void decode_BH();
	void decode_AX() { decode_Reg<operand_type::REG_AX>(); }
	void decode_DX() { decode_Reg<operand_type::REG_DX>(); }

	// simple wrappers around some of the these for cleaner tables
	void decode_SegCS()    { decode_Reg<operand_type::REG_CS>(); }
	void decode_SegDS()    { decode_Reg<operand_type::REG_DS>(); }
	void decode_SegES()    { decode_Reg<operand_type::REG_ES>(); }
	void decode_SegFS()    { decode_Reg<operand_type::REG_FS>(); }
	void decode_SegGS()    { decode_Reg<operand_type::REG_GS>(); }
	void decode_SegSS()    { decode_Reg<operand_type::REG_SS>(); }
	void decode_Ev_Gv_CL() { decode_Ev_Gv_Reg<operand_type::REG_CL>(); }

private:
	// 2 operand modes
	template <int index>
	void decode_ST_STi() { decode2<&instruction_type::template decode_Reg<operand_type::REG_ST>, &instruction_type::template decode_STi<index> >(); }

	template <int index>
	void decode_STi_ST() { decode2<&instruction_type::template decode_STi<index>, &instruction_type::template decode_Reg<operand_type::REG_ST> >(); }


	// macro for easier maintenance of these modes
	// only works for "simple" ones though (no template usage in params)
	#define DECODE2(op1, op2)                                                         \
	void decode_ ## op1 ## _ ## op2() {                             \
		decode2<&instruction_type::decode_ ## op1, &instruction_type::decode_ ## op2>(); \
	}

	DECODE2(Gq, Mo)
	DECODE2(Pd, Eq)
	DECODE2(Pd, Ed)
	DECODE2(Nq, Gq)
	DECODE2(Gq, Wo)
	DECODE2(Gd, Mo)
	DECODE2(Vo, Wd)
	DECODE2(Vo, Ww)
	DECODE2(Gq, Eb)
	DECODE2(Gq, Uo)
	DECODE2(Gq, Eq)
	DECODE2(Gd, Ev)
	DECODE2(Eq, Pd)
	DECODE2(Vd, Eq)
	DECODE2(Vq, Eq)
	DECODE2(Eq, Vo)
	DECODE2(Gq, Wd)
	DECODE2(Gq, Wq)
	DECODE2(Pq, Eq)
	DECODE2(Eq, Gq)
	DECODE2(Vo, Eq)
	DECODE2(Mv, Gv)
	DECODE2(Gv, Mv)
	DECODE2(Gd, Eb)
	DECODE2(Ev, Gv)
	DECODE2(Eb, Gb)
	DECODE2(Eb, Ib)
	DECODE2(Cd, Rd) // FIX
	DECODE2(Ed, Gd)
	DECODE2(Ed, Pd)
	DECODE2(Ed, Vo)
	DECODE2(Ev, Ib)
	DECODE2(Ev, Iz)
	DECODE2(Ev, Sw)
	DECODE2(Ew, Gw)
	DECODE2(Gb, Eb)
	DECODE2(Gd, Ed)
	DECODE2(Gd, Nq)
	DECODE2(Gd, Uo)
	DECODE2(Gd, Wd)
	DECODE2(Gd, Wq)
	DECODE2(Gv, Eb)
	DECODE2(Gv, Ev)
	DECODE2(Gv, Ew)
	DECODE2(Gv, M)
	DECODE2(Gv, Ma)
	DECODE2(Gv, Mp)
	DECODE2(Gz, Mp)
	DECODE2(Dd, Rd)
	DECODE2(Ib, rAX)
	DECODE2(Iw, Ib)
	DECODE2(Md, Gd)
	DECODE2(Mo, Vo)
	DECODE2(Mq, Pq)
	DECODE2(Mq, Vq)
	DECODE2(rAX, Ib)
	DECODE2(rAX, Iv)
	DECODE2(rAX, Iz)
	DECODE2(rAX, Ov)
	DECODE2(rBP, Iv)
	DECODE2(rBP, rAX)
	DECODE2(rBX, Iv)
	DECODE2(rBX, rAX)
	DECODE2(rCX, Iv)
	DECODE2(rCX, rAX)
	DECODE2(rDI, Iv)
	DECODE2(rDI, rAX)
	DECODE2(rDX, Iv)
	DECODE2(rDX, rAX)
	DECODE2(rAX, rAX)
	DECODE2(rSI, Iv)
	DECODE2(rSI, rAX)
	DECODE2(rSP, Iv)
	DECODE2(rSP, rAX)
	DECODE2(Ov, rAX)
	DECODE2(Nq, Ib)
	DECODE2(Pq, Ed)
	DECODE2(Pq, Nq)
	DECODE2(Pq, Qd)
	DECODE2(Pq, Qq)
	DECODE2(Pq, Uq)
	DECODE2(Pq, Wo)
	DECODE2(Pq, Wq)
	DECODE2(Qq, Pq)
	DECODE2(Rd, Cd) // FIX
	DECODE2(Rd, Dd)
	DECODE2(Sw, Ew)
	DECODE2(Uo, Ib)
	DECODE2(Vd, Ed)
	DECODE2(Vd, Wd)
	DECODE2(Vd, Wq)
	DECODE2(Vo, Ed)
	DECODE2(Vo, Mo)
	DECODE2(Vo, Mq)
	DECODE2(Vo, Nq)
	DECODE2(Vo, Qq)
	DECODE2(Vo, Uo)
	DECODE2(Vo, Wo)
	DECODE2(Gd, Wo)
	DECODE2(Vo, Wq)
	DECODE2(Vq, Ed)
	DECODE2(Vq, Mq)
	DECODE2(Vq, Wq)
	DECODE2(Wd, Vd)
	DECODE2(Wo, Vo)
	DECODE2(Wq, Vq)
	DECODE2(Qq, Wo)

	DECODE2(rCX, rAX_NOREX)
	DECODE2(rDX, rAX_NOREX)
	DECODE2(rBX, rAX_NOREX)
	DECODE2(rSP, rAX_NOREX)
	DECODE2(rBP, rAX_NOREX)
	DECODE2(rSI, rAX_NOREX)
	DECODE2(rDI, rAX_NOREX)
	DECODE2(eAX, Ib)
	DECODE2(Ib, eAX)
	DECODE2(eAX, DX)
	DECODE2(DX, eAX)

	DECODE2(Vo, Uo_Mq)
	DECODE2(Vo, Uo_Mw)
	DECODE2(Vo, Uo_Md)

	#undef DECODE2

	void decode_rAX_rAX_NOREX();

	void decode_AL_Ib() { decode2<&instruction_type::decode_AL, &instruction_type::decode_Ib>(); }
	void decode_CL_Ib() { decode2<&instruction_type::decode_CL, &instruction_type::decode_Ib>(); }
	void decode_DL_Ib() { decode2<&instruction_type::decode_DL, &instruction_type::decode_Ib>(); }
	void decode_BL_Ib() { decode2<&instruction_type::decode_BL, &instruction_type::decode_Ib>(); }
	void decode_AH_Ib() { decode2<&instruction_type::decode_AH, &instruction_type::decode_Ib>(); }
	void decode_CH_Ib() { decode2<&instruction_type::decode_CH, &instruction_type::decode_Ib>(); }
	void decode_DH_Ib() { decode2<&instruction_type::decode_DH, &instruction_type::decode_Ib>(); }
	void decode_BH_Ib() { decode2<&instruction_type::decode_BH, &instruction_type::decode_Ib>(); }

	void decode_AL_DX()  { decode2<&instruction_type::template decode_Reg<operand_type::REG_AL>, &instruction_type::template decode_Reg<operand_type::REG_DX> >(); }
	void decode_AL_Ob()  { decode2<&instruction_type::template decode_Reg<operand_type::REG_AL>, &instruction_type::decode_Ob>(); }
	void decode_DX_AL()  { decode2<&instruction_type::template decode_Reg<operand_type::REG_DX>, &instruction_type::template decode_Reg<operand_type::REG_AL> >(); }
	void decode_DX_rAX() { decode2<&instruction_type::template decode_Reg<operand_type::REG_DX>, &instruction_type::decode_rAX >(); }
	void decode_Eb_1()   { decode2<&instruction_type::decode_Eb, &instruction_type::template decode_const_Ib<1> >(); }
	void decode_Eb_CL()  { decode2<&instruction_type::decode_Eb, &instruction_type::template decode_Reg<operand_type::REG_CL> >(); }
	void decode_Ev_1()   { decode2<&instruction_type::decode_Ev, &instruction_type::template decode_const_Id<1> >(); }
	void decode_Ev_CL()  { decode2<&instruction_type::decode_Ev, &instruction_type::template decode_Reg<operand_type::REG_CL> >(); }
	void decode_Ib_AL()  { decode2<&instruction_type::decode_Ib, &instruction_type::template decode_Reg<operand_type::REG_AL> >(); }
	void decode_Ob_AL()  { decode2<&instruction_type::decode_Ob, &instruction_type::template decode_Reg<operand_type::REG_AL> >(); }
	void decode_rAX_DX() { decode2<&instruction_type::decode_rAX, &instruction_type::template decode_Reg<operand_type::REG_DX> >(); }


private:

	// macro for easier maintenance of these modes
	// only works for "simple" ones though (no template usage in params)
	#define DECODE3(op1, op2, op3)                                                                                    \
	void decode_ ## op1 ## _ ## op2 ## _ ## op3() {                                                 \
		decode3<&instruction_type::decode_ ## op1, &instruction_type::decode_ ## op2, &instruction_type::decode_ ## op3>(); \
	}

	// 3 operand modes
	DECODE3(Ed, Vo, Ib)
	DECODE3(Eq, Vo, Ib)
	DECODE3(Ev, Gv, Ib)
	DECODE3(Gd, Nq, Ib)
	DECODE3(Gd, Uo, Ib)
	DECODE3(Gv, Ev, Ib)
	DECODE3(Gv, Ev, Iz)
	DECODE3(Pq, Qq, Ib)
	DECODE3(Vo, Ed, Ib)
	DECODE3(Vo, Eq, Ib)
	DECODE3(Vo, Mb, Ib)
	DECODE3(Vo, Md, Ib)
	DECODE3(Vo, Wo, Ib)

	DECODE3(Ev, Vo, Ib)

	DECODE3(Pq, Rd_Mw, Ib)
	DECODE3(Pq, Rq_Mw, Ib)
	DECODE3(Vo, Rd_Mw, Ib)
	DECODE3(Vo, Rq_Mw, Ib)

	DECODE3(Md_Gd, Vo, Ib)
	DECODE3(Rd_Mb, Vo, Ib)
	DECODE3(Rd_Mw, Vo, Ib)
	DECODE3(Rq_Mw, Vo, Ib)
	#undef DECODE3

	template <typename operand_type::Register REG>
	void decode_Ev_Gv_Reg() { decode3<&instruction_type::decode_Ev, &instruction_type::decode_Gv, &instruction_type::template decode_Reg<REG> >(); }

private:
	static typename operand_type::Register index_to_reg_invalid(uint8_t)    { return operand_type::REG_INVALID; }
	static typename operand_type::Register index_to_reg_8(uint8_t index)    { return static_cast<typename operand_type::Register>(operand_type::REG_AL   + index); }
	static typename operand_type::Register index_to_reg_16(uint8_t index)   { return static_cast<typename operand_type::Register>(operand_type::REG_AX   + index); }
	static typename operand_type::Register index_to_reg_32(uint8_t index)   { return static_cast<typename operand_type::Register>(operand_type::REG_EAX  + index); }
	static typename operand_type::Register index_to_reg_64(uint8_t index)   { return static_cast<typename operand_type::Register>(operand_type::REG_RAX  + index); }
	static typename operand_type::Register index_to_reg_seg(uint8_t index)  { return static_cast<typename operand_type::Register>(operand_type::REG_ES   + index); }
	static typename operand_type::Register index_to_reg_mmx(uint8_t index)  { return static_cast<typename operand_type::Register>(operand_type::REG_MM0  + index); }
	static typename operand_type::Register index_to_reg_xmmx(uint8_t index) { return static_cast<typename operand_type::Register>(operand_type::REG_XMM0 + index); }
	static typename operand_type::Register index_to_reg_fpu(uint8_t index)  { return static_cast<typename operand_type::Register>(operand_type::REG_ST0  + index); }
	static typename operand_type::Register index_to_reg_cr(uint8_t index)   { return static_cast<typename operand_type::Register>(operand_type::REG_CR0  + index); }
	static typename operand_type::Register index_to_reg_dr(uint8_t index)   { return static_cast<typename operand_type::Register>(operand_type::REG_DR0  + index); }
	static typename operand_type::Register index_to_reg_tr(uint8_t index)   { return static_cast<typename operand_type::Register>(operand_type::REG_TR0  + index); }

public:
	unsigned int flags() const                        { return opcode_->flags; }
	Type type() const                                 { return opcode_->type; }
	address_type rva() const                          { return rva_; }
	bool valid() const                                { return type() != OP_INVALID; }
	const operand_type *operands() const              { return operands_; }
	const uint8_t *bytes() const                      { return bytes_; }
	operator void *() const                           { return reinterpret_cast<void *>(valid()); }
	std::string mnemonic() const                      { return opcode_->mnemonic; }
	uint32_t prefix() const                           { return prefix_; }
	uint32_t mandatory_prefix() const                 { return mandatory_prefix_; }
	unsigned int operand_count() const                { return operand_count_; }
	unsigned int prefix_size() const                  { return prefix_size_; }
	unsigned int size() const                         { return byte_index_; }

private:
	int operand_size() const;
	int address_size() const;

private:
	struct opcode_entry {
		const char  *mnemonic;
		decoder_t    decoder;
		Type         type;
		unsigned int flags;
	};

private:
	static const opcode_entry Opcodes_x87_Lo[64];
	static const opcode_entry Opcodes_x87_Hi[0x200];

	static const opcode_entry Opcodes[0x100];
	static const opcode_entry Opcodes_2Byte_NA[0x100];
	static const opcode_entry Opcodes_2Byte_66[0x100];
	static const opcode_entry Opcodes_2Byte_F2[0x100];
	static const opcode_entry Opcodes_2Byte_F3[0x100];
	static const opcode_entry Opcodes_3Byte_38_NA[0x100];
	static const opcode_entry Opcodes_3Byte_38_66[0x100];
	static const opcode_entry Opcodes_3Byte_38_F2[0x100];
	static const opcode_entry Opcodes_3Byte_3A_NA[0x100];
	static const opcode_entry Opcodes_3Byte_3A_66[0x100];

private:
	static const opcode_entry Opcodes_Group1[32];
	static const opcode_entry Opcodes_Group2[16];
	static const opcode_entry Opcodes_Group2D[32];
	static const opcode_entry Opcodes_Group3[16];
	static const opcode_entry Opcodes_Group4[8];
	static const opcode_entry Opcodes_Group5[8];
	static const opcode_entry Opcodes_Group6[8];
	static const opcode_entry Opcodes_Group7[8];
	static const opcode_entry Opcodes_Group7A[64];
	static const opcode_entry Opcodes_Group8[8];
	static const opcode_entry Opcodes_Group9[8];
	static const opcode_entry Opcodes_Group9_66[8];
	static const opcode_entry Opcodes_Group9_F3[8];
	static const opcode_entry Opcodes_Group10[8];
	static const opcode_entry Opcodes_Group11[8];
	static const opcode_entry Opcodes_Group12[16];
	static const opcode_entry Opcodes_Group13[8];
	static const opcode_entry Opcodes_Group13_66[8];
	static const opcode_entry Opcodes_Group14[8];
	static const opcode_entry Opcodes_Group14_66[8];
	static const opcode_entry Opcodes_Group15[8];
	static const opcode_entry Opcodes_Group15_66[8];
	static const opcode_entry Opcodes_Group16_Reg[8];
	static const opcode_entry Opcodes_Group16_Mem[8];
	static const opcode_entry Opcodes_Group17[64];

private:
	// other
	static const opcode_entry Opcodes_nop_pause_xchg[3];
	static const opcode_entry Opcodes_cbw_cwde_cdqe[3];
	static const opcode_entry Opcodes_cwd_cdq_cqo[3];
	static const opcode_entry Opcodes_stosw_stosd_stosq[3];
	static const opcode_entry Opcodes_lodsw_lodsd_lodsq[3];
	static const opcode_entry Opcodes_scasw_scasd_scasq[3];
	static const opcode_entry Opcodes_iretw_iret_iretq[3];
	static const opcode_entry Opcodes_movsw_movsd_movsq[3];
	static const opcode_entry Opcodes_popfw_popfd_popfq[3];
	static const opcode_entry Opcodes_pushfw_pushfd_pushfq[3];
	static const opcode_entry Opcodes_invalid_cmpxchg8b_cmpxchg16b[3];
	static const opcode_entry Opcodes_insw_insd_invalid[3];
	static const opcode_entry Opcodes_outsw_outsd_invalid[3];
	static const opcode_entry Opcodes_cmpsw_cmpsd_cmpsq[3];
	static const opcode_entry Opcodes_pushaw_pushad_invalid[3];
	static const opcode_entry Opcodes_popaw_popad_invalid[3];

private:
	static const opcode_entry Opcode_invalid;

private:
	stream_base        *byte_stream_;

	operand_type        operands_[MAX_OPERANDS];
	uint8_t             bytes_[MAX_SIZE];
	uint8_t             byte_index_;

	uint8_t             byte1_;
	uint8_t             byte2_;
	uint8_t             byte3_;
	uint8_t             modrm_byte_;
	uint8_t             sib_byte_;
	uint8_t             rex_byte_;

	address_type        rva_;
	const opcode_entry *opcode_;

	uint32_t            prefix_;
	uint32_t            mandatory_prefix_;
	uint8_t             operand_count_;

	uint8_t             modrm_size_;
	uint8_t             sib_size_;
	uint8_t             disp_size_;
	uint8_t             prefix_size_;
	uint8_t             immediate_size_;
	uint8_t             rex_size_;
};

#if __cplusplus >= 201103L
extern template class Instruction<x86>;
extern template class Instruction<x86_64>;
#endif

}

#include "edisassm_string.h"
#include "edisassm_ops.h"
#include "edisassm_functions.h"
#endif
