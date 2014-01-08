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

#ifndef OPTABLE_GROUP5_20080314_TCC_
#define OPTABLE_GROUP5_20080314_TCC_

namespace edisassm {

template <class M>
const typename Instruction<M>::opcode_entry Instruction<M>::Opcodes_Group5[8] = {
	{ "inc",     &Instruction::decode_Ev,      OP_INC,     FLAG_W_FLAGS },
	{ "dec",     &Instruction::decode_Ev,      OP_DEC,     FLAG_W_FLAGS },
	{ "call",    &Instruction::decode_Ev,      OP_CALL,    FLAG_STACK },
	{ "callf",   &Instruction::decode_Ep,      OP_CALL,    FLAG_32BIT_ONLY | FLAG_STACK },
	{ "jmp",     &Instruction::decode_Ev,      OP_JMP,     FLAG_NONE },
	{ "jmpf",    &Instruction::decode_Ep,      OP_JMP,     FLAG_NONE },
	{ "push",    &Instruction::decode_Ev,      OP_PUSH,    FLAG_STACK },
	{ "invalid", &Instruction::decode_invalid, OP_INVALID, FLAG_NONE },
};

}

#endif

