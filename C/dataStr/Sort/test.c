#include<stdio.h>
#include"Sort.h"
	
extern int A[];	
int main()
{	printf("初始序列：\n");
	PrintArray(A);
	printf("直接插入排序：\n");
	DirectInsertionSort(A);
	printf("冒泡排序：\n");
	BubbleSort(A);
	return 0;
}