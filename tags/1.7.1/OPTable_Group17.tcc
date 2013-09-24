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

#ifndef OPTABLE_GROUP17_20080314_TCC_
#define OPTABLE_GROUP17_20080314_TCC_

namespace edisassm {

template <class M>
const typename instruction<M>::opcode_entry instruction<M>::Opcodes_Group17[64] = {
	{ "prefetchnta", &instruction::decode_M,       OP_PREFETCHH, FLAG_NONE },
	{ "prefetcht0",  &instruction::decode_M,       OP_PREFETCHH, FLAG_NONE },
	{ "prefetcht1",  &instruction::decode_M,       OP_PREFETCHH, FLAG_NONE },
	{ "prefetcht2",  &instruction::decode_M,       OP_PREFETCHH, FLAG_NONE },
	{ "invalid",     &instruction::decode_invalid, OP_INVALID,   FLAG_NONE },
	{ "invalid",     &instruction::decode_invalid, OP_INVALID,   FLAG_NONE },
	{ "invalid",     &instruction::decode_invalid, OP_INVALID,   FLAG_NONE },
	{ "invalid",     &instruction::decode_invalid, OP_INVALID,   FLAG_NONE },

	{ "invalid",     &instruction::decode_invalid, OP_INVALID,   FLAG_NONE },
	{ "invalid",     &instruction::decode_invalid, OP_INVALID,   FLAG_NONE },
	{ "invalid",     &instruction::decode_invalid, OP_INVALID,   FLAG_NONE },
	{ "invalid",     &instruction::decode_invalid, OP_INVALID,   FLAG_NONE },
	{ "invalid",     &instruction::decode_invalid, OP_INVALID,   FLAG_NONE },
	{ "invalid",     &instruction::decode_invalid, OP_INVALID,   FLAG_NONE },
	{ "invalid",     &instruction::decode_invalid, OP_INVALID,   FLAG_NONE },
	{ "invalid",     &instruction::decode_invalid, OP_INVALID,   FLAG_NONE },

	INVALID_BLOCK,

	INVALID_BLOCK,

	INVALID_BLOCK
};

}

#endif
