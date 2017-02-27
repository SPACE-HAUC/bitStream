// Copyright 2017 UMass Lowell SpaceHauc C&DH

#ifndef INCLUDE_BITSTREAM_H_
#define INCLUDE_BITSTREAM_H_

#include <ctime>

bool getIntInput(int *inputVar);

class bitStream {
 public:
  bitStream() { seed = new unsigned(time(nullptr));}  // default constructor
  explicit bitStream(int sizeOfNew);
  ~bitStream();
  void scramble();
  void printStream();
  void generateNewStream();
  void generateNewStream(int sizeOfNew);

 private:
  int *stream;
  int sizeOfStream;
  unsigned int* seed;
  void flipBit(int indexOfBit);
};

#endif  // INCLUDE_BITSTREAM_H_
