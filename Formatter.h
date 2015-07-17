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

#ifndef FORMATTER_H_
#define FORMATTER_H_

#include <string>

namespace edisassm {

template <class M>
class Instruction;

template <class M>
class Operand;

enum Syntax {
	SyntaxIntel,
//	SyntexATT // TODO(eteran): implement this format!
};

enum Capitalization {
	UpperCase,
	LowerCase
};

enum SmallNumberFormat {
	SmallNumAsHex,
	SmallNumAsDec
};

struct FormatOptions {
	Syntax            syntax;
	Capitalization    capitalization;
	SmallNumberFormat smallNumFormat;
};

class Formatter {
public:
	Formatter();
	Formatter(const Formatter &other);
	~Formatter();
	explicit Formatter(const FormatOptions &options);
	Formatter &operator=(const Formatter &rhs);
	
public:
	template <class M>
	std::string to_string(const Instruction<M> &inst);
	
	template <class M>
	std::string to_string(const Operand<M> &op);
	
	template <class M>
	std::string to_byte_string(const Instruction<M> &inst);
	
	template <class M>
	std::string register_name(typename Operand<M>::Register reg);
	
private:
	template <class M>
	std::string format_expression(const Operand<M> &op);

	template <class M>
	std::string format_register(const Operand<M> &op);
	
public:
	void swap(Formatter &other);
	
private:
	FormatOptions options_;
};

}

#include "Formatter.tcc"

#endif
