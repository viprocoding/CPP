#include "array.h"
#include <iostream>

int main(void)
{
	raos::array<int> a(10);
	for (int i = 0; i < 10; i++)
		a[i] = i;
	
	for (int i = 0; i < 10; i++)
		std::cout << a[i] << " ";
	std::cout << std::endl;
	
	a = a * a;

	for (int i = 0; i < 10; i++)
		std::cout << a[i] << " ";
	std::cout << std::endl;

	
	for (int i = 0; i < 10; i++)
		a[i] = i;
	
	a *= a;

	for (int i = 0; i < 10; i++)
		std::cout << a[i] << " ";
	std::cout << std::endl;

	return 0;
}
