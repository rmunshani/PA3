#include "BitInputStream.hpp"
//using namespace std;

int BitInputStream::readBit(){
	if(in.eof()){ //use good or eof? 
		return -1;
	}

	if(this->buf_index == 8){
		fill();
	}

	int toReturn = ((buf>>(7 - buf_index)) & 1);
	buf_index ++;
	return toReturn;
}

int BitInputStream::readByte(){
	return in.get();
}

int BitInputStream::readInt(){
	int toReturn = 0;
	int first = in.get();
	int second = in.get();
	int third = in.get();
	int fourth = in.get();

	toReturn = first | (second << 8);
	toReturn = toReturn | (third <<16);
	toReturn = toReturn | (fourth << 24);

	return toReturn;
}
