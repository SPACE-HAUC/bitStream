// Copyright 2017 UMass Lowell SpaceHauc C&DH

#include <iostream>
#include <vector>
#include <exception>
#include <stdexcept>

#include "bitStream.h"

int main(int argc, char const *argv[]) {
  scrambler test;
  test.setSeed();
  test.randomizeBitStream(16);
  std::cout << test << std::endl;
  std::cout << "scrambling!!" << std::endl;
  test.scramble(30);
  std::cout << test << std::endl;
  return 0;
}
