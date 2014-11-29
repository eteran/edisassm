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

#ifndef EDISASSM_FUNCTIONS_20130610_H_
#define EDISASSM_FUNCTIONS_20130610_H_

namespace edisassm {

template <class T>
bool is_call(const Instruction<T> &insn) {
	return insn.type() == Instruction<T>::OP_CALL;
}

template <class T>
bool is_ret(const Instruction<T> &insn) {
	return insn.type() == Instruction<T>::OP_RET;
}

template <class T>
bool is_conditional_jump(const Instruction<T> &insn) {
	return insn.type() == Instruction<T>::OP_JCC;
}

template <class T>
bool is_unconditional_jump(const Instruction<T> &insn) {
	return insn.type() == Instruction<T>::OP_JMP;
}

template <class T>
bool is_jump(const Instruction<T> &insn) {
	return is_unconditional_jump(insn) || is_conditional_jump(insn);
}

template <class T>
bool is_nop(const Instruction<T> &insn) {
	return insn.type() == Instruction<T>::OP_NOP;
}

template <class T>
bool is_halt(const Instruction<T> &insn) {
	return insn.type() == Instruction<T>::OP_HLT;
}

}

#endif
