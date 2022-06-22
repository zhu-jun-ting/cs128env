#ifndef PATH_IMAGE_H
#define PATH_IMAGE_H

#include "color.hpp"
#include "path.hpp"
#include "elevation_dataset.hpp"
#include "grayscale_image.hpp"
#include <cstdlib>  // for size_t
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <stdexcept>


class PathImage {
public:
  // write behavior declarations here; define in path_image.cc.
  PathImage(const GrayscaleImage &image, const ElevationDataset &dataset);
  size_t Width() const { return width_; }
  size_t Height() const { return height_; }
  size_t MaxColorValue() const { return kMaxColorValue; }
  const std::vector<Path>& Paths() const { return paths_; }
  const std::vector<std::vector<Color> >& GetPathImage() const { return path_image_; }
  void ToPpm(const std::string& name) const;
private:
  std::vector<Path> paths_;
  size_t width_ = 0;
  size_t height_ = 0;
  std::vector<std::vector<Color>> path_image_;
  static const int kMaxColorValue = 255;
};

#endif