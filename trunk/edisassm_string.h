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

#ifndef EDISASSM_STRING_20110422_H_
#define EDISASSM_STRING_20110422_H_

#include <string>
#include <sstream>

template <class M>
class Instruction;

template <class M>
class Operand;

namespace edisassm {


//------------------------------------------------------------------------------
// Name: to_string(const Operand<M> &operand)
// Desc: creates a std::string which represents the given operand
//------------------------------------------------------------------------------
template<class M>
std::string to_string(const Operand<M> &operand) {
	return to_string(operand, false);
}

//------------------------------------------------------------------------------
// Name: to_string(const Operand<M> &operand, bool upper)
// Desc: creates a std::string which represents the given operand
//------------------------------------------------------------------------------
template<class M>
std::string to_string(const Operand<M> &operand, bool upper) {

	switch(operand.general_type()) {
	case Operand<M>::TYPE_REGISTER:   return operand.format_register(upper);
	case Operand<M>::TYPE_IMMEDIATE:  return operand.format_immediate(upper);
	case Operand<M>::TYPE_REL:        return operand.format_relative(upper);
	case Operand<M>::TYPE_EXPRESSION: return operand.format_expression(upper);
	case Operand<M>::TYPE_ABSOLUTE:   return operand.format_absolute(upper);
	default:
		return upper ? "(INVALID)" : "(invalid)";
		// is it better to throw, or return a string?
		//throw invalid_operand(owner_->size());
	}
}

//------------------------------------------------------------------------------
// Name: to_string(const Instruction<M> &insn, bool upper = false)
// Desc: creates a std::string which represents the given instruction
//------------------------------------------------------------------------------
template <class M>
std::string to_string(const Instruction<M> &insn, bool upper = false) {
	std::ostringstream ss;

	if(upper) {
		ss << edisassm::util::toupper_copy(insn.format_prefix());
		ss << edisassm::util::toupper_copy(insn.mnemonic());
	} else {
		ss << insn.format_prefix();
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

}

#endif
