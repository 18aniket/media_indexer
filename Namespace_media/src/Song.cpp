/*
 * Song.cpp
 *
 *  Created on: 22-Apr-2019
 *      Author: kpit
 */

#include "Song.h"

#include <iostream>

Song::Song(int idOfSong, std::string fileName, std::string fileFormat,
		std::string filePath, double fileInode, double fileSize)
: idOfSong(idOfSong),
  fileName(fileName),
  fileFormat(fileFormat),
  filePath(filePath),
  fileInode(fileInode),
  fileSize(fileSize) {}

std::ostream& operator<<(std::ostream& out, const Song& other) {
	out << "file name: " << other.getFileName() << "\n";
	out << "file format: " << other.getFileFormat() << "\n";
	out << "file path: " << other.getFilePath() << "\n";
	out << "file size: " << other.getFileSize() << " mb"
			<< "\n";
	return out;
}

const std::string& Song::getFileFormat() const { return fileFormat; }

double Song::getFileInode() const { return fileInode; }

const std::string& Song::getFileName() const { return fileName; }

const std::string& Song::getFilePath() const { return filePath; }

double Song::getFileSize() const { return fileSize; }

int Song::getIdOfSong() const { return idOfSong; }

