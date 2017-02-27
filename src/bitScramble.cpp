// Copyright 2017 UMass Lowell SpaceHauc C&DH

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

#include "bitStream.h"

using std::cin;
using std::cout;
using std::endl;
using std::streamsize;
using std::numeric_limits;

bitStream::bitStream(int sizeOfNew) {
  seed = new unsigned(time(nullptr));
  generateNewStream(sizeOfNew);
}

bitStream::~bitStream() {
  if (stream != nullptr) {
    delete stream;
  }
  if (seed != nullptr) {
    delete seed;
  }
}

// This function iterates through the bitStream array and randomly flips a few
// of the bits (~25%)
void bitStream::scramble() {
  for (int i = 0; i < sizeOfStream; i++) {
    if ((rand_r(seed) % 5) == 0) {  // the integer in this line controls the
      flipBit(i);                   // percentage of bits flipped 1/i = %
    }
  }
}

// This function prints each number in the array.
void bitStream::printStream() {
  for (int i = 0; i < sizeOfStream; i++) {
    cout << stream[i] << " ";
  }
  cout << endl;
}

// This helper function takes the index of a bit and flips the bit at that index
void bitStream::flipBit(int indexOfBit) {
  if (stream[indexOfBit] == 0) {
    stream[indexOfBit] = 1;
  } else if (stream[indexOfBit] == 1) {
    stream[indexOfBit] = 0;
  }
}

// This function generates a random stream of bits of the user inputed length.
void bitStream::generateNewStream() {
  if (stream != nullptr) {
    delete stream;  // delete current stream to make room for the new one
  }
  // if (seed != nullptr) {
  //   delete seed;
  // }
  // seed = new unsigned(time(nullptr));
  int sizeOfNew;
  cout << "input the size of the desired bit stream\n";
  getIntInput(&sizeOfNew);
  stream = new int[sizeOfNew];
  sizeOfStream = sizeOfNew;
  for (int i = 0; i < sizeOfStream; i++) {
    stream[i] = rand_r(seed) % 2;
  }
}

// Overloaded version of generateNewStream that takes in the size as a parameter
// instead of from user input
void bitStream::generateNewStream(int sizeOfNew) {
  if (stream != nullptr) {
    delete stream;  // delete current stream to make room for the new one
  }
  // if (seed != nullptr) {
  //   delete seed;
  // }
  // seed = new unsigned(time(nullptr));
  stream = new int[sizeOfNew];
  sizeOfStream = sizeOfNew;
  for (int i = 0; i < sizeOfStream; i++) {
    stream[i] = rand_r(seed) % 2;
  }
}

// Function that securely gets integer input.
bool getIntInput(int *inputVar) {
  while (!(cin >> *inputVar)) {
    cout << "that input is invalid" << endl;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
  }
  return true;
}
