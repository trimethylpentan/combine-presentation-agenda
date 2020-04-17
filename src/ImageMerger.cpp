#include "ImageMerger.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <istream>
#include <errno.h>
#include <cstring>
#include <stdexcept>
#include <opencv4/opencv2/opencv.hpp>

using namespace std;
using namespace cv;

ImageMerger::ImageMerger() {
	// TODO Auto-generated constructor stub

}

ImageMerger::~ImageMerger() {
	// TODO Auto-generated destructor stub
}

void ImageMerger::MergeImages(string path) {
	string directoryName = path.substr(0, path.find_last_of("\\/"));
	string indexFilename = directoryName + "/index.txt";

	ifstream infile(indexFilename);
	if (!infile.good()) {
		throw runtime_error(strerror(errno));
	}
	string line;

	list<string> chapters;

	while(getline(infile, line)) {
		chapters.push_back(line);
	}

	for(const string chapter : chapters) {
		list<Mat3b> images;
		int cols = 0;
		int rows;

		for(const string currentChapter : chapters) {
			Mat3b image;
			if (currentChapter == chapter) {
				 image = imread(directoryName + "/img/point_highlight.png");
			} else {
				image = imread(directoryName + "/img/point_neutral.png");
			}
			Mat icon = imread(directoryName + "/img/" + currentChapter, IMREAD_UNCHANGED);
			OverlayImage(image, icon, image, Point((image.cols / 2) - (icon.cols / 2), (image.rows / 2) - (icon.rows / 2)));
			images.push_back(image);
			cols += image.cols;
			rows = image.rows;
		}
		
		int lastCols = 0;
		Mat3b background(rows, cols, Vec3b(0, 0, 0));
		
		for(const Mat3b currentImage : images) {
			currentImage.copyTo(background(Rect(lastCols, 0, currentImage.cols, currentImage.rows)));
			lastCols += currentImage.cols;
		}
		
		imwrite(directoryName + "/img/out" + chapter + ".png", background);
	}
}

// Source: http://jepsonsblog.blogspot.com/2012/10/overlay-transparent-image-in-opencv.html
void ImageMerger::OverlayImage(const cv::Mat &background, const cv::Mat &foreground, cv::Mat &output, cv::Point2i location) {
  background.copyTo(output);

  // start at the row indicated by location, or at row 0 if location.y is negative.
  for(int y = std::max(location.y , 0); y < background.rows; ++y)
  {
    int fY = y - location.y; // because of the translation

    // we are done of we have processed all rows of the foreground image.
    if(fY >= foreground.rows)
      break;

    // start at the column indicated by location,
    // or at column 0 if location.x is negative.
    for(int x = std::max(location.x, 0); x < background.cols; ++x)
    {
      int fX = x - location.x; // because of the translation.

      // we are done with this row if the column is outside of the foreground image.
      if(fX >= foreground.cols)
        break;

      // determine the opacity of the foregrond pixel, using its fourth (alpha) channel.
      double opacity =
        ((double)foreground.data[fY * foreground.step + fX * foreground.channels() + 3]) / 255.;

      // and now combine the background and foreground pixel, using the opacity,

      // but only if opacity > 0.
      for(int c = 0; opacity > 0 && c < output.channels(); ++c)
      {
        unsigned char foregroundPx =
          foreground.data[fY * foreground.step + fX * foreground.channels() + c];
        unsigned char backgroundPx =
          background.data[y * background.step + x * background.channels() + c];
        output.data[y*output.step + output.channels()*x + c] =
          backgroundPx * (1.-opacity) + foregroundPx * opacity;
      }
    }
  }
}
