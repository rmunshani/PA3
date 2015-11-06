#include "BitInputStream.hpp"

using namespace std;

void BitInputStream::fill(){
	buf = in.get();
	buf_index = 0;
	//buf =0;
}

int BitInputStream::readBit(){

	if(buf_index == 8){
		fill();
	}

	int toReturn = bitVal(buf,buf_index + 1);
	buf_index ++;


	return toReturn;
}

int BitInputStream::readByte(){

	return in.get();
}

int BitInputStream::readInt(){

	int placeHolder;
	in.read((char*) &placeHolder, sizeof(int));
	return placeHolder;

}
