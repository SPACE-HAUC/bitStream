// Copyright 2017 UMass Lowell SpaceHauc C&DH
#ifndef INCLUDE_BITSTREAM_H_
#define INCLUDE_BITSTREAM_H_

#include <iostream>
#include <vector>

class bitStream {
 public:
  int getBit(int index) const;
  void resize(int newSize);
  void randomizeBitStream(int newSize);
  friend std::ostream& operator << (std::ostream& os, const bitStream stream);
  unsigned randSeed;

  inline void flipBit(int index) {
    stream[index / sizeOfInt] ^= (1 << index % sizeOfInt);
  }

  inline void setSeed() {randSeed = time(nullptr);}

 protected:
  std::vector<int> stream;
  unsigned sizeOfStream;
  static const unsigned sizeOfInt;
};

class scrambler: public bitStream {
 public:
  void scramble(int rate);
};

#endif  // INCLUDE_BITSTREAM_H_
