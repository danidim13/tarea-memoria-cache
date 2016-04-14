#include <sstream>

CacheMemory::CacheMemory(int assoc, int mem_size, int bloq_size){
	//df

}
void CacheMemory::set_block_size(int val){
	if (check_pow2(val))
		block_size = val;
	else 
		std::cout << "Error, block_size not valid" << std::endl;
}

void CacheMemory::set_mem_size(int val){
	if (check_pow2(val))
		mem_size = val;
	else 
		std::cout << "Error, mem_size not valid" << std::endl;
}

void CacheMemory::set_assoc(int val){
	if (check_pow2(val))
		assoc = val;
	else 
		std::cout << "Error, assoc not valid" << std::endl;
}

bool CacheMemory::check_pow2(int val){
	if(val){
		return (x & (x-1)) == 0;
	}
	return false;
}
