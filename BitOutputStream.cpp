#include "BitOutputStream.hpp"

void BitOutputStream::writeBit(int bit){
	if(buf_index == 8){
		flush();
	}

	this->buf = this->buf | (bit << (7 - buf_index));
	buf_index ++;
}

void BitOutputStream::flush(){
	out.put(buf);
	buf_index = 0;
	//buf = 0; ???
}

void BitOutputStream::writeByte(int i){
	out.put(i);
}

void BitOutputStream::writeInt(int i){
	out.write((char*)&i, sizeof(int));
}


