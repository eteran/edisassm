
#include "Instruction.h"
#include "Formatter.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>

typedef edisassm::Instruction<edisassm::x86_64> insn64_t;

struct test_data_t {
	unsigned size;
	const char *bytes;
	const char *result;
	unsigned int flags;
} test64_data[] = {
	
	// stupid wait prefix stuff...
	{3, "\x0f\x7e\xf0",         "movd eax, mm6",   insn64_t::FLAG_MMX},
	{3, "\x0f\x6e\xf8",         "movd mm7, eax",   insn64_t::FLAG_MMX},
	{5, "\x66\x44\x0f\x6e\xd1", "movd xmm10, ecx", insn64_t::FLAG_MMX},
	


};

int main() {

	edisassm::Formatter formatter;



	for(size_t i = 0; i < sizeof(test64_data) / sizeof(test64_data[0]); ++i) {
		test_data_t *p = &test64_data[i];

		std::cout << "performing test #" << i << "...";
		insn64_t insn(p->bytes, p->bytes + p->size, 0x00000000, std::nothrow);

		if(!insn.valid() || formatter.to_string(insn) != p->result) {
			std::cout << "\n----------\n";
			std::cout << formatter.to_string(insn) << " != " << p->result << std::endl;
			std::cout << "FAIL" << std::endl;
			return -1;
		}

		if(insn.size() != p->size) {
			std::cout << "\n----------\n";
			std::cout << formatter.to_byte_string(insn) << " incorrect size" << std::endl;
			std::cout << "FAIL" << std::endl;
			return -1;
		}

		if(insn.flags() != p->flags) {
			std::cout << "\n----------\n";
			std::cout << formatter.to_byte_string(insn) << " wrong flags" << std::endl;
			std::cout << "FLAGS: " << insn.flags() << std::endl;
			std::cout << "FAIL" << std::endl;
			return -1;
		}

		std::cout << " " << formatter.to_byte_string(insn) << " '" << formatter.to_string(insn) << "' " << "OK" << std::endl;
	}
}
