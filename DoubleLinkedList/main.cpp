
#include <iostream>
#include "List.h"

int main()
{
	List<int> list = { 1,2,2,2,2};

	list.remove(2);
	
	
	


	
	for (int value : list) {
		std::cout << value << std::endl;
	}
	




}
