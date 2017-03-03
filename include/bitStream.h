// Copyright 2017 UMass Lowell SpaceHauc C&DH

#ifndef INCLUDE_BITSTREAM_H_
#define INCLUDE_BITSTREAM_H_

#include <ctime>
#include <vector>

bool getIntInput(int *inputVar);

class bitStream {
 public:
  bitStream() { seed = new unsigned(time(nullptr));}  // default constructor
  explicit bitStream(int sizeOfNew);
  ~bitStream();
  void scramble();
  void printStream();
  void setStream(int input[]);

  void generateNewStream();
  void generateNewStream(int sizeOfNew);

 private:
  std::vector<int> stream;
  unsigned int* seed;

  void flipBit(int indexOfBit);
};

class parity: public bitStream {
  void appendEvenParityBit();
  bool checkEvenParity();



 private:
  bool parityBit;
};

#endif  // INCLUDE_BITSTREAM_H_
