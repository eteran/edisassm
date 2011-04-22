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

#ifndef OPERAND_20080421_TCC_
#define OPERAND_20080421_TCC_

#include "Instruction.h"
#include "edisassm_util.h"
#include <algorithm>
#include <cstring>
#include <functional>
#include <iomanip>
#include <limits>
#include <sstream>

//------------------------------------------------------------------------------
// Name: Operand()
//------------------------------------------------------------------------------
template <class M>
Operand<M>::Operand() : owner_(0), type_(TYPE_INVALID) {
	using std::memset;
	memset(&u, 0, sizeof(U));
}

//------------------------------------------------------------------------------
// Name: swap(Operand &other)
//------------------------------------------------------------------------------
template <class M>
void Operand<M>::swap(Operand &other) {
	using std::swap;

	swap(owner_, other.owner_);
	swap(type_, other.type_);
	swap(u, other.u);
}

//------------------------------------------------------------------------------
// Name: format_immediate(bool upper) const
//------------------------------------------------------------------------------
template <class M>
std::string Operand<M>::format_immediate(bool upper) const {
	std::ostringstream ss;

	switch(type_) {
	case TYPE_IMMEDIATE64:
		if(u.qword < std::numeric_limits<uint32_t>::max()) {
			// this will lead to a fall through, we can print smaller
		} else {
			if(edisassm::util::is_small_num(u.sqword)) {
				ss << u.sqword;
			} else {
				ss << hex_string(u.sqword, upper);
			}
			break;
		}
		// FALL THROUGH
	case TYPE_IMMEDIATE32:
		if(u.dword < std::numeric_limits<uint16_t>::max()) {
			// this will lead to a fall through, we can print smaller
		} else {
			if(edisassm::util::is_small_num(u.sdword)) {
				ss << u.sdword;
			} else {
				ss << hex_string(u.sdword, upper);
			}
			break;
		}
		// FALL THROUGH
	case TYPE_IMMEDIATE16:
		if(u.word < std::numeric_limits<uint8_t>::max()) {
			// this will lead to a fall through, we can print smaller
		} else {
			if(edisassm::util::is_small_num(u.sword)) {
				ss << u.sword;
			} else {
				ss << hex_string(u.sword, upper);
			}
			break;
		}
		// FALL THROUGH
	case TYPE_IMMEDIATE8:
		if(u.sbyte & 0x80) {
			ss << hex_string(u.byte, upper);
		} else {
			ss << static_cast<int>(u.sbyte);
		}
		break;
	default:
		break;
	}

	return ss.str();
}

//------------------------------------------------------------------------------
// Name: relative_target() const
//------------------------------------------------------------------------------
template <class M>
typename Operand<M>::address_t Operand<M>::relative_target() const {

	const address_t rva		= owner_->rva();
	const unsigned int size	= owner_->size();
	const address_t offset	= rva + size;

	switch(type_) {
	case TYPE_REL8:
		return static_cast<address_t>(u.sbyte + offset);
	case TYPE_REL16:
		// NOTE: intel truncates EIP to 16-bit here
		return static_cast<address_t>((u.sword + offset) & 0xffff);
	case TYPE_REL32:
		return static_cast<address_t>(u.sdword + offset);
	case TYPE_REL64:
		return static_cast<address_t>(u.sqword + offset);
	default:
		return 0;
	}
}

//------------------------------------------------------------------------------
// Name: format_relative(bool upper) const
//------------------------------------------------------------------------------
template <class M>
std::string Operand<M>::format_relative(bool upper) const {
	return hex_string(static_cast<address_t>(relative_target()), upper);
}

//------------------------------------------------------------------------------
// Name: format_expression(bool upper) const
//------------------------------------------------------------------------------
template <class M>
std::string Operand<M>::format_expression(bool upper) const {

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
	ss << edisassm::util::toupper_copy(expression_strings[type_ - TYPE_EXPRESSION], upper);

	const uint32_t prefix = owner_->prefix();

	if(prefix & instruction_t::PREFIX_CS) {
		ss << edisassm::util::toupper_copy("cs:", upper);
	} else if(prefix & instruction_t::PREFIX_SS) {
		ss << edisassm::util::toupper_copy("ss:", upper);
	} else if(prefix & instruction_t::PREFIX_DS) {
		ss << edisassm::util::toupper_copy("ds:", upper);
	} else if(prefix & instruction_t::PREFIX_ES) {
		ss << edisassm::util::toupper_copy("es:", upper);
	} else if(prefix & instruction_t::PREFIX_FS) {
		ss << edisassm::util::toupper_copy("fs:", upper);
	} else if(prefix & instruction_t::PREFIX_GS) {
		ss << edisassm::util::toupper_copy("gs:", upper);
	}

	bool only_disp = true;

	ss << '[';

	// the base, if any
	if(u.expression.base != REG_NULL) {
		ss << edisassm::util::toupper_copy(register_name(u.expression.base), upper);
		only_disp = false;
	}

	// the index, if any
	if(u.expression.index != REG_NULL) {
		if(!only_disp) {
			ss << '+';
		}
		ss << edisassm::util::toupper_copy(register_name(u.expression.index), upper);
		only_disp = false;

		// the scale, if any
		if(u.expression.scale != 1) {
			ss << '*' << static_cast<int>(u.expression.scale);
		}
	}

	// the displacement, if any
	switch(u.expression.displacement_type) {
	case DISP_U32:
		if(u.expression.u_disp32 <= std::numeric_limits<uint16_t>::max()) {
			// this will lead to a fall through, we can print smaller
		} else {
			if(!only_disp) {
				ss << '+';
			}
			ss << hex_string(u.expression.u_disp32, upper);
			break;
		}
		// FALL THROUGH
	case DISP_U16:
		if(u.expression.u_disp16 <= std::numeric_limits<uint8_t>::max()) {
			// this will lead to a fall through, we can print smaller
		} else {
			if(!only_disp) {
				ss << '+';
			}
			ss << hex_string(u.expression.u_disp16, upper);
			break;
		}
		// FALL THROUGH
	case DISP_U8:
		if(u.expression.u_disp8 != 0 || only_disp) {
			if(!only_disp) {
				ss << '+';
			}
			ss << hex_string(u.expression.u_disp8, upper);
		}
		break;

	case DISP_S32:
		if(u.expression.s_disp32 <= std::numeric_limits<int16_t>::max() && u.expression.s_disp32 >= std::numeric_limits<int16_t>::min()) {
			// this will lead to a fall through, we can print smaller
		} else {
			if(only_disp) {
				// we only have a displacement, so we wanna display in hex since it is likely an address
				ss << hex_string(u.expression.s_disp32, upper);
			} else {
				ss << '+';
				ss << hex_string(u.expression.s_disp32, upper);
			}
			break;
		}
		// FALL THROUGH
	case DISP_S16:
		if(u.expression.s_disp16 <= std::numeric_limits<int8_t>::max() && u.expression.s_disp16 >= std::numeric_limits<int8_t>::min()) {
			// this will lead to a fall through, we can print smaller
		} else {
			if(only_disp) {
				// we only have a displacement, so we wanna display in hex since it is likely an address
				ss << hex_string(u.expression.s_disp16, upper);
			} else {
				ss << std::showpos << static_cast<int32_t>(u.expression.s_disp16);
			}
			break;
		}
		// FALL THROUGH
	case DISP_S8:
		if(u.expression.s_disp8 != 0 || only_disp) {
			if(only_disp) {
				// we only have a displacement, so we wanna display in hex since it is likely an address
				ss << hex_string(u.expression.s_disp8, upper);
			} else {
				ss << std::showpos << static_cast<int32_t>(u.expression.s_disp8);
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
// Name: format_absolute() const
//------------------------------------------------------------------------------
template <class M>
std::string Operand<M>::format_absolute(bool upper) const {
	std::ostringstream ss;

	ss	<< edisassm::util::toupper_copy("far ", upper)
		<< hex_string(u.absolute.seg, upper)
		<< ':'
		<< hex_string(u.absolute.offset, upper);

	return ss.str();
}

//------------------------------------------------------------------------------
// Name: format_register(bool upper) const
//------------------------------------------------------------------------------
template <class M>
std::string Operand<M>::format_register(bool upper) const {
	std::string ret = register_name(u.reg);
	if(upper) {
		return edisassm::util::toupper(ret);
	}

	return ret;

}

//------------------------------------------------------------------------------
// Name: displacement() const
//------------------------------------------------------------------------------
template <class M>
int32_t Operand<M>::displacement() const {

	switch(u.expression.displacement_type) {
	case DISP_U8:  return static_cast<int32_t>(u.expression.u_disp8);
	case DISP_U16: return static_cast<int32_t>(u.expression.u_disp16);
	case DISP_U32: return static_cast<int32_t>(u.expression.u_disp32);
	case DISP_S8:  return static_cast<int32_t>(u.expression.s_disp8);
	case DISP_S16: return static_cast<int32_t>(u.expression.s_disp16);
	case DISP_S32: return static_cast<int32_t>(u.expression.s_disp32);
	default:
		return 0;
	}
}

//------------------------------------------------------------------------------
// Name: immediate() const
//------------------------------------------------------------------------------
template <class M>
int64_t Operand<M>::immediate() const {

	switch(type_) {
	case TYPE_IMMEDIATE8:  return static_cast<int64_t>(u.sbyte);
	case TYPE_IMMEDIATE16: return static_cast<int64_t>(u.sword);
	case TYPE_IMMEDIATE32: return static_cast<int64_t>(u.sdword);
	case TYPE_IMMEDIATE64: return static_cast<int64_t>(u.sqword);
	default:
		return 0;
	}
}

//------------------------------------------------------------------------------
// Name: general_type() const
//------------------------------------------------------------------------------
template <class M>
typename Operand<M>::Type Operand<M>::general_type() const {
	return static_cast<Type>(static_cast<unsigned int>(type_) & TYPE_MASK);
}

//------------------------------------------------------------------------------
// Name: hex_string(T value, bool upper)
//------------------------------------------------------------------------------
template <class M>
template <class T>
std::string Operand<M>::hex_string(T value, bool upper) {

	if(value == 0) {
		return "0";
	}

	std::ostringstream ss;
	ss << "0x";
	if(upper) {
		ss << std::uppercase;
	}
	ss << std::hex << std::setw(sizeof(T) * 2) << std::setfill('0') << static_cast<address_t>(value);
	return ss.str();
}

//------------------------------------------------------------------------------
// Name: hex_string(T value, bool upper)
//------------------------------------------------------------------------------
template <class M>
std::string Operand<M>::register_name(Register reg) {

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

	return names[reg];
}

#endif
