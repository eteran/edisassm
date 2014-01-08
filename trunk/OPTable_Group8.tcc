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

#ifndef OPTABLE_GROUP8_20080314_TCC_
#define OPTABLE_GROUP8_20080314_TCC_

namespace edisassm {

template <class M>
const typename instruction<M>::opcode_entry instruction<M>::Opcodes_Group8[8] = {
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "invalid", &instruction::decode_invalid, OP_INVALID, FLAG_NONE },
	{ "bt",      &instruction::decode_Ev_Ib,   OP_BT,      FLAG_W_FLAGS },
	{ "bts",     &instruction::decode_Ev_Ib,   OP_BTS,     FLAG_W_FLAGS },
	{ "btr",     &instruction::decode_Ev_Ib,   OP_BTR,     FLAG_W_FLAGS },
	{ "btc",     &instruction::decode_Ev_Ib,   OP_BTC,     FLAG_W_FLAGS },
};

}

#endif

