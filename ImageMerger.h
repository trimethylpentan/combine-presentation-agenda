#pragma once

#include <string>

class ImageMerger {
public:
	ImageMerger();
	virtual ~ImageMerger();
	void MergeImages(std::string path);
};
