#include "ImageMerger.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ImageMerger::ImageMerger() {
	// TODO Auto-generated constructor stub

}

ImageMerger::~ImageMerger() {
	// TODO Auto-generated destructor stub
}

void ImageMerger::MergeImages(string path) {
	string indexFilename = path + "/../index.txt";

	ifstream infile(indexFilename);
	string line;
	while(getline(infile, line)) {
		cout << line;
		this->chapters.push_front(line);
	}
}
