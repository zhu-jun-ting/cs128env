#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include "utilities.hpp"
using namespace std;

vector<vector<string>> GetDataframe(const string& fname);
int CountMaxConsec(const string& str, const string& query);
string GetName(const string& fname, const string& dna);



#endif