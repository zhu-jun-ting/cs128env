#include "solution.hpp"

unsigned int StrLen(const char* c_str) {
	unsigned i = 0;
	unsigned count = 0;
	while(c_str[i] != '\0') {
		count ++;
		i ++;
	}
	return count;
}





void StrCpy(char*& to, const char* from) {
	if(from == nullptr) {
		return;
	}
	char* dstr = new char[StrLen(from) + 1];
	for(unsigned i = 0; i < StrLen(from) + 1; i++) {
		dstr[i] = from[i];
	}
	delete[] to;
	to = dstr; 
}