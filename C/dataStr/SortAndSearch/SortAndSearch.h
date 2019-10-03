#include<stdio.h>


//直接插入排序
int* DirectInsertionSort(int ARRAY[]);

//折半插入排序
int* BinaryInsertionSort(int ARRAY[]);

//希尔排序
int* ShellSort(int ARRAY[]);

//冒泡排序
int* BubbleSort(int ARRAY[]);

//快速排序
int* QuickSort(int ARRAY[]);

//简单选择排序
int* SimpleSelectionSort(int ARRAY[]);

//堆排序
int* HeapSort(int ARRAY[]);

//归并排序
int* MergeSort(int ARRAY[]);

//基数排序
int* RadixSort(int ARRAY[]);

//输出数组
void PrintArray(int ARRAY[]);

void P();

//顺序查找
void Sortsearch(int ARRAY[],int x);

//折半查找
int BinarySeaerch(int ARRAY[],int l,int x);
