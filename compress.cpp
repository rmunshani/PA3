#include "HCTree.hpp"
#include "BitOutputStream.cpp"
#include "BitInputStream.hpp"
#include "HCNode.hpp"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

<<<<<<< HEAD
int main(int argc, char** argv){
=======
int main(int argc, char* argv[]){
>>>>>>> origin/master

	//check number of input file 
	if(argc != 3){
		cerr << "file entering number is wrong, exit the prgram now" << endl;
		return -1;
	}

	//create a vector that will hold each char's frequency 
<<<<<<< HEAD
	//vector range from 0 to 255, 256 for exclusive boundary

	vector<int> myVector(256,0);
=======
	//0-255 or 0-256?

	vector<int> myVector(255,0);
>>>>>>> origin/master

	//create a HCTree that will build huffman coding data structure
	HCTree myTree;

	//begin to scan the file 
	ifstream in;
<<<<<<< HEAD
	//open the file as binary 
	in.open(argv[1], ios::binary);

	if(!in.is_open()){

		cerr << "the file cannot be opened!" << endl;
		in.clear();
=======
	in.open(argv[1], ios::binary);

	if(!in.is_open()){
		cerr << "the file cannot be opened!" << endl;
>>>>>>> origin/master
		in.close();
		return -1;
	}

<<<<<<< HEAD
	int sum = 0;

	while(1){

		if(!in.good()){
			break;
		}

=======
	//??

	int sum = 0;

	while(!in.eof()){
>>>>>>> origin/master
		int index = in.get();
		myVector[index] = myVector[index] + 1;
		sum ++;
	}

<<<<<<< HEAD
	if(!in.eof()){
		cerr << "the file reader terminate the process ealier than expect" << endl;
		in.clear();
		in.close();
		return -1;
	}

	cout << "The sum is: " << sum << endl;

	in.clear();
	in.close();

	//start to build the tree
	myTree.build(myVector);
}
















=======
	//start to build the tree
	myTree.build(myVector);
}
>>>>>>> origin/master
