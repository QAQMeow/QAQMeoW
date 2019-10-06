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
		B[0] = -1;
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
	int* B = (int*)malloc((LEN+1)*sizeof(int));
	B[0] = -1;
	for(int i = 1;i <= LEN;i++)
	B[i] = A[i-1];
	int d;
	for (d = LEN/2; d>=1 ; d=d/2)
	{
		for (int i = d+1; i < LEN; ++i)
		{
			if(B[i]<B[i-d])
			{ int j;	
				B[0] = B[i];
				for (j = i-d; j >0&&B[0]<B[j];j-=d)
				{
					B[j+d] = B[j];
				}
				B[j+d] = B[0];
			}
		}
	}

	return B+1;

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

	 
	void swap(int* a, int* b)
	{
	    int temp = *b;
	    *b = *a;
	    *a = temp;
	}
	void max_heapify(int arr[], int start, int end) 
	{
	    //建立父节点指标和子节点指标
	    int dad = start;
	    int son = dad * 2 + 1;
	    while (son <= end)  //若子节点指标在范围内才做比较
	        {
	            if (son + 1 <= end && arr[son] < arr[son + 1]) 
	            //先比较两个子节点大小，选择最大的
	            son++;
	        if (arr[dad] > arr[son]) //如果父节点大於子节点代表调整完毕，直接跳出函数
	            return;
	        else  //否则交换父子内容再继续子节点和孙节点比较
	        {
	            swap(&arr[dad], &arr[son]);
	            dad = son;
	            son = dad * 2 + 1;
	        }
	    }
	}
	int i;
    //初始化，i从最後一个父节点开始调整
    for (i = LEN / 2 - 1; i >= 0; i--)
        max_heapify(B, i, LEN - 1);
    //先将第一个元素和已排好元素前一位做交换，再重新调整，直到排序完毕
    for (i = LEN - 1; i > 0; i--) 
    {
        swap(&B[0], &B[i]);
        max_heapify(B, 0, i - 1);
    }

    return B;
}

//归并排序
int* MergeSort(int ARRAY[])
{
	int* B = (int*)malloc(LEN*sizeof(int));
	for(int i = 0;i < LEN;i++)
	B[i] = A[i];

	void Merge(int sourceArr[],int tempArr[], int startIndex, int midIndex, int endIndex)
	{
	    int i = startIndex, j=midIndex+1, k = startIndex;
	    while(i!=midIndex+1 && j!=endIndex+1)
	    {
	        if(sourceArr[i] > sourceArr[j])
	            tempArr[k++] = sourceArr[j++];
	        else
	            tempArr[k++] = sourceArr[i++];
	    }
	    while(i != midIndex+1)
	        tempArr[k++] = sourceArr[i++];
	    while(j != endIndex+1)
	        tempArr[k++] = sourceArr[j++];
	    for(i=startIndex; i<=endIndex; i++)
	        sourceArr[i] = tempArr[i];
	}

	void MergeSort(int sourceArr[], int tempArr[], int startIndex, int endIndex)
	{
	    int midIndex;
	    if(startIndex < endIndex)
	    {
	        midIndex = startIndex + (endIndex-startIndex) / 2;
	        MergeSort(sourceArr, tempArr, startIndex, midIndex);
	        MergeSort(sourceArr, tempArr, midIndex+1, endIndex);
	        Merge(sourceArr, tempArr, startIndex, midIndex, endIndex);
	    }
	}
	int C[LEN];
	MergeSort(B, C, 0, 19);
	return B;
	
}

//基数排序

int* RadixSort(int ARRAY[])
{
	int* B = (int*)malloc(LEN*sizeof(int));
	// for(int i = 0;i < LEN;i++)
	// B[i] = A[i];
	typedef struct C
	{
		int data;
		int p;
		int r;
	}C;

	C Ca[LEN];	
	for (int i = 0; i < LEN; ++i)
	{
		Ca[i].data = A[i];
		Ca[i].p  = i;
		Ca[i].r =A[i]%10;
	}
	
	for(int i = 0;i < LEN-1;i++)
	{
		for(int j = 0;j < LEN-i-1;j++)       //注意 j< LEN-1-i
		{
			
			if(Ca[j].r > Ca[j+1].r)
			{
				int t,k,l;
				t =Ca[j].data;
				k = Ca[j].p;
				l = Ca[j].r;

				Ca[j].data = Ca[j+1].data;
				Ca[j].p  =Ca[j+1].p;
				Ca[j].r = Ca[j+1].r;

				Ca[j+1].data = t;
				Ca[j+1].p  = k;
				Ca[j+1].r = l;
			}
		}
	}

for (int i = 0; i < LEN; ++i)
	{
		Ca[i].r =Ca[i].data/10;
	}
for(int i = 0;i < LEN-1;i++)
	{
		for(int j = 0;j < LEN-i-1;j++)       //注意 j< LEN-1-i
		{
			
			if(Ca[j].r > Ca[j+1].r)
			{
				int t,k,l;
				t =Ca[j].data;
				k = Ca[j].p;
				l = Ca[j].r;

				Ca[j].data = Ca[j+1].data;
				Ca[j].p  =Ca[j+1].p;
				Ca[j].r = Ca[j+1].r;

				Ca[j+1].data = t;
				Ca[j+1].p  = k;
				Ca[j+1].r = l;
			}
		}
	}

	for (int i = 0; i < LEN; ++i)
	{
		B[i] = Ca[i].data;
	}
	return B;
}

//输出数组
void PrintArray(int ARRAY[])
{	
	
	for(int i = 0;i<LEN;i++)
	printf("%d ",ARRAY[i]);
	
	printf("\n");
}

