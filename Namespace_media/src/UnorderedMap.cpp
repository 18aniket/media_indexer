/*
 *@brief:
 * UnorderedMap.cpp
 *
 *  Created on: 10-May-2019
 *      Author: kpit
 */
#include "UnorderedMap.h"

#include <iterator>

using namespace MediaIndexer;

UnorderedMap::UnorderedMap() {}

/*
 *@brief:
 *It will add Songs in UnorderedMap<int, Song>

 */
int UnorderedMap::addMediaToConatiner(const Song &song) {
	UnorderedMap::unorderedMap.emplace(
			std::pair<int, Song>(song.getIdOfSong(), song));
	return 0;
}

/*
 *@brief:
 *For Iterating in Map
 */
void UnorderedMap::displayMediaFromConatiner() {
	for (std::unordered_map<int, Song>::iterator it =
			UnorderedMap::unorderedMap.begin();
			it != UnorderedMap::unorderedMap.end(); ++it)
		std::cout << " " << it->first << " " << it->second << " "
		<< "\n";
}

/*
 *@brief:
 *For finding Song in Container
 *Id of Song is given by User
 */
int UnorderedMap::findMediaInConatiner(int idOfMedia) {
	std::unordered_map<int, Song>::iterator itr = unorderedMap.find(idOfMedia);
	if (itr == unorderedMap.end())
		std::cout << "Please enter in Range(Invalid Entry)"
		<< "\n";  // unordered_map::end if the specified key is
	// not found in the container.
	else
		std::cout << itr->first << " " << itr->second;
	return 0;
}

/*
 *@brief:
 *For Deleting the Media
 *Exception : none
 *(iterator erase(const_iterator pos);
 */
int UnorderedMap::deleteMediaFromConatiner(int idOfMedia) {
	unorderedMap.erase(idOfMedia);  // iterator erase(const_iterator pos);
	return 0;                       // Exception
	//(none)
}

/*
 *@brief:
 *For Counting the Number of Songs
 *Return Type : int
 *returns the Number of Songs in Container
 */
int UnorderedMap::countOfMediaInConatiner() { return unorderedMap.size(); }

UnorderedMap::~UnorderedMap() {}

