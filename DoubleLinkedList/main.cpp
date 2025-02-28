
#include <iostream>
#include "List.h"
#include "ObjectPool.h"

int main()
{
	List<int> list = { 1,2,2,2,2};

	list.remove(2);
	
	
	


	
	for (int value : list) {
		std::cout << value << std::endl;
	}
	

	ObjectPool<int*> objectPool = ObjectPool<int*>(100, []() {return new int; });
	std::cout << objectPool.CountAll();
	std::cout << objectPool.CountInactive();

}
