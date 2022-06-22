#include "path.hpp"
#include "elevation_dataset.hpp"
#include "grayscale_image.hpp"
#include <cstdlib>  // for size_t
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <stdexcept>

using namespace std;

// class Path {
// public:
//   // write behavior declarations here; define in path.cc.
//   Path(size_t length, size_t starting_row);
//   size_t Length() const { return length_; }
//   size_t StartingRow() const { return starting_row_; }
//   size_t EleChange() const { return ele_change_; }
//   void IncEleChange(unsigned int value);
//   const std::vector<size_t>& GetPath() const { return path_; }
//   void SetLoc( size_t col, size_t row );
// private:
//   size_t length_;
//   size_t starting_row_;
//   std::vector<size_t> path_;
//   unsigned int ele_change_ = 0;
// };

Path::Path(size_t length, size_t starting_row) {
	if(length <= 0) {
		throw invalid_argument("length must be positive");
	}
	vector<size_t> vec(length);
	path_ = vec;
	path_[0] = starting_row;
	length_ = length;
	starting_row_ = starting_row;
	ele_change_ = 0;
}

void Path::SetLoc( size_t col, size_t row ) {
	if(col < 0 || col >= length_) {
		throw invalid_argument("invalid col num");
	}
	path_[col] = row;
}