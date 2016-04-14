#ifndef MEMORYCACHE_H
#define MEMORYCACHE_H

#include "CacheMemory.cpp"

class CacheMemory{
	public:
		CacheMemory();
		CacheMemory(int, int, int);
		~CacheMemory();
		void set_block_size(int);
		void set_assoc(int);
		void set_mem_size(int);

	private:
		int block_size;
		int assoc;
		int mem_size;


		bool check_pow2(int);
}



#endif
