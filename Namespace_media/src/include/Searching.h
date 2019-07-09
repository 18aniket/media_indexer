/*
 * Searching.h
 *
 *  Created on: 22-Apr-2019
 *      Author: kpit
 */

#ifndef SEARCHING_H_
#define SEARCHING_H_

#include <dirent.h>
#include <errno.h>
#include <libgen.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <ostream>
#include <string>
#include "Song.h"

#include "DisplayContainer.h"
#include "Intermediate.h"
#include "MediaFactory.h"

namespace MediaIndexer {
class Searching {
 private:
  Intermediate *ptrIntermediate;
  MediaFactory *ptrMediaFactory;
  DisplayContainer display;

 public:
  Searching();

  int SearchFile(const std::string &path);

  ~Searching();

  DisplayContainer getDisplay() const;
};
}
#endif /* SEARCHING_H_ */
