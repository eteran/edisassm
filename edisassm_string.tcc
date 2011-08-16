/*
Copyright (C) 2006 - 2011 Evan Teran
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

#include <cassert>
#include <iomanip>
#include <limits>
#include <sstream>
#include "edisassm_util.h"

namespace edisassm {
namespace {

//------------------------------------------------------------------------------
// Name: hex_string(T value, bool upper)
// Desc: returns a hexstring of a value, optionally in upper case
//------------------------------------------------------------------------------
template <class M, class T>
std::string hex_string(T value, bool upper) {

	if(value == 0) {
		return "0";
	}

	std::ostringstream ss;
	ss << "0x";
	if(upper) {
		ss << std::uppercase;
	}
	ss << std::hex << std::setw(sizeof(T) * 2) << std::setfill('0') << static_cast<typename M::address_t>(value);
	return ss.str();
}

//------------------------------------------------------------------------------
// Name: format_register(const Operand<M> &operand, bool upper)
// Desc: returns a register type operand as a string
//------------------------------------------------------------------------------
template <class M>
std::string format_register(const Operand<M> &operand, bool upper) {
	std::string ret = register_name<M>(operand.reg());
	if(upper) {
		return util::toupper(ret);
	}

	return ret;

}

//------------------------------------------------------------------------------
// Name: format_prefix(const Instruction<M> &insn)
//------------------------------------------------------------------------------
template <class M>
std::string format_prefix(const Instruction<M> &insn) {
	std::string ret;

	if((insn.prefix() & Instruction<M>::PREFIX_LOCK) && !(insn.mandatory_prefix() & Instruction<M>::PREFIX_LOCK)) {
		// TODO: this is only legal for the memory dest versions of:
		// ADD, ADC, AND, BTC, BTR, BTS, CMPXCHG, CMPXCH8B, (CMPXCH16B?)
		// DEC, INC, NEG, NOT, OR, SBB, SUB, XOR, XADD, XCHG
		ret = "lock ";

	} else if((insn.prefix() & Instruction<M>::PREFIX_REP) && !(insn.mandatory_prefix() & Instruction<M>::PREFIX_REP)) {
		if(insn.type() == Instruction<M>::OP_CMPS || insn.type() == Instruction<M>::OP_SCAS) {
			ret = "repe ";
		} else {
			// TODO: this is only legal for:
			// INS, OUTS, MOVS, LODS and STOS
			ret = "rep ";
		}
	} else if((insn.prefix() & Instruction<M>::PREFIX_REPNE) && !(insn.mandatory_prefix() & Instruction<M>::PREFIX_REPNE)) {
		// TODO: this is only legal for:
		// CMPS and SCAS
		ret = "repne ";
	}

	return ret;
}

//------------------------------------------------------------------------------
// Name: 
// Desc: 
//------------------------------------------------------------------------------
template <class M>
std::string format_absolute(const Operand<M> &operand, bool upper) {
	std::ostringstream ss;

	ss << util::toupper_copy("far ", upper)
		<< hex_string<M>(operand.absolute().seg, upper)
		<< ':'
		<< hex_string<M>(operand.absolute().offset, upper);

	return ss.str();
}

//------------------------------------------------------------------------------
// Name: 
// Desc: 
//------------------------------------------------------------------------------
template <class M>
std::string format_relative(const Operand<M> &operand, bool upper) {
	return hex_string<M>(static_cast<typename M::address_t>(operand.relative_target()), upper);
}

//------------------------------------------------------------------------------
// Name: 
// Desc: 
//------------------------------------------------------------------------------
template <class M>
std::string format_immediate(const Operand<M> &operand, bool upper) {
	std::ostringstream ss;

	switch(operand.complete_type()) {
	case Operand<M>::TYPE_IMMEDIATE64:
		if(operand.qword() < std::numeric_limits<uint32_t>::max()) {
			// this will lead to a fall through, we can print smaller
		} else {
			if(util::is_small_num(operand.sqword())) {
				ss << operand.sqword();
			} else {
				ss << hex_string<M>(operand.sqword(), upper);
			}
			break;
		}
		// FALL THROUGH
	case Operand<M>::TYPE_IMMEDIATE32:
		if(operand.dword() < std::numeric_limits<uint16_t>::max()) {
			// this will lead to a fall through, we can print smaller
		} else {
			if(util::is_small_num(operand.sdword())) {
				ss << operand.sdword();
			} else {
				ss << hex_string<M>(operand.sdword(), upper);
			}
			break;
		}
		// FALL THROUGH
	case Operand<M>::TYPE_IMMEDIATE16:
		if(operand.word() < std::numeric_limits<uint8_t>::max()) {
			// this will lead to a fall through, we can print smaller
		} else {
			if(util::is_small_num(operand.sword())) {
				ss << operand.sword();
			} else {
				ss << hex_string<M>(operand.sword(), upper);
			}
			break;
		}
		// FALL THROUGH
	case Operand<M>::TYPE_IMMEDIATE8:
		if(operand.sbyte() & 0x80) {
			ss << hex_string<M>(operand.byte(), upper);
		} else {
			ss << static_cast<int>(operand.sbyte());
		}
		break;
	default:
		break;
	}

	return ss.str();
}

//------------------------------------------------------------------------------
// Name: 
// Desc: 
//------------------------------------------------------------------------------
template <class M>
std::string format_expression(const Operand<M> &operand, bool upper) {

	typedef Instruction<M> instruction_t;

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
	ss << util::toupper_copy(expression_strings[operand.general_type() - Operand<M>::TYPE_EXPRESSION], upper);

	const uint32_t prefix = operand.owner()->prefix();

	if(prefix & instruction_t::PREFIX_CS)      ss << util::toupper_copy("cs:", upper);
	else if(prefix & instruction_t::PREFIX_SS) ss << util::toupper_copy("ss:", upper);
	else if(prefix & instruction_t::PREFIX_DS) ss << util::toupper_copy("ds:", upper);
	else if(prefix & instruction_t::PREFIX_ES) ss << util::toupper_copy("es:", upper);
	else if(prefix & instruction_t::PREFIX_FS) ss << util::toupper_copy("fs:", upper);
	else if(prefix & instruction_t::PREFIX_GS) ss << util::toupper_copy("gs:", upper);
	

	bool only_disp = true;

	ss << '[';

	// the base, if any
	if(operand.expression().base != Operand<M>::REG_NULL) {
		ss << util::toupper_copy(register_name<M>(operand.expression().base), upper);
		only_disp = false;
	}

	// the index, if any
	if(operand.expression().index != Operand<M>::REG_NULL) {
		if(!only_disp) {
			ss << '+';
		}
		ss << util::toupper_copy(register_name<M>(operand.expression().index), upper);
		only_disp = false;

		// the scale, if any
		if(operand.expression().scale != 1) {
			ss << '*' << static_cast<int>(operand.expression().scale);
		}
	}

	// the displacement, if any
	switch(operand.expression().displacement_type) {
	case Operand<M>::DISP_U32:
		if(operand.expression().u_disp32 <= std::numeric_limits<uint16_t>::max()) {
			// this will lead to a fall through, we can print smaller
		} else {
			if(!only_disp) {
				ss << '+';
			}
			ss << hex_string<M>(operand.expression().u_disp32, upper);
			break;
		}
		// FALL THROUGH
	case Operand<M>::DISP_U16:
		if(operand.expression().u_disp16 <= std::numeric_limits<uint8_t>::max()) {
			// this will lead to a fall through, we can print smaller
		} else {
			if(!only_disp) {
				ss << '+';
			}
			ss << hex_string<M>(operand.expression().u_disp16, upper);
			break;
		}
		// FALL THROUGH
	case Operand<M>::DISP_U8:
		if(operand.expression().u_disp8 != 0 || only_disp) {
			if(!only_disp) {
				ss << '+';
			}
			ss << hex_string<M>(operand.expression().u_disp8, upper);
		}
		break;

	case Operand<M>::DISP_S32:
		if(operand.expression().s_disp32 <= std::numeric_limits<int16_t>::max() && operand.expression().s_disp32 >= std::numeric_limits<int16_t>::min()) {
			// this will lead to a fall through, we can print smaller
		} else {
			if(only_disp) {
				// we only have a displacement, so we wanna display in hex since it is likely an address
				ss << hex_string<M>(operand.expression().s_disp32, upper);
			} else {
				ss << '+';
				ss << hex_string<M>(operand.expression().s_disp32, upper);
			}
			break;
		}
		// FALL THROUGH
	case Operand<M>::DISP_S16:
		if(operand.expression().s_disp16 <= std::numeric_limits<int8_t>::max() && operand.expression().s_disp16 >= std::numeric_limits<int8_t>::min()) {
			// this will lead to a fall through, we can print smaller
		} else {
			if(only_disp) {
				// we only have a displacement, so we wanna display in hex since it is likely an address
				ss << hex_string<M>(operand.expression().s_disp16, upper);
			} else {
				ss << std::showpos << static_cast<int32_t>(operand.expression().s_disp16);
			}
			break;
		}
		// FALL THROUGH
	case Operand<M>::DISP_S8:
		if(operand.expression().s_disp8 != 0 || only_disp) {
			if(only_disp) {
				// we only have a displacement, so we wanna display in hex since it is likely an address
				ss << hex_string<M>(operand.expression().s_disp8, upper);
			} else {
				ss << std::showpos << static_cast<int32_t>(operand.expression().s_disp8);
			}
		}
		break;

	default:
		break;
	}
	ss << ']';

	return ss.str();
}
}

//------------------------------------------------------------------------------
// Name: register_name(typename Operand<M>::Register reg)
// Desc: returns a string for a given register
//------------------------------------------------------------------------------
template <class M>
std::string register_name(typename Operand<M>::Register reg) {

	static const char *names[] = {
		"",

		"rax",	"rcx",	"rdx",	"rbx",
		"rsp",	"rbp",	"rsi",	"rdi",
		"r8",	"r9",	"r10",	"r11",
		"r12",	"r13",	"r14",	"r15",

		"eax",	"ecx",	"edx",	"ebx",
		"esp",	"ebp",	"esi",	"edi",
		"r8d",	"r9d",	"r10d",	"r11d",
		"r12d",	"r13d",	"r14d",	"r15d",

		"ax",	"cx",	"dx",	"bx",
		"sp",	"bp",	"si",	"di",
		"r8w",	"r9w",	"r10w",	"r11w",
		"r12w",	"r13w",	"r14w",	"r15w",

		"al",	"cl",	"dl",	"bl",
		"ah",	"ch",	"dh",	"bh",
		"r8b",	"r9b",	"r10b",	"r11b",
		"r12b",	"r13b",	"r14b",	"r15b",
		"spl",	"bpl",	"sil",	"dil",

		"es",	"cs",	"ss",	"ds",
		"fs",	"gs",	"seg7",	"seg8",

		"cr0",	"cr1",	"cr2",	"cr3",
		"cr4",	"cr5",	"cr6",	"cr7",
		"cr8",	"cr9",	"cr10",	"cr11",
		"cr12",	"cr13",	"cr14",	"cr15",

		"dr0",	"dr1",	"dr2",	"dr3",
		"dr4",	"dr5",	"dr6",	"dr7",
		"dr8",	"dr9",	"dr10",	"dr11",
		"dr12",	"dr13",	"dr14",	"dr15",

		"tr0",	"tr1",	"tr2",	"tr3",
		"tr4",	"tr5",	"tr6",	"tr7",

		"mm0",	"mm1",	"mm2",	"mm3",
		"mm4",	"mm5",	"mm6",	"mm7",

		"xmm0",	"xmm1",	"xmm2",	"xmm3",
		"xmm4",	"xmm5",	"xmm6",	"xmm7",
		"xmm8",	"xmm9",	"xmm10","xmm11",
		"xmm12","xmm13","xmm14","xmm15",

		"st",
		"st(0)", "st(1)", "st(2)", "st(3)",
		"st(4)", "st(5)", "st(6)", "st(7)",

		"rip",
		"eip",

		"(invalid)"
	};

	assert(reg < sizeof(names) / sizeof(names[0]));
	return names[reg];
}

//------------------------------------------------------------------------------
// Name: 
// Desc: 
//------------------------------------------------------------------------------
template<class M>
std::string to_string(const Operand<M> &operand, const syntax_intel &syntax) {
	return to_string(operand, false, syntax);
}

//------------------------------------------------------------------------------
// Name: 
// Desc: 
//------------------------------------------------------------------------------
template <class M>
std::string to_string(const Instruction<M> &insn, const syntax_intel &) {
	std::ostringstream ss;

	ss << format_prefix(insn);
	ss << insn.mnemonic();

	const std::size_t count = insn.operand_count();
	if(count != 0) {
		ss << ' ' << to_string(insn.operand(0));
		for(std::size_t i = 1; i < count; ++i) {
			ss << ", " << to_string(insn.operand(i));
		}
	}

	return ss.str();
}

//------------------------------------------------------------------------------
// Name: 
// Desc: 
//------------------------------------------------------------------------------
template<class M>
std::string to_string(const Operand<M> &operand, bool upper, const syntax_intel &) {

	switch(operand.general_type()) {
	case Operand<M>::TYPE_ABSOLUTE:   return format_absolute(operand, upper);
	case Operand<M>::TYPE_EXPRESSION: return format_expression(operand, upper);
	case Operand<M>::TYPE_IMMEDIATE:  return format_immediate(operand, upper);
	case Operand<M>::TYPE_REGISTER:   return format_register(operand, upper);
	case Operand<M>::TYPE_REL:        return format_relative(operand, upper);
	default:
		return upper ? "(INVALID)" : "(invalid)";
		// is it better to throw, or return a string?
		//throw invalid_operand(owner_->size());
	}
}

//------------------------------------------------------------------------------
// Name: 
// Desc: 
//------------------------------------------------------------------------------
template <class M>
std::string to_string(const Instruction<M> &insn, bool upper, const syntax_intel &) {
	std::ostringstream ss;

	if(upper) {
		ss << util::toupper_copy(format_prefix(insn));
		ss << util::toupper_copy(insn.mnemonic());
	} else {
		ss << format_prefix(insn);
		ss << insn.mnemonic();
	}

	const std::size_t count = insn.operand_count();
	if(count != 0) {
		ss << ' ' << to_string(insn.operand(0), upper);
		for(std::size_t i = 1; i < count; ++i) {
			ss << ", " << to_string(insn.operand(i), upper);
		}
	}

	return ss.str();
}

//------------------------------------------------------------------------------
// Name: to_byte_string(const Instruction<M> &insn, bool upper)
// Desc: creates a std::string which represents the given instruction
//------------------------------------------------------------------------------
template <class M>
std::string to_byte_string(const Instruction<M> &insn, bool upper) {

	if(upper) {
		std::ostringstream ss;

		const uint8_t *const ptr = insn.buffer();
		ss << std::hex << std::uppercase << std::setw(2) << std::setfill('0') << static_cast<uint32_t>(ptr[0]);
		for(unsigned int i = 1; i < insn.size(); ++i) {
			ss << ' ' << std::uppercase << std::hex << std::setw(2) << std::setfill('0') << static_cast<uint32_t>(ptr[i]);
		}
		return ss.str();
	} else {
	
	}	return to_byte_string(insn);
	
}

//------------------------------------------------------------------------------
// Name: to_byte_string(const Instruction<M> &insn)
// Desc: creates a std::string which represents the given instruction
//------------------------------------------------------------------------------
template <class M>
std::string to_byte_string(const Instruction<M> &insn) {
	std::ostringstream ss;
	
	const uint8_t *const ptr = insn.buffer();
	
	ss << std::hex << std::setw(2) << std::setfill('0') << static_cast<uint32_t>(ptr[0]);
	for(unsigned int i = 1; i < insn.size(); ++i) {
		ss << ' ' << std::hex << std::setw(2) << std::setfill('0') << static_cast<uint32_t>(ptr[i]);
	}
	return ss.str();
}

}

#endif
