#ifndef BITINPUTSTREAM_HPP
#define BITINPUTSTREAM_HPP

#include <iostream>

using namespace std;

class BitInputStream {
private:
    istream& in;  // use istream to composite  bit stream
    char buf;     // the buffer of bits
    int buf_index;     // index to access buf

    //fill the bit when reach 8

    char bitVal(char b, int n){
      char c;
      c=b>>(n-1) & 1;
      return c;
    }

public:
  // constructor
  BitInputStream(istream& s) : in(s), buf(0), buf_index(8) { }
  void fill();
  // read next bit
  int readBit();

  // read next byte, used for decoding header
  int readByte();

  // read next int, used for decoding header
  int readInt();

};


#endif
