#pragma once

#include <string>
#include <list>

class ImageMerger {
public:
	ImageMerger();
	virtual ~ImageMerger();
	void MergeImages(std::string path);
private:
	std::list<std::string> chapters;
};
