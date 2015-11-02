#include "HCTree.hpp"
<<<<<<< HEAD
#include "BitOutputStream.hpp"
#include <queue>
#include <stack>

=======
#include <queue>
>>>>>>> origin/master
using namespace std;

HCTree::~HCTree(){
	this->deleteAll(root);
}

void HCTree::build(const vector<int>& freqs){

	if(freqs.size() == 0){
		return;
	}

	priority_queue<HCNode*,vector<HCNode*>,HCNodePtrComp> pq;

	unsigned int i = 0;

	while(i < freqs.size() && freqs[i] != 0){
		HCNode* nodePointer = new HCNode(freqs[i],i,0,0,0);
		leaves[i] = nodePointer;
		pq.push(nodePointer);
		i++;
	}

	while(pq.size() > 1){
		HCNode* smallest = pq.top();
		pq.pop();
		HCNode* secondSmall = pq.top();
		pq.pop();
	
		int combinedFreq = smallest->count + secondSmall->count;
		//constructor count(count), symbol(symbol), c0(c0), c1(c1), p(p)
		HCNode* combinedNode = new HCNode(combinedFreq, 0, smallest, secondSmall, 0);
		smallest->p = combinedNode;
		secondSmall->p = combinedNode;
		pq.push(combinedNode);
	}

	//deal with the last element in the queue or the situation where freqs size == 1
	if(pq.size() == 1){
		root = pq.top();
		//pq;
	} 
}

<<<<<<< HEAD

void encode(byte symbol, BitOutputStream& out) const{

	if(root == 0){
		return;
	}

	int trace = symbol;
	HCNode* find = leaves[trace];

	stack <int> myStack;

	while(find->p != 0){
		if(find->p->c0 == find){
			myStack.push(0);
			find = find ->p;
		}
		else if(find->p->c1 == find){
			myStack.push(1);
			find = find->p;
		}
		else{
			cout << "Error occur during encoding" << endl;
		}
	}

	while(!myStack.empty()){
		in.writeBit(myStack.top());
	}
}




void HCTree::encode(byte symbol, ofstream& out) const{

	if(root == 0){
		return;
	}

	int trace = symbol;
	HCNode* find = leaves[trace];

	stack <int> myStack;

	while(find->p != 0){
		if(find->p->c0 == find){
			myStack.push(0);
			find = find ->p;
		}
		else if(find->p->c1 == find){
			myStack.push(1);
			find = find->p;
		}
		else{
			cout << "Error occur during encoding" << endl;
		}
	}
	
	while(!myStack.empty()){
		in.writeBit(myStack.top());
	}
}

int decode(BitInputStream& in) const{

	HCNode* curr = root;
	//since every parent has two childrens, check only one of them will be enough 
	while(curr->c0 != 0){
		if(in.readBit() == 0){
			curr = curr->c0;
		}
		else{
			curr = curr->c1;
		}
	}

	return (char)curr->symbol;
}

int decode(ifstream& in) const{
	HCNode* curr = root;
	//since every parent has two childrens, check only one of them will be enough 
	while(curr->c0 != 0){
		if(in.readBit() == 0){
			curr = curr->c0;
		}
		else{
			curr = curr->c1;
		}
	}

	return (char)curr->symbol;
}






























=======
void HCTree::encode(byte symbol, BitOutputStream& out) const{

}
>>>>>>> origin/master
