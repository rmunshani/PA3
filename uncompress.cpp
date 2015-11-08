#include "HCTree.hpp"
#include "BitOutputStream.hpp"
#include "BitInputStream.hpp"
#include "HCNode.hpp"
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

	ifstream in;
	//open the file as binary
	in.open(argv[1], ios::binary);
	//declare a bitInput
	BitInputStream bitInput(in);

	if(!in.is_open()){
		//handle the case when the file cannot be opened
		cerr << "the input file cannot be opened!" << endl;
		in.clear();
		in.close();
		return -1;
	}

	unsigned int i = 0;
	unsigned int temp = 0;
	unsigned int sum = 0;
	unsigned int count;
	while(i < myVector.size()){
		temp = bitInput.readInt();
		myVector[i] = temp;
		cout << temp << " " << count << endl;
		sum = sum + temp;
		i++;
		count++;
	}
	//bitInput.readByte();
	cout << "the total number of char in the input file is " << sum << endl;

	ofstream out;
	//open the file as binary
	out.open(argv[2], ios::binary);
	//declare a bitInput
	BitOutputStream bitOutput(out);

	if(!out.is_open()){
		cerr << "the output file cannot be opened!" << endl;
		out.clear();
		out.close();
		return -1;
	}

	//initialize a tree on stack
	HCTree myTree;
	//start to build the tree
	myTree.build(myVector);

	int ch;
	int T = sum;
	while(sum > 0){
		ch = myTree.decode(bitInput);  // the number in ACSII table
		cout << ch << endl;
		bitOutput.writeByte(ch);
		sum--;
	}
	bitInput.fill();
	//flush to make sure nothing in buffer any more
	//bitOutput.flush();
	if(!in.eof()){
		cerr << "hey dude the file reader terminate the process ealier than expect" << endl;
		in.clear();
		in.close();
		return -1;
	}

	double resultsize = out.tellp();
	double ratio = resultsize/T;
	cout << "the uncompress ratio is " << ratio << endl;

	out.clear();
	out.close();

	in.clear();
	in.close();

	return 1;
}
