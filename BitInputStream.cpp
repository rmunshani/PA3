#include "BitInputStream.hpp"

using namespace std;

int BitInputStream::readBit(){

<<<<<<< HEAD
	if(!in.good()){
		cerr << "error occur when read bit from the file" << endl;
=======
	if(in.eof()){ //use good or eof? 
		cout << "reach end of file" << endl;
		return -1;
	}

	if(!in.good()){
		cout << "error occur when read bit from the file" << endl;
>>>>>>> origin/master
		return -1;
	}

	if(buf_index == 8){
		fill();
	}

	int toReturn = ((buf>>(7 - buf_index)) & 1);
	buf_index ++;
	return toReturn;
}

int BitInputStream::readByte(){

	if(!in.good()){
<<<<<<< HEAD
		cerr << "error occur when read bit from the file" << endl;
=======
		cout << "error occur when read bit from the file" << endl;
>>>>>>> origin/master
		return -1;
	}

	return in.get();
}

int BitInputStream::readInt(){

	if(!in.good()){
		cerr << "error occur when read bit from the file" << endl;
		return -1;
	}

	int placeHolder;
	in.read((char*) &placeHolder, sizeof(int));
	
}
