#include "elevation_dataset.hpp"
#include "grayscale_image.hpp"
#include "color.hpp"
#include "path.hpp"
#include "path_image.hpp"
#include "path.hpp"
#include <cstdlib>  // for size_t
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <stdexcept>

using namespace std;

int main() {
	const string& filename = "/home/vagrant/src/mp-mountain-paths-zhu-jun-ting-master/tests/input_1.txt";
	const string& savename = "/home/vagrant/src/mp-mountain-paths-zhu-jun-ting-master/tests/output_1.txt";
	const string& save_pathimage = "/home/vagrant/src/mp-mountain-paths-zhu-jun-ting-master/tests/output_pathimage_1.txt";
	size_t width = 5;
	size_t height = 2;
	ElevationDataset ed = ElevationDataset(filename, width, height);
	cout << ed.MaxEle() << endl;
	GrayscaleImage gi = GrayscaleImage(ed);
	cout << gi.ColorAt(0, 4).Blue() << endl;
	gi.ToPpm(savename);
	PathImage pi = PathImage(gi, ed);
	pi.ToPpm(save_pathimage);
}