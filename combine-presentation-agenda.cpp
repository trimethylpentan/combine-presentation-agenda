#include <string>

#include "src/ImageMerger.h"

using namespace std;

int main(int argc, char **argv) {
	string path = argv[0];

	ImageMerger merger;
	merger.MergeImages(path);

	return 0;
}
