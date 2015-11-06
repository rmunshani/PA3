#include "BitInputStream.hpp"
#include "BitInputStream.cpp"
#include "BitOutputStream.hpp"
#include "BitOutputStream.cpp"
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char** argv){
    ifstream myFile;
    ofstream outFile;
    outFile.open(argv[1], ios::binary);
    BitInputStream in (myFile);
    BitOutputStream out (outFile);
    out.writeBit(0);
    out.writeBit(1);
    out.writeBit(0);
    out.writeBit(1);
    out.writeBit(0);
    out.writeBit(0);
    out.writeBit(1);
    out.writeBit(0);
    out.writeBit(0);
    //out.flush();

    myFile.open("sample.txt", ios::binary);
    cout << in.readBit() << endl;
    cout << in.readBit() << endl;
    cout << in.readBit() << endl;
    cout << in.readBit() << endl;
    cout << in.readBit() << endl;
    cout << in.readBit() << endl;
    cout << in.readBit() << endl;
    cout << in.readBit() << endl;
    cout << in.readBit() << endl;
    

    //cout << myFile.readBit() << endl;


    //outFile.close();
    /*
    myFile.open("input.txt", ios::binary);
    BitInputStream in(myFile);
    //cout << in.readBit();
    while(1){
        if(!myFile.good()){
            cout << "Error" <<endl;
            break;
        }
        for(int i = 0; i < 8; i++){
            cout<< in.readBit();
        }
        cout <<""<<endl;

    }*/
    return 0;
}
