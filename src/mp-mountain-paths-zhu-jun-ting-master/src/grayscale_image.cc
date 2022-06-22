#include "grayscale_image.hpp"
#include "elevation_dataset.hpp"
#include <cstdlib>  // for size_t
#include <vector>
#include <string>
#include <stdexcept>
#include <fstream>
#include <cmath>

using namespace std;

  // size_t width_;
  // size_t height_;
  // std::vector<std::vector<Color>> image_;
  // static const int kMaxColorValue = 255;

GrayscaleImage::GrayscaleImage(const ElevationDataset& dataset) {
	vector<vector<Color>> vec( dataset.Height() , vector<Color> (dataset.Width()));
	image_ = vec;
	width_ = dataset.Width();
	height_ = dataset.Height();
	int max_ele = dataset.MaxEle();
	int min_ele = dataset.MinEle();

	for(unsigned i = 0; i < height_; i++) {
		for(unsigned j = 0; j < width_; j++) {
			int val = dataset.GetData()[i][j];
			int shade_of_gray = round(static_cast<float>(kMaxColorValue) * static_cast<float>(val - min_ele) / static_cast<float>(max_ele - min_ele));
			image_[i][j] = Color(shade_of_gray, shade_of_gray, shade_of_gray);
		}
	}
}

GrayscaleImage::GrayscaleImage(const std::string& filename, size_t width, size_t height) {
	ElevationDataset dataset = ElevationDataset(filename, width, height);
	vector<vector<Color>> vec( dataset.Height() , vector<Color> (dataset.Width()));
	image_ = vec;
	width_ = dataset.Width();
	height_ = dataset.Height();
	int max_ele = dataset.MaxEle();
	int min_ele = dataset.MinEle();

	for(unsigned i = 0; i < height_; i++) {
		for(unsigned j = 0; j < width_; j++) {
			int val = dataset.GetData()[i][j];
			int shade_of_gray = round(static_cast<float>(kMaxColorValue) * static_cast<float>(val - min_ele) / static_cast<float>(max_ele - min_ele));
			image_[i][j] = Color(shade_of_gray, shade_of_gray, shade_of_gray);
		}
	}
}

const Color& GrayscaleImage::ColorAt(int row, int col) const {
	int height = height_;
	int width = width_;
	if(row < 0 || row > height || col < 0 || col > width) {
		throw invalid_argument("invalid row col");
	}
	return image_[row][col];
}

void GrayscaleImage::ToPpm( const std::string& name ) const { 
	ofstream ofs(name);
	string str = "P3\n" + to_string(width_) + " " + to_string(height_) + "\n";
	str += "255\n";
	for(unsigned i = 0; i < height_; i++) {
		for(unsigned j = 0; j < width_; j++) {
			string num = to_string(image_[i][j].Blue()) + " ";
			str.append(num);
			str.append(num);
			str.append(num);
		}
		str += "\n";
	}	
	ofs << str;
}