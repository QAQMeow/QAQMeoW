#include<stdio.h>
#include"SortAndSearch.h"
#include<stdlib.h>
int A[20] = {10,3,11,7,19,1,6,14,5,18,9,15,2,12,16,13,4,17,8,20};
int LEN =  sizeof(A)/sizeof(int);	


//直接插入排序
/*
初始假设第一个元素(下标0)是已排好序列，从下标(i = 1)开始，与已排好的序列依次(从j = 0开始)比较，若比排好的序列中的j元素小，则已排好的序列从j往后顺移一位，将i元素插入j位置
*/
int*  DirectInsertionSort(int ARRAY[])
{
	int* B = (int*)malloc(LEN*sizeof(int));
	for(int i = 0;i < LEN;i++)
	B[i] = A[i];

	int t;			// 临时记录选取比较的i元素
	int i;			// 未排列的元素下标
	int j; 			// 已排列的元素下标
	int k;			// 往后顺移时记录位置

	for(i = 1;i < LEN;i++)
	{
		for(j = 0;j < i;j++)
		{
			t = B[i];
			if(t < B[j])
			{
				for(int k = i;k > j ;k--)
				{
					B[k] = B[k-1];
				}
				B[j] = t;
			}
		
		}
	}		
	return B;
	
}

//折半插入排序
/*
先折半查找位置再移动
*/
int* BinaryInsertionSort(int ARRAY[])
{
	int* B = (int*)malloc((LEN+1)*sizeof(int));
	for(int i = 1;i <=LEN;i++)
	B[i] = A[i-1];
	
	int i,j,high,low;

	for(i=2;i<(LEN+1);i++)
	{
		B[0] = B[i];
		low = 1;
		high = i-1;
		while(low<=high)
		{
			int mid = (low+high)/2;
			if(B[mid]>B[0])
				high = mid -1;
			else
				low = mid+1;

		}
		for (j = i-1;j>=high+1;--j)
		{
			B[j+1] = B[j];
		}
		B[high+1] = B[0];
	}

	return B+1;
}

//希尔排序
/*

*/
int* ShellSort(int ARRAY[])
{
	int* B = (int*)malloc(LEN*sizeof(int));
	for(int i = 0;i < LEN;i++)
	B[i] = A[i];
	for(int i = 0;i < LEN;i++)
	B[i] = A[i];


	return B;

}

//冒泡排序
/*
排序为从小到达
每次都从下标j=0开始，每排序一次，最大值都排到最后一位，下次需要排序的个数-1
*/
int* BubbleSort(int ARRAY[])
{
	int* B = (int*)malloc(LEN*sizeof(int));
	for(int i = 0;i < LEN;i++)
	B[i] = A[i];

	int i,j;
	int t;
	for(i = 0;i < LEN-1;i++)
	{
		for(j = 0;j < LEN-i-1;j++)       //注意 j< LEN-1-i
		{
			
			if(B[j] > B[j+1])
			{
				t = B[j];
				B[j] = B[j+1];
				B[j+1] = t;
			}
		}
	}
	return B;
}

//快速排序
/*
选取第一个为参考值，将序列分为比该值小和比该值大两序列，再对这两序列进行同样的操作
*/
int* QuickSort(int ARRAY[])
{ 	
	int* B = (int*)malloc(LEN*sizeof(int));
	for(int i = 0;i < LEN;i++)
	B[i] = A[i];

	int left = 0;
	int right = LEN - 1;
	int T = B[left];
	int k;
	int nright,nleft;
	void sort(int left,int right,int T)
	{
		int i = 0,j = 0;		//记录移动增量，方便计算下一次排序序列位置，可只用一个变量记录
		while(left <right)
		{	

			if(B[left] < T)
			{
			 	left++;
			 	i++;
			}
			if(B[right] > T)
			{
				right--;
				j++;
			}	
			k = B[left];
			B[left] = B[right];
			B[right] = k;	

			/*	left-i：下一次左边排序序列第一个元素位置
				left-1：下一次左边排序最后一个元素位置
				right+1：下一次右边序列排序第一个元素位置
				right+j：下一次右边排序最后一个元素位置
			*/
			sort(left-i,left-1,B[left-i]);
			sort(right+1,right+j, B[right+1]);
		}
		
	}

	sort(left,right,B[0]);
	
	return B;
}

//简单选择排序
/*

*/
int* SimpleSelectionSort(int ARRAY[])
{
	int* B = (int*)malloc(LEN*sizeof(int));
	for(int i = 0;i < LEN;i++)
	B[i] = A[i];

	int i,j,t;

	for(i = 0;i<LEN - 1;i++)
	{
		for(j = i;j<LEN - 1;j++)
		{
			if(B[j] <= B[i])
			{
				t = B[j];
				B[j] = B[i];
				B[i] = t;
			}
		}	
	}
	return B;
}

//堆排序
int* HeapSort(int ARRAY[])
{
	int* B = (int*)malloc(LEN*sizeof(int));
	for(int i = 0;i < LEN;i++)
	B[i] = A[i];
}

//归并排序
int* MergeSort(int ARRAY[])
{
	int* B = (int*)malloc(LEN*sizeof(int));
	for(int i = 0;i < LEN;i++)
	B[i] = A[i];
}

//基数排序
int* RadixSort(int ARRAY[])
{
	int* B = (int*)malloc(LEN*sizeof(int));
	for(int i = 0;i < LEN;i++)
	B[i] = A[i];

}

//输出数组
void PrintArray(int ARRAY[])
{	
	
	for(int i = 0;i<LEN;i++)
	printf("%d ",ARRAY[i]);
	
	printf("\n");
}

