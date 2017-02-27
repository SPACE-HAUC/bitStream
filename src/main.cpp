// Copyright 2017 UMass Lowell SpaceHauc C&DH Team

#include <iostream>
#include <cstdlib>

#include "bitStream.h"

int main(int argc, char const *argv[]) {
    bitStream test(30);
    //test.generateNewStream(30);
    test.printStream();
    test.generateNewStream();
    test.printStream();
    test.scramble();
    test.printStream();
    return 0;
}
