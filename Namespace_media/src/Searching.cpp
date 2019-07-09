/*
 * Searching.cpp
 *
 *  Created on: 22-Apr-2019
 *      Author: kpit
 */
#include "Searching.h"
#include "Song.h"

using namespace MediaIndexer;
/*
 * type: variable
 * unique index for container
 */
static int indexForContainer = 0;

/*
 * return type: int (for successful returning ,else error code)
 * parameter type: const string
 * description: takes string argument as a path and it checks recursively
 * 				for given path. if found return 0 else return
 * error
 * code.
 */
int Searching::SearchFile(const std::string &directoryPath) {
	DIR *dir;
	struct stat stat_;
	struct dirent *dp;
	std::string fName, fFormat, fPath;
	double fInodeno, fSize;

	if ((dir = opendir(directoryPath.c_str())) != NULL) {
		while ((dp = readdir(dir)) != NULL) {
			auto absolutePath = directoryPath + "/" + std::string(dp->d_name);
			auto filename = std::string(dp->d_name);

			if (strncmp(dp->d_name, ".", 10) != 0 &&
					strncmp(dp->d_name, "..", 10) != 0) {
				stat(absolutePath.c_str(), &stat_);
				if (S_ISDIR(stat_.st_mode)) {
					SearchFile(absolutePath);
				} else {
					if (absolutePath.substr(absolutePath.rfind(".") + 1) == "mp3") {
						stat(absolutePath.c_str(), &stat_);

						fFormat = ".mp3";
						fInodeno = stat_.st_ino;
						fSize = stat_.st_size;
						fSize /= (1024 * 1024);

						std::ifstream inputFile(absolutePath, std::ios::binary);
						if (inputFile.is_open()) {
							unsigned char magic[4] = {0};
							inputFile.read((char *)magic, sizeof(magic));
							if ((magic[0] == 0x49) && (magic[1] == 0x44) &&
									(magic[2] == 0x33)) {
								++indexForContainer;

								ptrMediaFactory->addMediaToConatiner(
										Song(indexForContainer, filename, fFormat, absolutePath,
												fInodeno, fSize));
							}
							inputFile.close();
						}
					}
				}
			}
		}
		closedir(dir);
		return 0;
	} else {
		return errno;
	}
}

/*
 *@brief: default constructor initialize Manager(Intermediate class)
                  also,it will provide object of Storage class(Unordered Map)
 and
                  sending pointer of media factory to the display class
 */
Searching::Searching() {
	ptrIntermediate = new Intermediate();
	ptrMediaFactory = ptrIntermediate->getMedia();
	display.recieveMediaFactoryPointer(ptrMediaFactory);
}
/*
 * @brief: destructor : deallocate allocated memory
 * for MediaFactory and Intermediate class
 * */
Searching::~Searching() {
	delete ptrMediaFactory;
	delete ptrIntermediate;
}
/*
 * @brief: getter for Display object*/
DisplayContainer Searching::getDisplay() const { return display; }

