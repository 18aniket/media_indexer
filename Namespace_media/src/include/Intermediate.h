/*
 * Intermediate.h
 *
 *  Created on: 11-May-2019
 *      Author: kpit
 */

#ifndef INTERMEDIATE_H_
#define INTERMEDIATE_H_

#include "MediaFactory.h"

namespace MediaIndexer {

class Intermediate {
 private:
  MediaFactory* ptrMediaFactory;

 public:
  Intermediate();

  MediaFactory* getMedia();

  ~Intermediate();
};
}
#endif /* INTERMEDIATE_H_ */
