#ifndef DISPLAYCONTAINER_H_
#define DISPLAYCONTAINER_H_

#include "MediaFactory.h"

#include <cstdlib>

namespace MediaIndexer {

class DisplayContainer {
 private:
  MediaFactory *ptrOfMediaFactoryDisplay;

 public:
  DisplayContainer();

  void recieveMediaFactoryPointer(MediaFactory *ptr);
  void displayMedia();
  int searchMediaById(int);
  int availableSongsCountInContainer();
  void deleteMediaFromContainer(int);

  ~DisplayContainer();
};
}
#endif
