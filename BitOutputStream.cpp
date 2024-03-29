#include "BitOutputStream.hpp"
#include <iostream>

using namespace std;

void BitOutputStream::writeBit(int bit){

	//satisfied flush condition
	if(buf_index == 8){
		flush();
	}

	//call helper
	buf = setBit(buf,bit,buf_index+1);
	//cout << buf << endl;
	buf_index ++;
}

void BitOutputStream::flush(){

	if(!out.good()){
		cerr << "error occur when read bit from the file" << endl;
		//return ;
	}

	out.put(buf);
	//out.flush();
	buf_index = 0;
	buf = 0;
}

void BitOutputStream::writeByte(int i){

	out.put(i);
}

void BitOutputStream::writeInt(int i){

	//must cast the pointer to char in order to obey the api
	out.write((char*)&i, sizeof(int));
}
