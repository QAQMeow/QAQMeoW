#include<stdio.h>
#include"SortAndSearch.h"

extern int A[];	

int main()
{	printf("初始序列：\n");
	PrintArray(A);
	printf("直接插入排序：\n");
	PrintArray(DirectInsertionSort(A));
	printf("冒泡排序：\n");
	PrintArray( BubbleSort(A));
	printf("快速排序：\n");
	PrintArray(QuickSort(A));
	printf("简单选择排序：\n");
	PrintArray(SimpleSelectionSort(A));
	printf("折半插入排序\n");
	PrintArray(BinaryInsertionSort(A));
	printf("希尔排序\n");
	PrintArray(ShellSort(A));
	printf("顺序查找\n");
	Sortsearch(A,15);
	int*B = SimpleSelectionSort(A);
	printf("折半查找 15 \n");
	printf("先排序\n");
	PrintArray(B);
	int t = BinarySeaerch(B,20,15);
	if(t>=0)
	printf("ARRAY[%d] = 15\n",t);
	else
		printf("无\n");
	return 0;
}