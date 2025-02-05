
#include <iostream>
#include "List.h"

int main()
{
	List<int> list = { 3 ,6 ,6 ,6 ,3 };

	list.remove(6);

	
	list.insert(100, 0);
	list.insert(100, 2);
	

	list.remove(100);



	for (int value : list) {
		std::cout << value << std::endl;
	}




}
