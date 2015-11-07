#include "HCTree.hpp"
#include "BitOutputStream.hpp"
#include "BitInputStream.hpp"
#include <queue>
#include <stack>

using namespace std;

HCTree::~HCTree(){
	deleteAll(root);
}

void HCTree::build(const vector<int>& freqs){

	priority_queue<HCNode*,vector<HCNode*>,HCNodePtrComp> pq;

	unsigned int i = 0;
	int single = 0;

	while(i < freqs.size()){
		if(freqs[i] != 0){
			HCNode* nodePointer = new HCNode(freqs[i],i,0,0,0);
			leaves[i] = nodePointer;
			pq.push(nodePointer);
			single++;
		}
		i++;
	}

	if(single == 1){//corner case when there is only one node except the root
		cout << "Entered" << endl;
		HCNode* myPointer = pq.top();
		root = new HCNode(myPointer->count,0,myPointer,0,0);
		cout << root -> count << endl;
		myPointer ->p = root;
		pq.pop();
	}


	while(pq.size() > 1){
		HCNode* smallest = pq.top();
		//cout << smallest->symbol << endl;
		pq.pop();

		HCNode* secondSmall = pq.top();
		//cout << secondSmall->symbol << endl;
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
		cout << root->symbol << endl;
		//pq;
	}
}


void HCTree::encode(byte symbol, BitOutputStream& out) const{

	if(root == 0){
		return;
	}

	int trace = symbol;
	HCNode* find = this->leaves[trace];

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
		out.writeBit(myStack.top());
		myStack.pop();
	}
	//out.flush();
}

void HCTree::encode(byte symbol, ofstream& out) const{

	BitOutputStream temp(out);

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
		temp.writeBit(myStack.top());
	}
}

int HCTree::decode(BitInputStream& in) const{
	//cout << "entered" << endl;
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
	//in.fill();
	cout << (int)curr->symbol << endl;
	cout << curr->symbol << endl;
	return (int)curr->symbol;
}

int HCTree::decode(ifstream& in) const{

	BitInputStream temp (in);
	HCNode* curr = root;
	//since every parent has two childrens, check only one of them will be enough
	while(curr->c0 != 0){
		if(temp.readBit() == 0){
			curr = curr->c0;
		}
		else{
			curr = curr->c1;
		}
	}

	return (int)curr->symbol;
}
