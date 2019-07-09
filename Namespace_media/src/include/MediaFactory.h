/*
 * MediaFactory.h
 *
 *  Created on: 10-May-2019
 *      Author: kpit
 */

#ifndef MEDIAFACTORY_H_
#define MEDIAFACTORY_H_
#include "Song.h"

namespace MediaIndexer {
class MediaFactory {
 public:
  MediaFactory();

  virtual int addMediaToConatiner(const Song &song) = 0;
  virtual int deleteMediaFromConatiner(int idOfMedia) = 0;
  virtual int findMediaInConatiner(int idOfMedia) = 0;
  virtual int countOfMediaInConatiner() = 0;
  virtual void displayMediaFromConatiner() = 0;

  virtual ~MediaFactory();
};
}
#endif /* MEDIAFACTORY_H_ */
