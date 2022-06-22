#include "path_image.hpp"
#include "path.hpp"
#include "elevation_dataset.hpp"
#include "grayscale_image.hpp"
#include "color.hpp"
#include <cstdlib>  // for size_t
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <stdexcept>

using namespace std;

  // std::vector<Path> paths_;
  // size_t width_ = 0;
  // size_t height_ = 0;
  // std::vector<std::vector<Color>> path_image_;
  // static const int kMaxColorValue = 255;

PathImage::PathImage(const GrayscaleImage &image, const ElevationDataset &dataset) {
	width_ = image.Width();
	height_ = image.Height();
	path_image_ = image.GetImage();
	const Color kRed = Color(252, 25, 63);
  const Color kGreen  = Color(31, 253, 13);
	for(size_t i = 0; i < height_; i++) {
		Path p = Path(width_, i);
		for(size_t col = 1; col < width_; col++) {
			size_t pre_row = p.GetPath()[col - 1];
			int previous = dataset.DatumAt(pre_row, col - 1);
			int upper = abs(dataset.DatumAt(pre_row - 1, col) - previous);
			int mid = abs(dataset.DatumAt(pre_row, col) - previous);
			int lower = abs(dataset.DatumAt(pre_row + 1, col) - previous);
			if(upper < mid && upper < lower) {
				p.SetLoc(col, pre_row - 1);
				p.IncEleChange(abs(previous - upper));
			} else if((mid < lower && mid < upper) || (mid == upper && mid <= lower) || (mid == lower && mid <= upper)) {
				p.SetLoc(col, pre_row);
				p.IncEleChange(abs(previous - mid));
			} else if((lower < upper && lower < mid) || (lower == upper && lower < mid)) {
				p.SetLoc(col, pre_row + 1);
				p.IncEleChange(abs(previous - lower));
			}
		}
		paths_.push_back(p);
	}
	Path min_path = paths_[0];
	for(Path p : paths_) {
		if(p.EleChange() <= min_path.EleChange()) {
			min_path = p;
		}
		for(size_t col = 0; col < p.Length(); col++) {
			path_image_[p.GetPath()[col]][col] = kRed;
		}
	}
	for(size_t col = 0; col < min_path.Length(); col++) {
		path_image_[min_path.GetPath()[col]][col] = kGreen;
	}	
}

void PathImage::ToPpm(const std::string& name) const {
	ofstream ofs(name);
	string str = "P3\n" + to_string(width_) + " " + to_string(height_) + "\n";
	str += "255\n";
	for(unsigned i = 0; i < height_; i++) {
		for(unsigned j = 0; j < width_; j++) {
			string num = to_string(path_image_[i][j].Red()) + " ";
			str.append(num);
			num = to_string(path_image_[i][j].Green()) + " ";
			str.append(num);
			num = to_string(path_image_[i][j].Blue()) + " ";
			str.append(num);
		}
		str += "\n";
	}	
	ofs << str;	
}
