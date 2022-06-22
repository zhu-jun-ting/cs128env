#include "seam_carver.hpp"
#include "image_ppm.hpp"
#include "pixel.hpp" 
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

// implement the rest of SeamCarver's functions here

// given functions below, DO NOT MODIFY

SeamCarver::SeamCarver(const ImagePPM& image): image_(image) {
  height_ = image.GetHeight();
  width_ = image.GetWidth();
}


void SeamCarver::SetImage(const ImagePPM& image) {
  image_ = image;
  width_ = image.GetWidth();
  height_ = image.GetHeight();
}

// findMinPathDynamicProgramming():
//     Values ← 2D array with height rows and width columns

//     For each cell in the last row
//         Values[cell_row][cell_col] ← E(cell_row, cell_col)

//     For each row starting from the second to last
//         For each cell in the row
//             Best ← Min(Values[/*down-right*/], Values[/*down*/], Values[/*down-left*/])
//             Values[cell_row][cell_col] ← Best + E(cell_row, cell_col)

//     Return minimum cell of Values[0]


int* SeamCarver::GetHorizontalSeam() const {
  if (width_ == 0 || height_ == 0) {
    return new int(0);
  }
  int** array = new int*[height_];
  for (int row = 0; row < height_; row++) {
    array[row] = new int[width_];
  }
  for (int row = 0; row < height_; row++) {
    array[row][width_ - 1] = GetEnergy(row, width_ - 1);
  }
  for (int col = width_ - 2; col >= 0; col--) {
    for (int row = 0; row < height_; row++) {
      int min = array[row][col + 1];

      if (row > 0) {
        if (array[row - 1][col + 1] < min) {
          min = array[row - 1][col + 1];
        }
      }
      if (row < height_ - 1) {
        if (array[row + 1][col + 1] < min) {
          min = array[row + 1][col + 1];
        }
      }
      if (array[row][col + 1] <= min) {
        min = array[row][col + 1];
      }
      array[row][col] = min + GetEnergy(row, col);
    }
  }
  int* hor = Hehehe(height_, width_, array);
  for (int row = 0; row < height_; row++) {
    delete[] array[row];
  }
  delete[] array;
  return hor;
}

int* SeamCarver::Hehehe(int height_, int width_, int** array) const {
  int* hor = new int[width_];
  int value = array[0][0];
  int index2 = 0;
  for (int row = 1; row < height_; row++) {
    if (array[row][0] < value) {
      value = array[row][0];
      index2 = row;
    }
  }
  hor[0] = index2;
  for (int col = 1; col < width_; col++) {
    int set2 = index2;
    int min = array[index2][col];
    if (index2 > 0) {
      if (array[index2 - 1][col] < min) {
        min = array[index2 - 1][col];
        set2 = index2 - 1;
      }
    }
    if (index2 < height_ - 1) {
      if (array[index2 + 1][col] < min) {
        min = array[index2 + 1][col];
        set2 = index2 + 1;
      }
    }
    hor[col] = set2;
    index2 = set2;
  }
  return hor;
}



int* SeamCarver::GetVerticalSeam() const {
  if (width_ == 0 || height_ == 0) return new int(0);
  int** another_array = new int*[height_];
  for (int row = 0; row < height_; row++) {
    another_array[row] = new int[width_];
  }
  for (int col = 0; col < width_; col++) another_array[height_ - 1][col] = GetEnergy(height_ - 1, col);
  for (int row = height_ - 2; row >= 0; row--) {
    for (int col = 0; col < width_; col++) {
      int min = another_array[row + 1][col];
      if (col > 0) {
        if (another_array[row + 1][col - 1] <= min) {
          min = another_array[row + 1][col - 1];
        }
      }
      if (col < width_ - 1) {
        if (another_array[row + 1][col + 1] <= min) {
          min = another_array[row + 1][col + 1];
        }
      }
      if (another_array[row + 1][col] <= min) {
        min = another_array[row + 1][col];
      }
      another_array[row][col] = min + GetEnergy(row, col);
    }
  }
  int value = another_array[0][0];
  int index = 0;
  for (int col = 0; col < width_; col++) {
    if (value > another_array[0][col]) {
      value = another_array[0][col];
      index = col;
    }
  }
  int* verticel = Hahaha(height_, width_, index, another_array);
  for (int row = 0; row < height_; row++) delete[] another_array[row];
  delete[] another_array;
  return verticel;
}

int* SeamCarver::Hahaha(int height_, int width_, int index, int** another_array) const {
  int* verticel = new int[height_];
  verticel[0] = index;
  for (int row = 1; row < height_; row++) {
    int set = index;
    int min2 = another_array[row][index];
    if (index < width_ - 1) {
      if (another_array[row][index + 1] <= min2) {
        min2 = another_array[row][index + 1];
        set = index + 1;
      }
    }
    if (index > 0) {
      if (another_array[row][index - 1] <= min2) {
        min2 = another_array[row][index - 1];
        set = index - 1;
      }
    }
    if (another_array[row][index] <= min2) {
      min2 = another_array[row][index];
      set = index;
    }
    verticel[row] = set;
    index = set;
  }
  return verticel;
}

// int* SeamCarver::GetHorizontalSeam() const {
//   int** energy = new int*[height_];
//   for (int row = 0; row < height_; row++) {
//     energy[row] = new int[width_];
//   }

//   for (int row = 0; row < height_; row++) {
//     energy[row][width_ - 1] = GetEnergy(row, width_ - 1);
//   }

//   for (int col = width_ - 2; col >= 0; col--) {
//     for (int row = 0; row < height_; row++) {
//       int up = row == 0? kMaxInt: energy[row - 1][col + 1];
//       int mid = energy[row][col + 1];
//       int down = row == height_ - 1? kMaxInt: energy[row + 1][col + 1];
//       energy[row][col] = GetEnergy(row, col) + Min(up, mid, down);
//     }
//   }

//   int start_row = 0;
//   for (int row = 0; row < height_; row++) {
//     if (energy[row][0] < energy[start_row][0]) {
//       start_row = row;
//     }
//   }

//   int* path = GetHorizontalSeamPath(energy, start_row);

//   for (int row = 0; row < height_; row++) {
//     delete[] energy[row];
//   }
//   // delete[] energy;

//   return path;
// }

// int* SeamCarver::GetHorizontalSeamPath(int** energy, int start_row) const {
//   int* path = new int[width_]();
//   path[0] = start_row;

//   for (int col = 1; col < width_; col++) {
//     int previous_row = path[col - 1];
//     int up = previous_row == 0? kMaxInt: energy[previous_row - 1][col];
//     int mid = energy[previous_row][col];
//     int down = previous_row == height_ - 1? kMaxInt: energy[previous_row + 1][col];
//     int min_val = Min(up, mid, down);
//     if (min_val == mid) {
//       path[col] = previous_row;
//     } else if (min_val == up) {
//       path[col] = previous_row - 1;
//     } else {
//       path[col] = previous_row + 1;
//     }
//   }

//   return path;
// }

// int* SeamCarver::GetVerticalSeam() const {
//   int** energy = new int*[height_];
//   for (int row = 0; row < height_; row++) {
//     energy[row] = new int[width_];
//   }

//   for (int col = 0; col < width_; col++) {
//     energy[height_ - 1][col] = GetEnergy(height_ - 1, col);
//   }

//   for (int row = height_ - 2; row >= 0; row--) {
//     for (int col = 0; col < width_; col++) {
//       int left = col == 0? kMaxInt: energy[row + 1][col - 1];
//       int mid = energy[row + 1][col];
//       int right = col == width_ - 1? kMaxInt: energy[row + 1][col + 1];
//       energy[row][col] = GetEnergy(row, col) + Min(left, mid, right);
//     }
//   }

//   int start_col = 0;
//   for (int col = 0; col < width_; col++) {
//     if (energy[0][col] < energy[0][start_col]) {
//       start_col = col;
//     }
//   }

//   int* path = GetVerticalSeamPath(energy, start_col);

//   for (int row = 0; row < height_; row++) {
//     delete[] energy[row];
//   }
//   // delete[] energy;

//   return path;
// }

// int* SeamCarver::GetVerticalSeamPath(int** energy, int start_col) const {
//   int* path = new int[height_]();
//   path[0] = start_col;

//   for (int row = 1; row < height_; row++) {
//     int previous_col = path[row - 1];
//     int left = previous_col == 0? kMaxInt: energy[row][previous_col - 1];
//     int mid = energy[row][previous_col];
//     int right = previous_col == width_ - 1? kMaxInt: energy[row][previous_col + 1];
//     int min_val = Min(left, mid, right);
//     if (min_val == mid) {
//       path[row] = previous_col;
//     } else if (min_val == left) {
//       path[row] = previous_col - 1;
//     } else {
//       path[row] = previous_col + 1;
//     }
//   }

//   return path;
// }

int SeamCarver::GetEnergy(int row, int col) const {
  Pixel left(0, 0, 0);
  Pixel right(0, 0, 0);
  Pixel up(0, 0, 0);
  Pixel down(0, 0, 0);

  if (col == 0) {
    left = image_.GetPixel(row, width_ - 1);
    right = image_.GetPixel(row, col + 1);
  } else if (col == width_ - 1) {
    left = image_.GetPixel(row, col - 1);
    right = image_.GetPixel(row, 0);
  } else {
    left = image_.GetPixel(row, col - 1);
    right = image_.GetPixel(row, col + 1); 
  }

  if (row == 0) {
    up = image_.GetPixel(height_ - 1, col);
    down = image_.GetPixel(row + 1, col);
  } else if (row == height_ - 1) {
    up = image_.GetPixel(row - 1, col);
    down = image_.GetPixel(0, col);
  } else {
    up = image_.GetPixel(row - 1, col);
    down = image_.GetPixel(row + 1, col);
  }

  int energy = 0;

  energy += (left.GetRed() - right.GetRed()) * (left.GetRed() - right.GetRed());
  energy += (left.GetBlue() - right.GetBlue()) * (left.GetBlue() - right.GetBlue());
  energy += (left.GetGreen() - right.GetGreen()) * (left.GetGreen() - right.GetGreen());
  energy += (up.GetRed() - down.GetRed()) * (up.GetRed() - down.GetRed());
  energy += (up.GetBlue() - down.GetBlue()) * (up.GetBlue() - down.GetBlue());
  energy += (up.GetGreen() - down.GetGreen()) * (up.GetGreen() - down.GetGreen());

  return energy;

}

// void SeamCarver::RemoveHorizontalSeam() {
//   height_ --;
//   int* path = GetHorizontalSeam();
//   int max_color = 0;

//   auto* new_image = new Pixel*[height_];
//   for (int col = 0; col < width_; col++) {
//     new_image[col] = new Pixel[width_];
//   }

//   for (int col = 0; col < width_; col++) {
//     int new_row = 0;
//     for (int row = 0; row < height_ + 1; row++) {
//       if (col != path[row]) {
//         Pixel p = image_.GetPixel(row, col);
//         new_image[new_row][col] = p;
//         new_row ++;
//         if (max_color < Max(p.GetRed(), p.GetBlue(), p.GetGreen())) {
//           max_color = Max(p.GetRed(), p.GetBlue(), p.GetGreen());
//         }
//       }
//     }
//   }

//   auto *ip = new ImagePPM(height_, width_, max_color, new_image);

//   SetImage(*ip);
// }

// void SeamCarver::RemoveVerticalSeam() {
//   width_ --;
//   int* path = GetVerticalSeam();
//   int max_color = 0;

//   auto* new_image = new Pixel*[height_];
//   for (int col = 0; col < width_; col++) {
//     new_image[col] = new Pixel[width_];
//   }

//   for (int row = 0; row < height_; row++) {
//     int new_col = 0;
//     for (int col = 0; col < width_ + 1; col++) {
//       if (row != path[col]) {
//         Pixel p = image_.GetPixel(row, col);
//         new_image[row][new_col] = p;
//         new_col ++;
//         if (max_color < Max(p.GetRed(), p.GetBlue(), p.GetGreen())) {
//           max_color = Max(p.GetRed(), p.GetBlue(), p.GetGreen());
//         }
//       }
//     }
//   }

//   auto *ip = new ImagePPM(height_, width_, max_color, new_image);

//   SetImage(*ip);
// }


void SeamCarver::RemoveHorizontalSeam() {
  int* horr = GetHorizontalSeam();
  auto *pixel = new Pixel*[height_];
  for (int row = 0; row < height_; row++) {
    pixel[row] = new Pixel[width_];
  }
  for (int col = 0; col < width_; col++) {
    int count = 0;
    for (int row = 0; row < height_; row++) {
      if (horr[col] == row) {

        count++;
      } else {

        pixel[row - count][col] = image_.GetPixel(row, col);
      }
    }
  }
  image_.RemoveVerticalSeam(pixel, height_ - 1, width_);
  height_ = height_ - 1;

  delete[] horr;
}

void SeamCarver::RemoveVerticalSeam() {
  int* verticall = GetVerticalSeam();

  auto *pixel = new Pixel*[height_];
  for (int row = 0; row < height_; row++) {
    pixel[row] = new Pixel[width_];
  }

  for (int row = 0; row < height_; row++) {
    int count = 0;
    for (int col = 0; col < width_; col++) {
      if (verticall[row] == col) {
        count++;

      } else {
        pixel[row][col - count] = image_.GetPixel(row, col);
      }
    }

  }
  image_.RemoveVerticalSeam(pixel, height_, width_ - 1);

  width_ = width_ - 1;
  delete[] verticall;
}


int Min(int a, int b, int c) {
  return a < b ? a : b < c ? b : c;
}

int Max(int a, int b, int c) {
  return a > b ? a : b > c ? b : c;
}
