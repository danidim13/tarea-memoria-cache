#ifndef CACHEMEMORY_H
#define CACHEMEMORY_H

//#include "CacheMemory.cpp"
#include <map>
// #include "CacheBlock.h"

class CacheMemory{
	public:
		CacheMemory();
		CacheMemory(int &v_assoc, int &v_mem_size, int &v_block_size);
		~CacheMemory();
		void set_block_size(const int&);
		void set_assoc(const int&);
		void set_mem_size(const int&);
		const void print();

		// Tipo de datos para las direcciones de memoria.
		typedef unsigned long dir_t; 


		/* La estrutura de datos para las posiciones de memoria del cache sera
		   un std::map, tal que el key es el index y el dato contiene el bloque
		   incluido en esto el tag, bit de dirty, bit de valid, y la 
		   Asi, el tipo de datos sera un std::map< dir_t, CacheBlock >
		*/ 
		// std::map< dir_t, CacheBlock > cache_struct;

		bool read(const dir_t&);
		bool write(const dir_t&);
	private:
		int block_size;
		int assoc;
		int mem_size;

		int tag_size;
		int index_size;
		int offset_size;
		int block_num;
		int set_num;

		// Tamano de las direcciones de memoria
		const static int DIR_SIZE = 32;

		void initialize();
		const bool check_pow2(const int&);
		void set_tag();
		bool fetch(const dir_t&);
};



#endif
