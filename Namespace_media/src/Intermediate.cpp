/*
 * Intermediate.cpp
 *
 *  Created on: 11-May-2019
 *      Author: kpit
 */

#include "Intermediate.h"
#include "UnorderedMap.h"

using namespace MediaIndexer;

/**
 *@brief:Making the object of storage class
 *@return:pointer to that storage class
 */
MediaFactory* Intermediate::getMedia() {
	ptrMediaFactory = new UnorderedMap();
	return ptrMediaFactory;
}

/**
 *@brief:default constructor
 */
Intermediate::Intermediate() { ptrMediaFactory = nullptr; }

Intermediate::~Intermediate() {}

