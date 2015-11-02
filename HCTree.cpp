#include "HCTree.hpp"
#include <queue>
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

void HCTree::encode(byte symbol, BitOutputStream& out) const{

}