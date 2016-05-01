#ifndef CACHESET_H
#define CACHESET_H

struct Block{
	Block():m_valid(false),m_tag(0){};

	//bool m_dirty;
	bool m_valid;
	unsigned long m_tag;

};

class CacheSet{
	public:
		CacheSet();
		CacheSet(const int assoc);
		~CacheSet();

		typedef unsigned long dir_t;
		const int block_num;
		
		
		// Busca un bloque con el tag, si lo encuentra
		// devuelve true, de lo contrario devuelve false
		// y lo agrega en la posicion blocks[fifo]
		bool fetch(dir_t tag);
		void print();
		
	private: 
		Block *blocks;
		int fifo;

		// Busca un bloque con el tag, devuelve
		// un puntero vacío si no encuentra
		Block *find(dir_t tag);
};

#endif
