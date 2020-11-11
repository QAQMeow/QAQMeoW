#include<iostream>
#include"Sort.h"

int main()
{
	int length = 20;
	int A[20] = { 17,2,1,13,4,5,20,8,7,12,10,11,14,15,18,19,3,16,6,9 };
	std::cout << "初始数列：";
	Meow_Van::showA(A, length);
	int* B = new int[length];

	B = Meow_Van::Shelltsort(A,length);
	std::cout << "排序数列：";
	Meow_Van::showA(B,length);
	return 0;
}