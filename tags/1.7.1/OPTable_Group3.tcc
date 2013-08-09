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

#ifndef OPTABLE_GROUP3_20080314_TCC_
#define OPTABLE_GROUP3_20080314_TCC_

namespace edisassm {

template <class M>
const typename instruction<M>::opcode_entry instruction<M>::Opcodes_Group3[16] = {
	{ "test",    &instruction::decode_Eb_Ib,   OP_TEST,    FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "not",     &instruction::decode_Eb,      OP_NOT,     FLAG_NONE },
	{ "neg",     &instruction::decode_Eb,      OP_NEG,     FLAG_W_FLAGS },
	{ "mul",     &instruction::decode_Eb,      OP_MUL,     FLAG_W_FLAGS },
	{ "imul",    &instruction::decode_Eb,      OP_IMUL,    FLAG_W_FLAGS },
	{ "div",     &instruction::decode_Eb,      OP_DIV,     FLAG_NONE },
	{ "idiv",    &instruction::decode_Eb,      OP_IDIV,    FLAG_NONE },

	{ "test",    &instruction::decode_Ev_Iz,   OP_TEST,    FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "not",     &instruction::decode_Ev,      OP_NOT,     FLAG_NONE },
	{ "neg",     &instruction::decode_Ev,      OP_NEG,     FLAG_W_FLAGS },
	{ "mul",     &instruction::decode_Ev,      OP_MUL,     FLAG_W_FLAGS },
	{ "imul",    &instruction::decode_Ev,      OP_IMUL,    FLAG_W_FLAGS },
	{ "div",     &instruction::decode_Ev,      OP_DIV,     FLAG_NONE },
	{ "idiv",    &instruction::decode_Ev,      OP_IDIV,    FLAG_NONE },
};

}

#endif

