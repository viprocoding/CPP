#include "array.h"
#include <iostream>

#define N 10

int main(void)
{
	raos::array<int> a(N);

	for (int i = 0; i < N; i++)
		std::cout << (a[i] = i) << " ";
	std::cout << std::endl;

	return 0;
}
