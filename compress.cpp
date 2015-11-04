#include "HCTree.hpp"
#include "BitOutputStream.cpp"
#include "BitInputStream.hpp"
#include "HCNode.hpp"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, char* argv[]){

	//check number of input file 
	if(argc != 3){
		cerr << "file entering number is wrong, exit the prgram now" << endl;
		return -1;
	}

	//create a vector that will hold each char's frequency 
	//0-255 or 0-256?

	vector<int> myVector(255,0);

	//create a HCTree that will build huffman coding data structure
	HCTree myTree;

	//begin to scan the file 
	ifstream in;
	in.open(argv[1], ios::binary);

	if(!in.is_open()){
		cerr << "the file cannot be opened!" << endl;
		in.close();
		return -1;
	}

	//??

	int sum = 0;

	while(!in.eof()){
		int index = in.get();
		myVector[index] = myVector[index] + 1;
		sum ++;
	}

	//start to build the tree
	myTree.build(myVector);
}