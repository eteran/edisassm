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

#ifndef SIB_20070530_H_
#define SIB_20070530_H_

#include "edisassm_types.h"

namespace edisassm {
namespace sib {
	inline uint8_t base(uint8_t value)  { return value & 0x07; }
	inline uint8_t index(uint8_t value) { return (value >> 3) & 0x07; }
	inline uint8_t scale(uint8_t value) { return (value >> 6) & 0x03; }
}
}

#endif

