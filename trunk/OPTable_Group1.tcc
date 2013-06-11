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

#ifndef OPTABLE_GROUP1_20080314_TCC_
#define OPTABLE_GROUP1_20080314_TCC_

namespace edisassm {

template <class M>
const typename instruction<M>::opcode_entry instruction<M>::Opcodes_Group1[32] = {
	{ "add", &instruction::decode_Eb_Ib, OP_ADD, FLAG_W_FLAGS },
	{ "or",  &instruction::decode_Eb_Ib, OP_OR,  FLAG_W_FLAGS },
	{ "adc", &instruction::decode_Eb_Ib, OP_ADC, FLAG_RW_FLAGS },
	{ "sbb", &instruction::decode_Eb_Ib, OP_SBB, FLAG_NONE },
	{ "and", &instruction::decode_Eb_Ib, OP_AND, FLAG_W_FLAGS },
	{ "sub", &instruction::decode_Eb_Ib, OP_SUB, FLAG_NONE },
	{ "xor", &instruction::decode_Eb_Ib, OP_XOR, FLAG_NONE },
	{ "cmp", &instruction::decode_Eb_Ib, OP_CMP, FLAG_W_FLAGS },

	{ "add", &instruction::decode_Ev_Iz, OP_ADD, FLAG_W_FLAGS },
	{ "or",  &instruction::decode_Ev_Iz, OP_OR,  FLAG_W_FLAGS },
	{ "adc", &instruction::decode_Ev_Iz, OP_ADC, FLAG_RW_FLAGS },
	{ "sbb", &instruction::decode_Ev_Iz, OP_SBB, FLAG_NONE },
	{ "and", &instruction::decode_Ev_Iz, OP_AND, FLAG_W_FLAGS },
	{ "sub", &instruction::decode_Ev_Iz, OP_SUB, FLAG_NONE },
	{ "xor", &instruction::decode_Ev_Iz, OP_XOR, FLAG_NONE },
	{ "cmp", &instruction::decode_Ev_Iz, OP_CMP, FLAG_W_FLAGS },

	{ "add", &instruction::decode_Eb_Ib, OP_ADD, FLAG_W_FLAGS },
	{ "or",  &instruction::decode_Eb_Ib, OP_OR,  FLAG_W_FLAGS },
	{ "adc", &instruction::decode_Eb_Ib, OP_ADC, FLAG_RW_FLAGS },
	{ "sbb", &instruction::decode_Eb_Ib, OP_SBB, FLAG_NONE },
	{ "and", &instruction::decode_Eb_Ib, OP_AND, FLAG_W_FLAGS },
	{ "sub", &instruction::decode_Eb_Ib, OP_SUB, FLAG_NONE },
	{ "xor", &instruction::decode_Eb_Ib, OP_XOR, FLAG_NONE },
	{ "cmp", &instruction::decode_Eb_Ib, OP_CMP, FLAG_W_FLAGS },

	{ "add", &instruction::decode_Ev_Ib, OP_ADD, FLAG_W_FLAGS },
	{ "or",  &instruction::decode_Ev_Ib, OP_OR,  FLAG_W_FLAGS },
	{ "adc", &instruction::decode_Ev_Ib, OP_ADC, FLAG_RW_FLAGS },
	{ "sbb", &instruction::decode_Ev_Ib, OP_SBB, FLAG_NONE },
	{ "and", &instruction::decode_Ev_Ib, OP_AND, FLAG_W_FLAGS },
	{ "sub", &instruction::decode_Ev_Ib, OP_SUB, FLAG_NONE },
	{ "xor", &instruction::decode_Ev_Ib, OP_XOR, FLAG_NONE },
	{ "cmp", &instruction::decode_Ev_Ib, OP_CMP, FLAG_W_FLAGS },
};

}

#endif

