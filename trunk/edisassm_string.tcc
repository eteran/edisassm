/*
Copyright (C) 2006 - 2013 Evan Teran
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

#ifndef EDISASSM_STRING_20110816_TCC_
#define EDISASSM_STRING_20110816_TCC_

#include <algorithm>
#include <cassert>
#include <iomanip>
#include <limits>
#include <sstream>

namespace edisassm {

//------------------------------------------------------------------------------
// Name: register_name
// Desc: returns a string for a given register
//------------------------------------------------------------------------------
template <class M>
std::string register_name(typename operand<M>::Register reg, const lower_case&) {

	static const char *const names[] = {
		"",

		"rax",   "rcx",   "rdx",   "rbx",
		"rsp",   "rbp",   "rsi",   "rdi",
		"r8",    "r9",    "r10",   "r11",
		"r12",   "r13",   "r14",   "r15",

		"eax",   "ecx",   "edx",   "ebx",
		"esp",   "ebp",   "esi",   "edi",
		"r8d",   "r9d",   "r10d",  "r11d",
		"r12d",  "r13d",  "r14d",  "r15d",

		"ax",    "cx",    "dx",    "bx",
		"sp",    "bp",    "si",    "di",
		"r8w",   "r9w",   "r10w",  "r11w",
		"r12w",  "r13w",  "r14w",  "r15w",

		"al",    "cl",    "dl",    "bl",
		"ah",    "ch",    "dh",    "bh",
		"r8b",   "r9b",   "r10b",  "r11b",
		"r12b",  "r13b",  "r14b",  "r15b",
		"spl",   "bpl",   "sil",   "dil",

		"es",    "cs",    "ss",    "ds",
		"fs",    "gs",    "seg7",  "seg8",

		"cr0",   "cr1",   "cr2",   "cr3",
		"cr4",   "cr5",   "cr6",   "cr7",
		"cr8",   "cr9",   "cr10",  "cr11",
		"cr12",  "cr13",  "cr14",  "cr15",

		"dr0",   "dr1",   "dr2",   "dr3",
		"dr4",   "dr5",   "dr6",   "dr7",
		"dr8",   "dr9",   "dr10",  "dr11",
		"dr12",  "dr13",  "dr14",  "dr15",

		"tr0",   "tr1",   "tr2",   "tr3",
		"tr4",   "tr5",   "tr6",   "tr7",

		"mm0",   "mm1",   "mm2",   "mm3",
		"mm4",   "mm5",   "mm6",   "mm7",

		"xmm0",  "xmm1",  "xmm2",  "xmm3",
		"xmm4",  "xmm5",  "xmm6",  "xmm7",
		"xmm8",  "xmm9",  "xmm10", "xmm11",
		"xmm12", "xmm13", "xmm14", "xmm15",

		"st",
		"st(0)", "st(1)", "st(2)", "st(3)",
		"st(4)", "st(5)", "st(6)", "st(7)",

		"rip",
		"eip",

		"(invalid)"
	};

	assert(static_cast<size_t>(reg) < sizeof(names) / sizeof(names[0]));
	return names[reg];
}

//------------------------------------------------------------------------------
// Name: register_name
// Desc: returns a string for a given register
//------------------------------------------------------------------------------
template <class M>
std::string register_name(typename operand<M>::Register reg, const upper_case&) {

	static const char *const names[] = {
		"",

		"RAX",   "RCX",   "RDX",   "RBX",
		"RSP",   "RBP",   "RSI",   "RDI",
		"R8",    "R9",    "R10",   "R11",
		"R12",   "R13",   "R14",   "R15",

		"EAX",   "ECX",   "EDX",   "EBX",
		"ESP",   "EBP",   "ESI",   "EDI",
		"R8D",   "R9D",   "R10D",  "R11D",
		"R12D",  "R13D",  "R14D",  "R15D",

		"AX",    "CX",    "DX",    "BX",
		"SP",    "BP",    "SI",    "DI",
		"R8W",   "R9W",   "R10W",  "R11W",
		"R12W",  "R13W",  "R14W",  "R15W",

		"AL",    "CL",    "DL",    "BL",
		"AH",    "CH",    "DH",    "BH",
		"R8B",   "R9B",   "R10B",  "R11B",
		"R12B",  "R13B",  "R14B",  "R15B",
		"SPL",   "BPL",   "SIL",   "DIL",

		"ES",    "CS",    "SS",    "DS",
		"FS",    "GS",    "SEG7",  "SEG8",

		"CR0",   "CR1",   "CR2",   "CR3",
		"CR4",   "CR5",   "CR6",   "CR7",
		"CR8",   "CR9",   "CR10",  "CR11",
		"CR12",  "CR13",  "CR14",  "CR15",

		"DR0",   "DR1",   "DR2",   "DR3",
		"DR4",   "DR5",   "DR6",   "DR7",
		"DR8",   "DR9",   "DR10",  "DR11",
		"DR12",  "DR13",  "DR14",  "DR15",

		"TR0",   "TR1",   "TR2",   "TR3",
		"TR4",   "TR5",   "TR6",   "TR7",

		"MM0",   "MM1",   "MM2",   "MM3",
		"MM4",   "MM5",   "MM6",   "MM7",

		"XMM0",  "XMM1",  "XMM2",  "XMM3",
		"XMM4",  "XMM5",  "XMM6",  "XMM7",
		"XMM8",  "XMM9",  "XMM10", "XMM11",
		"XMM12", "XMM13", "XMM14", "XMM15",

		"ST",
		"ST(0)", "ST(1)", "ST(2)", "ST(3)",
		"ST(4)", "ST(5)", "ST(6)", "ST(7)",

		"RIP",
		"EIP",

		"(INVALID)"
	};

	assert(static_cast<size_t>(reg) < sizeof(names) / sizeof(names[0]));
	return names[reg];
}

//------------------------------------------------------------------------------
// Name: register_name
// Desc: returns a string for a given register
//------------------------------------------------------------------------------
template <class M>
std::string register_name(typename operand<M>::Register reg) {
	return register_name<M>(reg, lower_case());
}

namespace {

//------------------------------------------------------------------------------
// Name: is_small_num
//------------------------------------------------------------------------------
template <class T>
bool is_small_num(T value) {
	return (value > -127 && value < 128);
}

//------------------------------------------------------------------------------
// Name: toupper_copy
//------------------------------------------------------------------------------
inline std::string toupper_copy(std::string s) {
	std::transform(s.begin(), s.end(), s.begin(), std::ptr_fun<int, int>(std::toupper));
	return s;
}

//------------------------------------------------------------------------------
// Name: toupper
//------------------------------------------------------------------------------
inline std::string &toupper(std::string &s) {
	std::transform(s.begin(), s.end(), s.begin(), std::ptr_fun<int, int>(std::toupper));
	return s;
}

//------------------------------------------------------------------------------
// Name: tolower
//------------------------------------------------------------------------------
inline std::string &tolower(std::string &s) {
	std::transform(s.begin(), s.end(), s.begin(), std::ptr_fun<int, int>(std::tolower));
	return s;
}

//------------------------------------------------------------------------------
// Name: rtrim
//------------------------------------------------------------------------------
inline std::string &rtrim(std::string &s) {
	s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
	return s;
}

//------------------------------------------------------------------------------
// Name: ltrim
//------------------------------------------------------------------------------
inline std::string &ltrim(std::string &s) {
	s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
	return s;
}

//------------------------------------------------------------------------------
// Name: trim
//------------------------------------------------------------------------------
inline std::string &trim(std::string &s) {
	return ltrim(rtrim(s));
}

//------------------------------------------------------------------------------
// Name: hex_string
//------------------------------------------------------------------------------
template <class M, class T>
std::string hex_string(T value, const upper_case&) {
	if(value == 0) {
		return "0";
	}

	std::ostringstream ss;
	ss << "0x";
	ss << std::uppercase << std::hex << std::setw(sizeof(T) * 2) << std::setfill('0') << static_cast<typename M::address_type>(value);
	return ss.str();
}

//------------------------------------------------------------------------------
// Name: hex_string
//------------------------------------------------------------------------------
template <class M, class T>
std::string hex_string(T value, const lower_case&) {
	if(value == 0) {
		return "0";
	}

	std::ostringstream ss;
	ss << "0x";
	ss << std::hex << std::setw(sizeof(T) * 2) << std::setfill('0') << static_cast<typename M::address_type>(value);
	return ss.str();
}

//------------------------------------------------------------------------------
// Name: format_expression
//------------------------------------------------------------------------------
template <class M>
std::string format_expression(const operand<M> &op, const upper_case &) {

	typedef operand<M> O;
	typedef instruction<M> I;

	static const char *expression_strings[] = {
		"",
		"BYTE PTR ",
		"WORD PTR ",
		"DWORD PTR ",
		"FWORD PTR ",
		"QWORD PTR ",
		"TBYTE PTR ",
		"XMMWORD PTR ",
	};

	std::ostringstream ss;
	ss << expression_strings[op.complete_type() - O::TYPE_EXPRESSION];

	const uint32_t prefix = op.owner()->prefix();

	if(prefix & I::PREFIX_CS)      ss << "CS:";
	else if(prefix & I::PREFIX_SS) ss << "SS:";
	else if(prefix & I::PREFIX_DS) ss << "DS:";
	else if(prefix & I::PREFIX_ES) ss << "ES:";
	else if(prefix & I::PREFIX_FS) ss << "FS:";
	else if(prefix & I::PREFIX_GS) ss << "GS:";

	bool only_disp = true;

	ss << '[';

	// the base, if any
	if(op.expression().base != O::REG_NULL) {
		ss << register_name<M>(op.expression().base, upper_case());
		only_disp = false;
	}

	// the index, if any
	if(op.expression().index != O::REG_NULL) {
		if(!only_disp) {
			ss << '+';
		}
		ss << register_name<M>(op.expression().index, upper_case());
		only_disp = false;

		// the scale, if any
		if(op.expression().scale != 1) {
			ss << '*' << static_cast<int>(op.expression().scale);
		}
	}

	// the displacement, if any
	switch(op.expression().displacement_type) {
	case O::DISP_U32:
		if(op.expression().u_disp32 <= std::numeric_limits<uint16_t>::max()) {
			// this will lead to a fall through, we can print smaller
		} else {
			if(!only_disp) {
				ss << '+';
			}
			ss << hex_string<M>(op.expression().u_disp32, upper_case());
			break;
		}
		// FALL THROUGH
	case O::DISP_U16:
		if(op.expression().u_disp16 <= std::numeric_limits<uint8_t>::max()) {
			// this will lead to a fall through, we can print smaller
		} else {
			if(!only_disp) {
				ss << '+';
			}
			ss << hex_string<M>(op.expression().u_disp16, upper_case());
			break;
		}
		// FALL THROUGH
	case O::DISP_U8:
		if(op.expression().u_disp8 != 0 || only_disp) {
			if(!only_disp) {
				ss << '+';
			}
			ss << hex_string<M>(op.expression().u_disp8, upper_case());
		}
		break;

	case O::DISP_S32:
		if(op.expression().s_disp32 <= std::numeric_limits<int16_t>::max() && op.expression().s_disp32 >= std::numeric_limits<int16_t>::min()) {
			// this will lead to a fall through, we can print smaller
		} else {
			if(only_disp) {
				// we only have a displacement, so we wanna display in hex since it is likely an address
				ss << hex_string<M>(op.expression().s_disp32, upper_case());
			} else {
				ss << '+';
				ss << hex_string<M>(op.expression().s_disp32, upper_case());
			}
			break;
		}
		// FALL THROUGH
	case O::DISP_S16:
		if(op.expression().s_disp16 <= std::numeric_limits<int8_t>::max() && op.expression().s_disp16 >= std::numeric_limits<int8_t>::min()) {
			// this will lead to a fall through, we can print smaller
		} else {
			if(only_disp) {
				// we only have a displacement, so we wanna display in hex since it is likely an address
				ss << hex_string<M>(op.expression().s_disp16, upper_case());
			} else {
				ss << std::showpos << static_cast<int32_t>(op.expression().s_disp16);
			}
			break;
		}
		// FALL THROUGH
	case O::DISP_S8:
		if(op.expression().s_disp8 != 0 || only_disp) {
			if(only_disp) {
				// we only have a displacement, so we wanna display in hex since it is likely an address
				ss << hex_string<M>(op.expression().s_disp8, upper_case());
			} else {
				ss << std::showpos << static_cast<int32_t>(op.expression().s_disp8);
			}
		}
		break;

	default:
		break;
	}
	ss << ']';

	return ss.str();
}


//------------------------------------------------------------------------------
// Name: format_expression
//------------------------------------------------------------------------------
template <class M>
std::string format_expression(const operand<M> &op, const lower_case &) {

	typedef operand<M> O;
	typedef instruction<M> I;

	static const char *expression_strings[] = {
		"",
		"byte ptr ",
		"word ptr ",
		"dword ptr ",
		"fword ptr ",
		"qword ptr ",
		"tbyte ptr ",
		"xmmword ptr ",
	};

	std::ostringstream ss;
	ss << expression_strings[op.complete_type() - O::TYPE_EXPRESSION];

	const uint32_t prefix = op.owner()->prefix();

	if(prefix & I::PREFIX_CS)      ss << "cs:";
	else if(prefix & I::PREFIX_SS) ss << "ss:";
	else if(prefix & I::PREFIX_DS) ss << "ds:";
	else if(prefix & I::PREFIX_ES) ss << "es:";
	else if(prefix & I::PREFIX_FS) ss << "fs:";
	else if(prefix & I::PREFIX_GS) ss << "gs:";

	bool only_disp = true;

	ss << '[';

	// the base, if any
	if(op.expression().base != O::REG_NULL) {
		ss << register_name<M>(op.expression().base, lower_case());
		only_disp = false;
	}

	// the index, if any
	if(op.expression().index != O::REG_NULL) {
		if(!only_disp) {
			ss << '+';
		}
		ss << register_name<M>(op.expression().index, lower_case());
		only_disp = false;

		// the scale, if any
		if(op.expression().scale != 1) {
			ss << '*' << static_cast<int>(op.expression().scale);
		}
	}

	// the displacement, if any
	switch(op.expression().displacement_type) {
	case O::DISP_U32:
		if(op.expression().u_disp32 <= std::numeric_limits<uint16_t>::max()) {
			// this will lead to a fall through, we can print smaller
		} else {
			if(!only_disp) {
				ss << '+';
			}
			ss << hex_string<M>(op.expression().u_disp32, lower_case());
			break;
		}
		// FALL THROUGH
	case O::DISP_U16:
		if(op.expression().u_disp16 <= std::numeric_limits<uint8_t>::max()) {
			// this will lead to a fall through, we can print smaller
		} else {
			if(!only_disp) {
				ss << '+';
			}
			ss << hex_string<M>(op.expression().u_disp16, lower_case());
			break;
		}
		// FALL THROUGH
	case O::DISP_U8:
		if(op.expression().u_disp8 != 0 || only_disp) {
			if(!only_disp) {
				ss << '+';
			}
			ss << hex_string<M>(op.expression().u_disp8, lower_case());
		}
		break;

	case O::DISP_S32:
		if(op.expression().s_disp32 <= std::numeric_limits<int16_t>::max() && op.expression().s_disp32 >= std::numeric_limits<int16_t>::min()) {
			// this will lead to a fall through, we can print smaller
		} else {
			if(only_disp) {
				// we only have a displacement, so we wanna display in hex since it is likely an address
				ss << hex_string<M>(op.expression().s_disp32, lower_case());
			} else {
				ss << '+';
				ss << hex_string<M>(op.expression().s_disp32, lower_case());
			}
			break;
		}
		// FALL THROUGH
	case O::DISP_S16:
		if(op.expression().s_disp16 <= std::numeric_limits<int8_t>::max() && op.expression().s_disp16 >= std::numeric_limits<int8_t>::min()) {
			// this will lead to a fall through, we can print smaller
		} else {
			if(only_disp) {
				// we only have a displacement, so we wanna display in hex since it is likely an address
				ss << hex_string<M>(op.expression().s_disp16, lower_case());
			} else {
				ss << std::showpos << static_cast<int32_t>(op.expression().s_disp16);
			}
			break;
		}
		// FALL THROUGH
	case O::DISP_S8:
		if(op.expression().s_disp8 != 0 || only_disp) {
			if(only_disp) {
				// we only have a displacement, so we wanna display in hex since it is likely an address
				ss << hex_string<M>(op.expression().s_disp8, lower_case());
			} else {
				ss << std::showpos << static_cast<int32_t>(op.expression().s_disp8);
			}
		}
		break;

	default:
		break;
	}
	ss << ']';

	return ss.str();
}

//------------------------------------------------------------------------------
// Name: format_absolute
//------------------------------------------------------------------------------
template <class M>
std::string format_absolute(const operand<M> &op, const upper_case &) {
	std::ostringstream ss;

	ss << "FAR "
	   << hex_string<M>(op.absolute().seg, upper_case())
	   << ':'
	   << hex_string<M>(op.absolute().offset, upper_case());

	return ss.str();
}

//------------------------------------------------------------------------------
// Name: format_absolute
//------------------------------------------------------------------------------
template <class M>
std::string format_absolute(const operand<M> &op, const lower_case &) {
	std::ostringstream ss;

	ss << "far "
	   << hex_string<M>(op.absolute().seg, lower_case())
	   << ':'
	   << hex_string<M>(op.absolute().offset, lower_case());

	return ss.str();
}

//------------------------------------------------------------------------------
// Name: format_register
//------------------------------------------------------------------------------
template <class M>
std::string format_register(const operand<M> &op, const upper_case &) {
	return register_name<M>(op.reg(), upper_case());
}

//------------------------------------------------------------------------------
// Name: format_register
//------------------------------------------------------------------------------
template <class M>
std::string format_register(const operand<M> &op, const lower_case &) {
	return register_name<M>(op.reg(), lower_case());
}

//------------------------------------------------------------------------------
// Name: format_prefix
//------------------------------------------------------------------------------
template <class M>
std::string format_prefix(const instruction<M> &insn, const lower_case &) {

	typedef instruction<M> I;

	std::string ret;

	if((insn.prefix() & I::PREFIX_LOCK) && !(insn.mandatory_prefix() & I::PREFIX_LOCK)) {

		// TODO: this is only legal for the memory dest versions of:
		// ADD, ADC, AND, BTC, BTR, BTS, CMPXCHG, CMPXCH8B, (CMPXCH16B?)
		// DEC, INC, NEG, NOT, OR, SBB, SUB, XOR, XADD, XCHG

		ret = "lock ";

	} else if((insn.prefix() & I::PREFIX_REP) && !(insn.mandatory_prefix() & I::PREFIX_REP)) {
		if(insn.type() == I::OP_CMPS || insn.type() == I::OP_SCAS) {
			ret = "repe ";
		} else {

			// TODO: this is only legal for:
			// INS, OUTS, MOVS, LODS and STOS

			ret = "rep ";
		}
	} else if((insn.prefix() & I::PREFIX_REPNE) && !(insn.mandatory_prefix() & I::PREFIX_REPNE)) {
		// TODO: this is only legal for:
		// CMPS and SCAS
		ret = "repne ";
	}

	return ret;
}

//------------------------------------------------------------------------------
// Name: format_prefix
//------------------------------------------------------------------------------
template <class M>
std::string format_prefix(const instruction<M> &insn, const upper_case &) {

	typedef instruction<M> I;

	std::string ret;

	if((insn.prefix() & I::PREFIX_LOCK) && !(insn.mandatory_prefix() & I::PREFIX_LOCK)) {

		// TODO: this is only legal for the memory dest versions of:
		// ADD, ADC, AND, BTC, BTR, BTS, CMPXCHG, CMPXCH8B, (CMPXCH16B?)
		// DEC, INC, NEG, NOT, OR, SBB, SUB, XOR, XADD, XCHG

		ret = "LOCK ";

	} else if((insn.prefix() & I::PREFIX_REP) && !(insn.mandatory_prefix() & I::PREFIX_REP)) {
		if(insn.type() == I::OP_CMPS || insn.type() == I::OP_SCAS) {
			ret = "REPE ";
		} else {

			// TODO: this is only legal for:
			// INS, OUTS, MOVS, LODS and STOS

			ret = "REP ";
		}
	} else if((insn.prefix() & I::PREFIX_REPNE) && !(insn.mandatory_prefix() & I::PREFIX_REPNE)) {
		// TODO: this is only legal for:
		// CMPS and SCAS
		ret = "REPNE ";
	}

	return ret;
}

//------------------------------------------------------------------------------
// Name: format_relative
// Desc:
//------------------------------------------------------------------------------
template <class M>
std::string format_relative(const operand<M> &op, const upper_case &) {
	return hex_string<M>(static_cast<typename M::address_type>(op.relative_target()), upper_case());
}

//------------------------------------------------------------------------------
// Name: format_relative
// Desc:
//------------------------------------------------------------------------------
template <class M>
std::string format_relative(const operand<M> &op, const lower_case &) {
	return hex_string<M>(static_cast<typename M::address_type>(op.relative_target()), lower_case());
}

//------------------------------------------------------------------------------
// Name: format_immediate
//------------------------------------------------------------------------------
template <class M>
std::string format_immediate(const operand<M> &op, const upper_case &) {

	typedef operand<M> O;

	std::ostringstream ss;

	switch(op.complete_type()) {
	case O::TYPE_IMMEDIATE64:
		if(op.qword() < std::numeric_limits<uint32_t>::max()) {
			// this will lead to a fall through, we can print smaller
		} else {
			if(is_small_num(op.sqword())) {
				ss << op.sqword();
			} else {
				ss << hex_string<M>(op.sqword(), upper_case());
			}
			break;
		}
		// FALL THROUGH
	case O::TYPE_IMMEDIATE32:
		if(op.dword() < std::numeric_limits<uint16_t>::max()) {
			// this will lead to a fall through, we can print smaller
		} else {
			if(is_small_num(op.sdword())) {
				ss << op.sdword();
			} else {
				ss << hex_string<M>(op.sdword(), upper_case());
			}
			break;
		}
		// FALL THROUGH
	case O::TYPE_IMMEDIATE16:
		if(op.word() < std::numeric_limits<uint8_t>::max()) {
			// this will lead to a fall through, we can print smaller
		} else {
			if(is_small_num(op.sword())) {
				ss << op.sword();
			} else {
				ss << hex_string<M>(op.sword(), upper_case());
			}
			break;
		}
		// FALL THROUGH
	case O::TYPE_IMMEDIATE8:
		if(op.sbyte() & 0x80) {
			ss << hex_string<M>(op.byte(), upper_case());
		} else {
			ss << static_cast<int>(op.sbyte());
		}
		break;
	default:
		break;
	}

	return ss.str();
}

//------------------------------------------------------------------------------
// Name: format_immediate
//------------------------------------------------------------------------------
template <class M>
std::string format_immediate(const operand<M> &op, const lower_case &) {

	typedef operand<M> O;

	std::ostringstream ss;

	switch(op.complete_type()) {
	case O::TYPE_IMMEDIATE64:
		if(op.qword() < std::numeric_limits<uint32_t>::max()) {
			// this will lead to a fall through, we can print smaller
		} else {
			if(is_small_num(op.sqword())) {
				ss << op.sqword();
			} else {
				ss << hex_string<M>(op.sqword(), lower_case());
			}
			break;
		}
		// FALL THROUGH
	case O::TYPE_IMMEDIATE32:
		if(op.dword() < std::numeric_limits<uint16_t>::max()) {
			// this will lead to a fall through, we can print smaller
		} else {
			if(is_small_num(op.sdword())) {
				ss << op.sdword();
			} else {
				ss << hex_string<M>(op.sdword(), lower_case());
			}
			break;
		}
		// FALL THROUGH
	case O::TYPE_IMMEDIATE16:
		if(op.word() < std::numeric_limits<uint8_t>::max()) {
			// this will lead to a fall through, we can print smaller
		} else {
			if(is_small_num(op.sword())) {
				ss << op.sword();
			} else {
				ss << hex_string<M>(op.sword(), lower_case());
			}
			break;
		}
		// FALL THROUGH
	case O::TYPE_IMMEDIATE8:
		if(op.sbyte() & 0x80) {
			ss << hex_string<M>(op.byte(), lower_case());
		} else {
			ss << static_cast<int>(op.sbyte());
		}
		break;
	default:
		break;
	}

	return ss.str();
}

}

//------------------------------------------------------------------------------
// Name: to_string
// Desc: creates a std::string which represents the given instruction
//------------------------------------------------------------------------------
template <class M>
std::string to_string(const instruction<M> &insn, const syntax_intel &, const lower_case &) {
	std::ostringstream ss;

	ss << format_prefix(insn, lower_case());
	ss << insn.mnemonic();

	const std::size_t count = insn.operand_count();
	if(count != 0) {
		ss << ' ' << to_string(insn.operands()[0], syntax_intel());
		for(std::size_t i = 1; i < count; ++i) {
			ss << ", " << to_string(insn.operands()[i], syntax_intel());
		}
	}

	return ss.str();
}

//------------------------------------------------------------------------------
// Name: to_string
// Desc: creates a std::string which represents the given instruction
//------------------------------------------------------------------------------
template <class M>
std::string to_string(const instruction<M> &insn, const syntax_intel &, const upper_case &) {
	std::ostringstream ss;

	ss << format_prefix(insn, upper_case());
	ss << toupper_copy(insn.mnemonic());

	const std::size_t count = insn.operand_count();
	if(count != 0) {
		ss << ' ' << to_string(insn.operands()[0], syntax_intel());
		for(std::size_t i = 1; i < count; ++i) {
			ss << ", " << to_string(insn.operands()[i], syntax_intel());
		}
	}

	return ss.str();
}

//------------------------------------------------------------------------------
// Name: to_string
// Desc: creates a std::string which represents the given instruction
//------------------------------------------------------------------------------
template <class M>
std::string to_string(const instruction<M> &instruction, const syntax_intel &) {
	return to_string(instruction, syntax_intel(), lower_case());
}

//------------------------------------------------------------------------------
// Name: to_string
// Desc: creates a std::string which represents the given instruction
//------------------------------------------------------------------------------
template <class M>
std::string to_string(const instruction<M> &instruction) {
	return to_string(instruction, syntax_intel());
}

//------------------------------------------------------------------------------
// Name: to_string
// Desc: creates a std::string which represents the given operand
//------------------------------------------------------------------------------
template <class M>
std::string to_string(const operand<M> &op, const syntax_intel &, const lower_case &) {

	typedef operand<M> O;

	switch(op.general_type()) {
	case O::TYPE_ABSOLUTE:   return format_absolute(op, lower_case());
	case O::TYPE_EXPRESSION: return format_expression(op, lower_case());
	case O::TYPE_IMMEDIATE:  return format_immediate(op, lower_case());
	case O::TYPE_REGISTER:   return format_register(op, lower_case());
	case O::TYPE_REL:        return format_relative(op, lower_case());
	default:
		return register_name<M>(O::REG_INVALID, lower_case());
		// is it better to throw, or return a string?
		//throw invalid_operand(owner_->size());
	}
}

//------------------------------------------------------------------------------
// Name: to_string
// Desc: creates a std::string which represents the given operand
//------------------------------------------------------------------------------
template <class M>
std::string to_string(const operand<M> &op, const syntax_intel &, const upper_case &) {
	typedef operand<M> O;

	switch(op.general_type()) {
	case O::TYPE_ABSOLUTE:   return format_absolute(op, upper_case());
	case O::TYPE_EXPRESSION: return format_expression(op, upper_case());
	case O::TYPE_IMMEDIATE:  return format_immediate(op, upper_case());
	case O::TYPE_REGISTER:   return format_register(op, upper_case());
	case O::TYPE_REL:        return format_relative(op, upper_case());
	default:
		return register_name<M>(O::REG_INVALID, upper_case());
		// is it better to throw, or return a string?
		//throw invalid_operand(owner_->size());
	}
}

//------------------------------------------------------------------------------
// Name: to_string
// Desc: creates a std::string which represents the given operand
//------------------------------------------------------------------------------
template <class M>
std::string to_string(const operand<M> &op, const syntax_intel &) {
	return to_string(op, syntax_intel(), lower_case());
}

//------------------------------------------------------------------------------
// Name: to_string
// Desc: creates a std::string which represents the given operand
//------------------------------------------------------------------------------
template <class M>
std::string to_string(const operand<M> &op) {
	return to_string(op, syntax_intel());
}

//------------------------------------------------------------------------------
// Name: to_byte_string
// Desc:
//------------------------------------------------------------------------------
template <class M>
std::string to_byte_string(const instruction<M> &insn, const lower_case &) {
	std::ostringstream ss;

	const uint8_t *const ptr = insn.bytes();

	ss << std::hex << std::setw(2) << std::setfill('0') << static_cast<uint32_t>(ptr[0]);
	for(unsigned int i = 1; i < insn.size(); ++i) {
		ss << ' ' << std::hex << std::setw(2) << std::setfill('0') << static_cast<uint32_t>(ptr[i]);
	}
	return ss.str();
}

//------------------------------------------------------------------------------
// Name: to_byte_string
// Desc:
//------------------------------------------------------------------------------
template <class M>
std::string to_byte_string(const instruction<M> &insn, const upper_case &) {
	std::ostringstream ss;

	const uint8_t *const ptr = insn.bytes();
	const unsigned int size = insn.size();
	if(size != 0) {
		ss << std::hex << std::uppercase << std::setw(2) << std::setfill('0') << static_cast<uint32_t>(ptr[0]);
		for(unsigned int i = 1; i < size; ++i) {
			ss << ' ' << std::uppercase << std::hex << std::setw(2) << std::setfill('0') << static_cast<uint32_t>(ptr[i]);
		}
	}
	return ss.str();
}

//------------------------------------------------------------------------------
// Name: to_byte_string
// Desc:
//------------------------------------------------------------------------------
template <class M>
std::string to_byte_string(const instruction<M> &insn) {
	return to_byte_string(insn, lower_case());
}

}

#endif
