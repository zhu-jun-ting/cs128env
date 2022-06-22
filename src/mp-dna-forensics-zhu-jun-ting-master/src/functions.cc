#include "functions.hpp"
#include "utilities.hpp"
#include <fstream>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

vector<string> GetHeader(const string& fname) {
	std::ifstream ifs{fname};
	string line;
	std::getline(ifs, line);
	// std::cout << "line1 = \"" << line << '\"' << std::endl;
	vector<string> header = utilities::GetSubstrs(line, ',');
	return header;
}

vector<vector<string>> GetDataframe(const string& fname) {
	std::ifstream ifs{fname};
	string first_line;
	vector<vector<string>> df;
	std::getline(ifs, first_line);
	for (std::string line; std::getline(ifs, line); line = "")
		// std::cout << "line = \"" << line << '\"' << std::endl;
		// vector<string> row = utilities::GetSubstrs(line, ',');
		df.push_back(utilities::GetSubstrs(line, ','));
	return df;
}

int CountMaxConsec(const string& str, const string& query) {
	int window = query.length();
	int count = 0;
	int max_count = 0;
	for (unsigned long i = 0; i < str.length() - window; i++) {
		while (str.substr(i, window) == query) {
			count++;
			i += window;
		}
		if (max_count < count) {
			max_count = count;
		}
		count = 0;
	}
	return max_count;
}

string GetName(const string& fname, const string& dna) {
	vector<string> header = GetHeader(fname);
	vector<vector<string>> df = GetDataframe(fname);
	bool right_person = true;

	// looping through the header and dataframe (without first col = name)
	for (unsigned long name_index = 0; name_index < df.size(); name_index++) {
		for (unsigned long i = 1; i < header.size(); i++) {
			if (stoi(df[name_index][i]) != CountMaxConsec(dna, header[i])) {
				right_person = false;
				break;
			}
		}
		if (right_person) {
			return df[name_index][0];
		}
		right_person = true;
	}
	return "No match";
}