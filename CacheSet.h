#ifndef CACHEBLOCK_H
#define CACHEBLOCK_H

struct CacheBlock{
	//bool m_dirty;
	bool m_valid;
	unsigned long m_tag;

};

class CacheSet{
	public:
		CacheBlock();
		CacheBlock(const int& assoc);
		
		CacheSet *find(const unsigned long m_tag);

	private: 
		CacheBlocks blocks[];
};

#endif
