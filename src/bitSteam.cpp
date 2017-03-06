// Copyright 2017 UMass Lowell SpaceHauc C&DH

#include <iostream>
#include <ctime>
#include <exception>
#include <stdexcept>

#include "bitStream.h"

void bitStream::resize(int newSize) {
  stream.resize(((newSize) / sizeOfInt) + 1);
  sizeOfStream = newSize;
}

int bitStream::getBit(int index) const {
  unsigned x = 1 << index % sizeOfInt;
  return (x & stream[index / sizeOfInt]) ? 1 : 0;
}

void bitStream::randomizeBitStream(int newSize) {
  resize(newSize);
  for (int i = 0; i < newSize; i++) {
    if ((rand_r(&randSeed) % 2) == 0) {
      flipBit(i);
    }
  }
}

std::ostream& operator << (std::ostream& os, const bitStream stream) {
  for (unsigned i = 0; i < stream.sizeOfStream; i++) {
    std::cout << stream.getBit(i) << " ";
  }
  return os;
}

const unsigned bitStream::sizeOfInt = (8 * sizeof(int));

void scrambler::scramble(int rate) {
  if (rate < 0) {
    throw std::out_of_range("rate is negative!!!!");
  }
  for (unsigned i = 0; i < sizeOfStream; i++) {
    if ((rand_r(&randSeed)%100) < rate) {
      flipBit(i);
    }
  }
}
