/*
 * UnorderedMap.h
 *
 *  Created on: 10-May-2019
 *      Author: kpit
 */

#ifndef UNORDEREDMAP_H_
#define UNORDEREDMAP_H_

#include <algorithm>
#include <unordered_map>

#include "MediaFactory.h"
#include "Song.h"

namespace MediaIndexer {

class UnorderedMap : public MediaFactory {
 private:
  std::unordered_map<int, Song> unorderedMap;

 public:
  UnorderedMap();
  int addMediaToConatiner(const Song& song);
  int deleteMediaFromConatiner(int idOfMedia);
  int findMediaInConatiner(int idOfMedia);
  int countOfMediaInConatiner();
  void displayMediaFromConatiner();

  ~UnorderedMap();

  std::unordered_map<int, Song>& getUnorderedMap() const;
};
}
#endif /* UNORDEREDMAP_H_ */
