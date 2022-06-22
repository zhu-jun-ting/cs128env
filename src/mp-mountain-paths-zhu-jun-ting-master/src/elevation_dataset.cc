#include "elevation_dataset.hpp"
#include <cstdlib>  // for size_t
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <limits>

using namespace std;

ElevationDataset::ElevationDataset(const string& filename, size_t width, size_t height): width_(width), height_(height) {
	vector<int> vec = GetIntsFromFile(filename);
	if(vec.size() != width * height) {
		throw invalid_argument("size does not match");
	}
	max_ele_ = vec[0];
	min_ele_ = vec[0];
	vector<int> line;
	for(unsigned i = 0; i < vec.size(); i++) {
		line.push_back(vec[i]);
		if(line.size() == width) {
			data_.push_back(line);
			line.clear();
		}
		if(vec[i] > max_ele_) {
			max_ele_ = vec[i];
		}
		if(vec[i] < min_ele_) {
			min_ele_ = vec[i];
		}
	}
	// cout << vec[0] << endl;
}

int ElevationDataset::DatumAt(size_t row, size_t col) const {
	if(row < 0 || row >= height_ || col < 0 || col >= width_) {
		return numeric_limits<int>::max();
	}
	return data_[row][col];
}


std::vector<int> GetIntsFromFile(const string& file_name) {
  vector<int> vec;
  int value = 0;
  std::ifstream ifs(file_name);
  if(!ifs.is_open()) {
      throw std::runtime_error("ifs is bad");
  }
  while(ifs.good()) {
    ifs >> value;
    if(ifs.fail()) {
      ifs.clear();
      ifs.ignore(1, '\n');
    } else {
      vec.push_back(value);
    }
  }
  return vec;
}