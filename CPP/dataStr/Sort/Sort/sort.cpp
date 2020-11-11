#include"Sort.h"

void Meow_Van::showA(int* A, int n)
{
	for(int i = 0;i<n;i++)
		std::cout << A[i] << ' ';
	std::cout << '\n';
}
int* Meow_Van::Insertsort(int *B,int n)
{
	int* A =new int[n];
	for (int i = 0; i < n; i++)
	{
		A[i] = B[i];
	}
	int i, j,t;
	for (i = 1; i < n; i++)
	{
		if (A[i] < A[i - 1])
		{
			t = A[i];
			for (j = i - 1; t < A[j]; --j)
			{
				A[j + 1] = A[j];
			}
			A[j + 1] = t;
		}

		
	}
	return A;
}
int* Meow_Van::Shelltsort(int* B, int n)
{
	int* A =new int[n];
	for (int i = 0; i < n; i++)
	{
		A[i] = B[i];
	}
	int i,j,t, dk;
	for (dk = n / 2; dk > 0; dk = dk / 2)
	{
		for (i = dk ; i < n; i++)
		{
			if (A[i] < A[i - dk])
			{
				t = A[i];
				for (j = i - dk; j >= 0 && t < A[j]; j -= dk)
				{
					A[j + dk] = A[j];
				}
				A[j + dk] = t;
			}
		}
	}
	return A;
}