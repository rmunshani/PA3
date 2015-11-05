#include "HCTree.hpp"
#include "HCTree.cpp"
#include "BitOutputStream.cpp"
#include "BitOutputStream.hpp"
#include "BitInputStream.hpp"
#include "BitInputStream.cpp"
#include "HCNode.hpp"
#include "HCNode.cpp"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, char** argv){

	//check number of input file 
	if(argc != 3){
		cerr << "file entering number is wrong, exit the prgram now" << endl;
		return -1;
	}

	//create a vector that will hold each char's frequency 
	//vector range from 0 to 255, 256 for exclusive boundary
	vector<int> myVector(256,0);

	//create a HCTree that will build huffman coding data structure
	HCTree myTree;

	//begin to scan the file 
	ifstream in;
	//open the file as binary 
	in.open(argv[1], ios::binary);
	//declare a bitInput
	BitInputStream bitInput(in);

	if(!in.is_open()){

		cerr << "the input file cannot be opened!" << endl;
		in.clear();
		in.close();
		return -1;
	}

	int sum = 0;
	int index = 0;


	while(1){

		if(in.eof()){
			break;
		}

		if(!in.good()){
			break;
		}

		//index = bitInput.readByte();

		if((index = bitInput.readByte()) == EOF){
			break;
		}

		myVector[index] = myVector[index] + 1;
		sum++;
		
	}

	if(!in.eof()){
		cerr << "the file reader terminate the process ealier than expect" << endl;
		in.clear();
		in.close();
		return -1;
	}

	cout << "The sum is: " << sum << endl;


	//start to build the tree
	myTree.build(myVector);

	//initialize the ofstream
	ofstream out;
	//open the output file
	out.open(argv[2], ios::binary);
	//initialize bitoutputstream
	BitOutputStream bitOutput(out);


	if(!out.is_open()){

		cerr << "the output file cannot be opened!" << endl;
		out.clear();
		out.close();
		return -1;
	}

	unsigned int writeIndex = 0;

	while(writeIndex < myVector.size()){

		if(!out.good()){
			break;
		}

		if(myVector[writeIndex]!=0){
			bitOutput.writeInt(myVector[writeIndex]);
		}

		writeIndex ++;

	}

	//reset get pointer to the begining of the file
	in.seekg(0,ios::beg);
	cout << in << endl;

	while(1){

		if(!in.good()){
			cout << "end reading file" << endl;
			break;
		}

		char temp = bitInput.readByte();
		
		myTree.encode(temp,bitOutput);
	}

	bitOutput.flush();

	out.clear();
	out.close();

	in.clear();
	in.close();

}
















