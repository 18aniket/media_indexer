#include "DisplayContainer.h"

using namespace MediaIndexer;

/**
 *default constructor
 */
DisplayContainer::DisplayContainer() { ptrOfMediaFactoryDisplay = nullptr; }

/**
 *purpose of function:get the pointer of mediafactory
 */
void DisplayContainer::recieveMediaFactoryPointer(MediaFactory *ptr) {
	ptrOfMediaFactoryDisplay = ptr;
}

/**
 *@brief:function shows all data from container
 */
void DisplayContainer::displayMedia() {
	ptrOfMediaFactoryDisplay->displayMediaFromConatiner();
}

/**
 *@param:id provided by user
 *@return :0
 */
int DisplayContainer::searchMediaById(int id) {
	ptrOfMediaFactoryDisplay->findMediaInConatiner(id);
	return 0;
}

/**
 *@brief:function that count the available song
 *@return:count of total songs
 */
int DisplayContainer::availableSongsCountInContainer() {
	int count;
	count = ptrOfMediaFactoryDisplay->countOfMediaInConatiner();
	return count;
}

/**
 *@brief:function that delete the object of song by id
 *@param:idofsong given by user
 */
void DisplayContainer::deleteMediaFromContainer(int idOfSong) {
	ptrOfMediaFactoryDisplay->deleteMediaFromConatiner(idOfSong);
}

/**
 *@brief:default destructor
 */
DisplayContainer::~DisplayContainer() { ptrOfMediaFactoryDisplay = nullptr; }

