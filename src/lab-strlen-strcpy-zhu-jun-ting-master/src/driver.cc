#include "solution.hpp"
#include <iostream>

using namespace std;

int main() {
	char cstr[100] = "hello";
	cout << StrLen(cstr) << endl;
	char* dstr = new char[100];
	StrCpy(dstr, cstr);
	cout << dstr << endl;
}