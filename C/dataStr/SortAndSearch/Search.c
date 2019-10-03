#include<stdio.h>
#include"SortAndSearch.h"
#include<stdlib.h>
extern int LEN;

void Sortsearch(int ARRAY[],int x)
{
	for (int i = 0; i < LEN; ++i)
	{
		if (ARRAY[i] == x)
		{
			printf("A[%d] = %d  \n", i,x);
		}
	}
}

int BinarySeaerch(int ARRAY[],int l,int x)
{
	int* B = (int*)malloc(l*sizeof(int));
	for(int i = 0;i < l;i++)
	B[i] = ARRAY[i];
	int low,high;
	int mid = l/2;
	if(x<B[0]||x>B[l-1])
		return -1;

	else if(x == B[mid])
	//	printf("ARRAY[%d] = %d \n", mid,x);
		return mid;
	else if(x > B[mid]&&mid!=0)
	{
		low = mid;
		high = l;
		int* C = (int*)malloc((high - low)*sizeof(int));
		for (int i = 0; i <(high - low); ++i)
		{
			C[i] = B[i+mid];
		}
		return low + BinarySeaerch(C,(high - low),x);
	}
	else if(x < B[mid] && mid!=0)
	{
		low = 0;
		high = mid;
		int* C = (int*)malloc((high - low)*sizeof(int));
		for (int i = 0; i < (high - low); ++i)
		{
			C[i] = B[i];
		}
		return low + BinarySeaerch(C,mid,x);
	}


}