#pragma once

#include <string>
#include <list>
#include <opencv4/opencv2/opencv.hpp>

class ImageMerger {
public:
	ImageMerger();
	virtual ~ImageMerger();
	void MergeImages(std::string path);
private:
	void OverlayImage(const cv::Mat &background, const cv::Mat &foreground, cv::Mat &output, cv::Point2i location);
};
