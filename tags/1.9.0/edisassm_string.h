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

#ifndef EDISASSM_STRING_20110422_H_
#define EDISASSM_STRING_20110422_H_

#include <string>

namespace edisassm {

template <class M>
class Instruction;

template <class M>
class Operand;

struct lower_case   {};
struct upper_case   {};
struct syntax_intel {};
struct syntax_att   {};

struct default_formatting {
	typedef lower_case   case_type;
	typedef syntax_intel syntax_type;
};

//------------------------------------------------------------------------------
// Name: to_string
// Desc: creates a std::string which represents the given inst
//------------------------------------------------------------------------------
template <class M, class F>
std::string to_string(const Instruction<M> &inst, const F &format);

//------------------------------------------------------------------------------
// Name: to_string
// Desc: creates a std::string which represents the given inst
//------------------------------------------------------------------------------
template <class M>
std::string to_string(const Instruction<M> &inst);

//------------------------------------------------------------------------------
// Name: to_string
// Desc: creates a std::string which represents the given operand
//------------------------------------------------------------------------------
template <class M, class F>
std::string to_string(const Operand<M> &op, const F &format);

//------------------------------------------------------------------------------
// Name: to_string
// Desc: creates a std::string which represents the given operand
//------------------------------------------------------------------------------
template <class M>
std::string to_string(const Operand<M> &op);

//------------------------------------------------------------------------------
// Name: to_byte_string
// Desc: 
//------------------------------------------------------------------------------
template <class M>
std::string to_byte_string(const Instruction<M> &inst, const lower_case &);

//------------------------------------------------------------------------------
// Name: to_byte_string
// Desc: 
//------------------------------------------------------------------------------
template <class M>
std::string to_byte_string(const Instruction<M> &inst, const upper_case &);

//------------------------------------------------------------------------------
// Name: to_byte_string
// Desc: 
//------------------------------------------------------------------------------
template <class M>
std::string to_byte_string(const Instruction<M> &inst);

//------------------------------------------------------------------------------
// Name: register_name
// Desc: returns a string for a given register
//------------------------------------------------------------------------------
template <class M>
std::string register_name(typename Operand<M>::Register reg, const upper_case&);

//------------------------------------------------------------------------------
// Name: register_name
// Desc: returns a string for a given register
//------------------------------------------------------------------------------
template <class M>
std::string register_name(typename Operand<M>::Register reg, const lower_case&);

//------------------------------------------------------------------------------
// Name: register_name
// Desc: returns a string for a given register
//------------------------------------------------------------------------------
template <class M>
std::string register_name(typename Operand<M>::Register reg);

}

#include "edisassm_string.tcc"
#endif
