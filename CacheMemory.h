#ifndef CACHEMEMORY_H
#define CACHEMEMORY_H
#include "CacheSet.h"
#include <vector>

class CacheMemory{
	public:
		CacheMemory();
		CacheMemory(const int &v_assoc, const int &v_mem_size, const int &v_block_size);
		~CacheMemory();
		void set_block_size(const int&);
		void set_assoc(const int&);
		void set_mem_size(const int&);
		const void print();

		// Tipo de datos para las direcciones de memoria.
		typedef unsigned long dir_t;

		bool fetch(const dir_t&);
		/* La estrutura de datos para las posiciones de memoria del cache sera
		   un arreglo de los sets, tal que el index del array es el mismo que el del set
		   Luego cada set consiste en n cantidad de bloques de cache, cada uno incluye
		   el respectivo tag, bit de dirty, bit de valid,
		   Asi, el tipo de datos sera un std::array< CacheSet >

		*/
		std::vector< CacheSet > set_vec;

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

		dir_t address;
		dir_t tag;
		dir_t index;
		dir_t tag_and_index;
		dir_t my_mask;

		// Tamano de las direcciones de memoria
		const static int DIR_SIZE = 32;

		void initialize();
		const bool check_pow2(const int&);
		void set_tag();
};



#endif
