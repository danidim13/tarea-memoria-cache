#ifndef MEMORYCACHE_H
#define MEMORYCACHE_H

#include "CacheMemory.cpp"

class CacheMemory{
	public:
		CacheMemory();
		CacheMemory(int, int, int);
		~CacheMemory();
	
	private:
		int block_size;
		int assoc;
		int mem_size;
		
}



#endif
