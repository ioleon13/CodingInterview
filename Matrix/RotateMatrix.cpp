#include <stdio.h>
#include <stdlib.h>


void swap(int &a, int &b)
{
	a = a^b;
	b = a^b;
	a = a^b;
}


void RotateMatrix(int a[][4], int n)
{
	//swap diag
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			if(i < j)
				swap(a[i][j], a[j][i]);
		}
	}
	
	//swap line
	for(int i = 0; i < n/2; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			swap(a[i][j], a[n-1-i][j]);
		}
	}
}


int main()
{
	int Matrix[4][4] = {1,2,3,4,
						5,6,7,8,
						9,10,11,12,
						13,14,15,16};
						
	printf("Matrix Before rotate is :\n");
	for(int i = 0; i < 4; ++i)
	{
		for(int j = 0; j < 4; ++j)
		{
			printf("%d  ", Matrix[i][j]);
		}
		printf("\n");
	}
	
	RotateMatrix(Matrix, 4);
	
	printf("Matrix After rotate is :\n");
	for(int i = 0; i < 4; ++i)
	{
		for(int j = 0; j < 4; ++j)
		{
			printf("%d  ", Matrix[i][j]);
		}
		printf("\n");
	}
}