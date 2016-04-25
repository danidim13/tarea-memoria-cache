#ifndef CACHEMEMORY_H
#define CACHEMEMORY_H


class CacheMemory{
	public:
		CacheMemory();
		CacheMemory(const int &v_assoc, const int &v_mem_size, const int &v_block_size);
		~CacheMemory();
		void set_block_size(const int&);
		void set_assoc(const int&);
		void set_mem_size(const int&);
		const void print();

		typedef unsigned long dir_t;
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

		const static int DIR_SIZE = 32;

		void initialize();
		const bool check_pow2(const int&);
		void set_tag();
		bool fetch(const dir_t&);
};



#endif
