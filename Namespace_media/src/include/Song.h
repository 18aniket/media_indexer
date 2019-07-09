/*
 * Song.h
 *
 *  Created on: 22-Apr-2019
 *      Author: kpit
 */

#ifndef SONG_H_
#define SONG_H_

#include <iostream>
#include <ostream>
#include <string>

class Song {
 private:
  int idOfSong;
  std::string fileName;
  std::string fileFormat;
  std::string filePath;
  double fileInode;
  double fileSize;

 public:
  Song(int idOfSong, std::string fileName, std::string fileFormat,
       std::string filePath, double fileInode, double fileSize);

  void show();

  const std::string& getFileFormat() const;

  double getFileInode() const;

  const std::string& getFileName() const;

  const std::string& getFilePath() const;

  double getFileSize() const;

  int getIdOfSong() const;
};

std::ostream& operator<<(std::ostream& out, const Song& other);

#endif /* SONG_H_ */
