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

template <class M>
class Instruction;

template <class M>
class Operand;

namespace edisassm {

	struct syntax_intel {};
	//struct syntax_att   {};
	
	//------------------------------------------------------------------------------
	// Name: to_string(const Instruction<M> &insn, bool upper, const syntax_intel &)
	// Desc: creates a std::string which represents the given instruction
	//------------------------------------------------------------------------------
	template <class M>
	std::string to_string(const Instruction<M> &insn, bool upper, const syntax_intel &);
	
	//------------------------------------------------------------------------------
	// Name: to_string(const Operand<M> &operand, bool upper, const syntax_intel &)
	// Desc: creates a std::string which represents the given operand
	//------------------------------------------------------------------------------
	template<class M>
	std::string to_string(const Operand<M> &operand, bool upper, const syntax_intel &);

	//------------------------------------------------------------------------------
	// Name: to_string(const Instruction<M> &insn, const syntax_intel &)
	// Desc: creates a std::string which represents the given instruction
	//------------------------------------------------------------------------------
	template <class M>
	std::string to_string(const Instruction<M> &insn, const syntax_intel &);

	//------------------------------------------------------------------------------
	// Name: to_string(const Operand<M> &operand, const syntax_intel &)
	// Desc: creates a std::string which represents the given operand
	//------------------------------------------------------------------------------
	template<class M>
	std::string to_string(const Operand<M> &operand, const syntax_intel &);
	
	//------------------------------------------------------------------------------
	// Name: to_string(const Instruction<M> &insn)
	// Desc: creates a std::string which represents the given instruction
	//------------------------------------------------------------------------------
	template <class M>
	std::string to_string(const Instruction<M> &insn) {
		return to_string(insn, syntax_intel());
	}

	//------------------------------------------------------------------------------
	// Name: to_string(const Operand<M> &operand)
	// Desc: creates a std::string which represents the given operand
	//------------------------------------------------------------------------------
	template<class M>
	std::string to_string(const Operand<M> &operand) {
		return to_string(operand, syntax_intel());
	}
	
	//------------------------------------------------------------------------------
	// Name: to_string(const Instruction<M> &insn, bool upper)
	// Desc: creates a std::string which represents the given instruction
	//------------------------------------------------------------------------------
	template <class M>
	std::string to_string(const Instruction<M> &insn, bool upper) {
		return to_string(insn, upper, syntax_intel());
	}

	//------------------------------------------------------------------------------
	// Name: to_string(const Operand<M> &operand, bool upper)
	// Desc: creates a std::string which represents the given operand
	//------------------------------------------------------------------------------
	template<class M>
	std::string to_string(const Operand<M> &operand, bool upper) {
		return to_string(operand, upper, syntax_intel());
	}
	
	//------------------------------------------------------------------------------
	// Name: to_byte_string(const Instruction<M> &insn, bool upper)
	// Desc: creates a std::string which represents the given instruction
	//------------------------------------------------------------------------------
	template <class M>
	std::string to_byte_string(const Instruction<M> &insn, bool upper);
	
	//------------------------------------------------------------------------------
	// Name: to_byte_string(const Instruction<M> &insn)
	// Desc: creates a std::string which represents the given instruction
	//------------------------------------------------------------------------------
	template <class M>
	std::string to_byte_string(const Instruction<M> &insn);
}

#include "edisassm_string.tcc"
#endif
