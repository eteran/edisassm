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

#ifndef REX_20071217_H_
#define REX_20071217_H_

#include "edisassm_types.h"

namespace edisassm {
namespace rex {
	inline bool is_rex(uint8_t value) { return (value & 0xf0) == 0x40; }
	inline uint8_t w(uint8_t value)   { return (value >> 3) & 0x01; } // 64 bit mode
	inline uint8_t r(uint8_t value)   { return (value >> 2) & 0x01; } // modRM extension
	inline uint8_t x(uint8_t value)   { return (value >> 1) & 0x01; } // SIB extension
	inline uint8_t b(uint8_t value)   { return (value >> 0) & 0x01; } // ModRM OR SIB base or Opcode Reg extension
}
}

#endif

