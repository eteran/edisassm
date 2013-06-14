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

#ifndef EDISASSM_STRING_20110422_H_
#define EDISASSM_STRING_20110422_H_

#include <string>


namespace edisassm {

template <class M>
class instruction;

template <class M>
class operand;

struct lower_case   {};
struct upper_case   {};
struct syntax_intel {};
struct syntax_att   {};

//------------------------------------------------------------------------------
// Name: to_string
// Desc: creates a std::string which represents the given instruction
//------------------------------------------------------------------------------
template <class M>
std::string to_string(const instruction<M> &instruction, const syntax_intel &, const lower_case &);

//------------------------------------------------------------------------------
// Name: to_string
// Desc: creates a std::string which represents the given instruction
//------------------------------------------------------------------------------
template <class M>
std::string to_string(const instruction<M> &instruction, const syntax_intel &, const upper_case &);

//------------------------------------------------------------------------------
// Name: to_string
// Desc: creates a std::string which represents the given instruction
//------------------------------------------------------------------------------
template <class M>
std::string to_string(const instruction<M> &instruction);

//------------------------------------------------------------------------------
// Name: to_string
// Desc: creates a std::string which represents the given operand
//------------------------------------------------------------------------------
template <class M>
std::string to_string(const operand<M> &operand, const syntax_intel &, const lower_case &);

//------------------------------------------------------------------------------
// Name: to_string
// Desc: creates a std::string which represents the given operand
//------------------------------------------------------------------------------
template <class M>
std::string to_string(const operand<M> &operand, const syntax_intel &, const upper_case &);

//------------------------------------------------------------------------------
// Name: to_string
// Desc: creates a std::string which represents the given operand
//------------------------------------------------------------------------------
template <class M>
std::string to_string(const operand<M> &operand);

//------------------------------------------------------------------------------
// Name: to_byte_string
// Desc: 
//------------------------------------------------------------------------------
template <class M>
std::string to_byte_string(const instruction<M> &instruction, const lower_case &);

//------------------------------------------------------------------------------
// Name: to_byte_string
// Desc: 
//------------------------------------------------------------------------------
template <class M>
std::string to_byte_string(const instruction<M> &instruction, const upper_case &);

//------------------------------------------------------------------------------
// Name: to_byte_string
// Desc: 
//------------------------------------------------------------------------------
template <class M>
std::string to_byte_string(const instruction<M> &instruction);

//------------------------------------------------------------------------------
// Name: register_name
// Desc: returns a string for a given register
//------------------------------------------------------------------------------
template <class M>
std::string register_name(typename operand<M>::Register reg, const upper_case&);

//------------------------------------------------------------------------------
// Name: register_name
// Desc: returns a string for a given register
//------------------------------------------------------------------------------
template <class M>
std::string register_name(typename operand<M>::Register reg, const lower_case&);

//------------------------------------------------------------------------------
// Name: register_name
// Desc: returns a string for a given register
//------------------------------------------------------------------------------
template <class M>
std::string register_name(typename operand<M>::Register reg);

}


#include "edisassm_string.tcc"
#endif
