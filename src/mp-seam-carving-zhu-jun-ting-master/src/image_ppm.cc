#include "image_ppm.hpp"
#include <fstream>
#include <iostream>
#include <string>

// implement the rest of ImagePPM's functions here

ImagePPM::ImagePPM(int height, int width, int max_color, Pixel** pixels):
  height_(height), width_(width), max_color_value_(max_color), pixels_(pixels) {

}

// given functions below, DO NOT MODIFY

ImagePPM::ImagePPM(const std::string& path) {
  std::ifstream input_file(path);
  input_file >> *this;
  input_file.close();
}

ImagePPM::ImagePPM(const ImagePPM& source) { *this = source; }

ImagePPM& ImagePPM::operator=(const ImagePPM& source) {
  if (this == &source) {
    return *this;
  }

  Clear();

  height_ = source.height_;
  width_ = source.width_;
  max_color_value_ = source.max_color_value_;

  pixels_ = new Pixel*[height_];
  for (int row = 0; row < height_; row++) {
    std::cout << row << std::endl;
    std::cout << width_ << std::endl;
    pixels_[row] = new Pixel[width_];

    for (int col = 0; col < width_; col++) {
      pixels_[row][col] = source.pixels_[row][col];
    }
  }

  return *this;
}

ImagePPM::~ImagePPM() { Clear(); }

void ImagePPM::Clear() {
  for (int i = 0; i < height_; i++) {
    delete[] pixels_[i];
  }

  delete[] pixels_;

  height_ = 0;
  width_ = 0;
  pixels_ = nullptr;
}

// std::ostream& operator<<(std::ostream& os, const ImagePPM& image) { 
// 	std::string str = "P3\n" + std::to_string(image.GetWidth()) + " " + std::to_string(image.GetHeight()) + "\n";
// 	str += std::to_string(image.GetMaxColorValue()) + "\n";
// 	for(int i = 0; i < image.GetHeight(); i++) {
// 		for(int j = 0; j < image.GetWidth(); j++) {
// 			std::string num = std::to_string(image.GetPixel(i, j).GetRed()) + '\n';
// 			str.append(num);
// 			num = std::to_string(image.GetPixel(i, j).GetGreen()) + '\n';
// 			str.append(num);
// 			num = std::to_string(image.GetPixel(i, j).GetBlue()) + '\n';
// 			str.append(num);
// 		}
// 		str += "\n";
// 	}	
// 	os << str;
//   return os;
// }


std::ostream& operator<<(std::ostream& os, const ImagePPM& image) {
  os << "P3"
     << "\n";
  os << image.width_ << " " << image.height_ << "\n" << image.max_color_value_ << "\n";

  for (int ii = 0; ii < image.height_; ii++) {

    for (int j = 0; j < image.width_; j++) {

      os << image.GetPixel(ii, j).GetRed() << "\n";
      os << image.GetPixel(ii, j).GetGreen() << "\n";
      // if (ii == image.height_ - 1 && j == image.width_ - 1) 
      //   os << image.GetPixel(ii, j).GetBlue();
      // else
      os << image.GetPixel(ii, j).GetBlue() << "\n";


    }
  }
  return os;
}

std::istream& operator>>(std::istream& is, ImagePPM& image) {
  image.Clear();
  std::string line;
  // ignore magic number line
  getline(is, line);
  // check to see if there's a comment line
  getline(is, line);
  if (line[0] == '#') {
    getline(is, line);
  }
  // parse width and height
  int space = line.find_first_of(' ');
  image.width_ = std::stoi(line.substr(0, space));
  image.height_ = std::stoi(line.substr(space + 1));
  // get max color value
  getline(is, line);
  image.max_color_value_ = std::stoi(line);
  // init and fill in Pixels array
  image.pixels_ = new Pixel*[image.height_];
  for (int i = 0; i < image.height_; i++) {
    image.pixels_[i] = new Pixel[image.width_];
  }
  for (int row = 0; row < image.height_; row++) {
    for (int col = 0; col < image.width_; col++) {
      getline(is, line);
      int red = std::stoi(line);
      getline(is, line);
      int green = std::stoi(line);
      getline(is, line);
      int blue = std::stoi(line);

      Pixel p(red, green, blue);
      image.pixels_[row][col] = p;
    }
  }
  return is;
}

void ImagePPM::RemoveHorizontalSeam(Pixel** image2,
                                    int new_height,
                                    int new_width) {
  Clear();
  pixels_ = image2;
  height_ = new_height;
  width_ = new_width;
  delete[] pixels_[height_];
}
void ImagePPM::RemoveVerticalSeam(Pixel** image1,
                                  int new_height,
                                  int new_width) {
  Clear();
  pixels_ = image1;
  height_ = new_height;
  width_ = new_width;
}