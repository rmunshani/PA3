#include "HCNode.hpp"

	bool HCNode::operator<(const HCNode& other){
		if(count == other.count){
			return symbol < other.symbol;
		}
		else{
			return count < other.count;
		}
	}

	//bool HCNode::comp(HCNode* one, HCNode* other){
  	//	return (*one) < (*other);
    //}

