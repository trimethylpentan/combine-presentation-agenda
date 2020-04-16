#include "ImageMerger.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <istream>
#include <errno.h>
#include <cstring>
#include <stdexcept>

using namespace std;

ImageMerger::ImageMerger() {
	// TODO Auto-generated constructor stub

}

ImageMerger::~ImageMerger() {
	// TODO Auto-generated destructor stub
}

void ImageMerger::MergeImages(string path) {
	string indexFilename = path.substr(0, path.find_last_of("\\/")) + "/index.txt";

	ifstream infile(indexFilename);
	if (!infile.good()) {
		throw runtime_error(strerror(errno));
	}
	string line;

	while(getline(infile, line)) {
		cout << line << endl;
		this->chapters.push_front(line);
	}
}
