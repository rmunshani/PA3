#include "BitInputStream.hpp"
#include "BitInputStream.cpp"
#include "BitOutputStream.hpp"
#include "BitOutputStream.cpp"
#include "HCTree.hpp"
#include "HCTree.cpp"
#include "HCNode.hpp"
#include "HCNode.cpp"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int main(int argc, char** argv){
    ifstream myFile;
    int index;
    myFile.open("justA", ios::binary);
    BitInputStream in(myFile);
    HCTree newTree;
    vector<int> myVector(256,0);
    newTree.build(myVector);
    while(1){
        if(!myFile.good()){
            cout << "Error" <<endl;
            break;
        }
        index = in.readByte();
        myVector[index]++;
    }
    newTree.build(myVector);

}
