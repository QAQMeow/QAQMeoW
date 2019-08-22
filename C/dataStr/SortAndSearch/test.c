#include<stdio.h>
#include"SortAndSearch.h"

extern int A[];	

int main()
{	printf("初始序列：\n");
	PrintArray(A);
	printf("直接插入排序：\n");
	DirectInsertionSort(A);
	printf("冒泡排序：\n");
	BubbleSort(A);
	printf("快速排序：\n");
	QuickSort(A);
	return 0;
}