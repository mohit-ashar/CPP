#include "Array.hpp"

int main()
{
    std::cout << "# create array1" << std::endl;
	Array<int> arr(3);
	for (size_t i = 0; i < arr.size(); i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
	std::cout << "<-- change array1 value" << std::endl;
	arr[0] = 1;
	arr[1] = 2;
	arr[2] = 3;
	std::cout << "# array1" << std::endl;
	for (size_t i = 0; i < arr.size(); i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
	std::cout << "# array2" << std::endl;
	Array<int> arr2 = arr;
	for (size_t i = 0; i < arr.size(); i++)
		std::cout << arr2[i] << " ";
	std::cout << std::endl;

	std::cout << "<-- change array2 value" << std::endl;
	arr2[0] = 100;
	arr2[1] = 200;
	arr2[2] = 300;

	std::cout << "# array1" << std::endl;
	for (size_t i = 0; i < arr.size(); i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
	std::cout << "# array2" << std::endl;
	for (size_t i = 0; i < arr.size(); i++)
		std::cout << arr2[i] << " ";
	std::cout << std::endl;

	return 0;
}