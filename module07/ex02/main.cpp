#include "Array.hpp"

int main()
{
    std::cout << "# create array1" << std::endl;
	Array<int> arr(3);
	for (size_t i = 0; i < arr.size(); i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;

	std::cout << "\n<-- change array1 value" << std::endl;
	arr[0] = 1;
	arr[1] = 2;
	arr[2] = 3;

	std::cout << "\n# array1" << std::endl;
	for (size_t i = 0; i < arr.size(); i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;

	std::cout << "\n# Copy by assignment for array2 and Copy constructor for array3" << std::endl;
	
	std::cout << "\n# array2" << std::endl;
	Array<int> arr2 = arr;
	for (size_t i = 0; i < arr2.size(); i++)
		std::cout << arr2[i] << " ";
	std::cout << std::endl;

	std::cout << "\n# array3" << std::endl;
	Array<int> arr3(arr);
	for (size_t i = 0; i < arr3.size(); i++)
		std::cout << arr3[i] << " ";
	std::cout << std::endl;

	std::cout << "\n<-- change array2 and array3 value for assignment test and copy test respectively" << std::endl;
	arr2[0] = 100;
	arr2[1] = 200;
	arr2[2] = 300;

	arr3[0] = 101;
	arr3[1] = 202;
	arr3[2] = 303;

	std::cout << "\n# array1" << std::endl;
	for (size_t i = 0; i < arr.size(); i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;

	std::cout << "\n# array2" << std::endl;
	for (size_t i = 0; i < arr2.size(); i++)
		std::cout << arr2[i] << " ";
	std::cout << std::endl;

	std::cout << "\n# array3" << std::endl;
	for (size_t i = 0; i < arr3.size(); i++)
		std::cout << arr3[i] << " ";
	std::cout << std::endl;
	
	std::cout << "\n# out of range array access" << std::endl;
	
	try
	{
		arr[5] = 10;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		arr[-1] = 10;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n# empty array \nAccess 1st element of empty array" << std::endl;
	try
	{
		Array<int> emp;
		emp[0] = 10;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n# Float array sample" << std::endl;

	Array<float> arrf(3);
	arrf[0] = 1.1f;
	arrf[1] = 1.2f;
	arrf[2] = 1.3f;
	for (size_t i = 0; i < arrf.size(); i++)
		std::cout << arrf[i] << " ";
	std::cout << std::endl;

	std::cout << "\n# Double array sample" << std::endl;

	Array<double> arrd(3);
	arrd[0] = 1.1;
	arrd[1] = 1.2;
	arrd[2] = 1.3;
	for (size_t i = 0; i < arrd.size(); i++)
		std::cout << arrd[i] << " ";
	std::cout << std::endl;

	std::cout << "\n# Char array sample" << std::endl;

	Array<char> arrc(3);
	arrc[0] = '*';
	arrc[1] = '$';
	arrc[2] = '@';
	for (size_t i = 0; i < arrc.size(); i++)
		std::cout << arrc[i] << " ";
	std::cout << std::endl;

	std::cout << "\n# String array sample" << std::endl;

	Array<std::string> arrs(3);
	arrs[0] = "*Welcome to 42*";
	arrs[1] = "*You are Born2Code";
	arrs[2] = "*****************";
	for (size_t i = 0; i < arrs.size(); i++)
		std::cout << arrs[i] << "\n";
	std::cout << std::endl;

	return 0;
}