#include "CacheSet.h"
#include <iostream>

CacheSet::CacheSet(): block_num(0), fifo(0), blocks(0){

}

CacheSet::CacheSet(const int assoc):block_num(assoc), fifo(0){
	blocks = new Block[assoc];
}

CacheSet::~CacheSet(){
	delete blocks;
}

Block* CacheSet::find(dir_t tag){
	for(int i=0; i < block_num; i++){
		if(blocks[i].m_valid && blocks[i].m_tag == tag)
			return blocks + i;
	}
	return 0;
}

bool CacheSet::fetch(dir_t tag){
	Block *p = find(tag);
	if(p){
		return true;
	}
	else{
		blocks[fifo].m_valid = true;
		blocks[fifo].m_tag = tag;
		fifo = (fifo + 1)%block_num;
		return false;
	}
}

void CacheSet::print(){
	std::cout << "\n";
	for(int i=0; i < block_num; i++){
		std::cout << i << ": ";
		if(blocks[i].m_valid){
			std::cout << "valid, tag: " << blocks[i].m_tag;
		}
		else{
			std::cout << "invalid";
		}
		std::cout << "\n";
	}
	std::cout << std::endl;
		
}
