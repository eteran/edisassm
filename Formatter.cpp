/*
Copyright (C) 2006 - 2015 Evan Teran
                          evan.teran@gmail.com

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

#include "Formatter.h"
#include <algorithm>

namespace edisassm {

//------------------------------------------------------------------------------
// Name: Formatter
//------------------------------------------------------------------------------
Formatter::Formatter() {
	options_.syntax         = SyntaxIntel;
	options_.capitalization = LowerCase;
	options_.smallNumFormat = SmallNumAsDec;
}

//------------------------------------------------------------------------------
// Name: Formatter
//------------------------------------------------------------------------------
Formatter::Formatter(const Formatter &other) : options_(other.options_) {

}

//------------------------------------------------------------------------------
// Name: ~Formatter
//------------------------------------------------------------------------------
Formatter::~Formatter() {

}

//------------------------------------------------------------------------------
// Name: Formatter
//------------------------------------------------------------------------------
Formatter::Formatter(const FormatOptions &options) : options_(options) {

}

//------------------------------------------------------------------------------
// Name: operator=
//------------------------------------------------------------------------------
Formatter &Formatter::operator=(const Formatter &rhs) {
	Formatter(rhs).swap(*this);
	return *this;
}

//------------------------------------------------------------------------------
// Name: swap
//------------------------------------------------------------------------------
void Formatter::swap(Formatter &other) {
	using std::swap;
	swap(options_, other.options_);
}

}
