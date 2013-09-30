#include <stdio.h>
#include <stdlib.h>
#include <cstring>

void ZeroRowAndCol(int** m, int nRow, int nCol)
{
	int* aRow = new int[nRow];
	int* aCol = new int[nCol];
	memset(aRow, 0, sizeof(int));
	memset(aCol, 0, sizeof(int));
	
	for(int i = 0; i < nRow; ++i)
	{
		for(int j = 0; j < nCol; ++j)
		{
			if(0 == m[i][j])
			{
				aRow[i] = 1;
				aCol[j] = 1;
			}
		}
	}
	
	for(int i = 0; i < nRow; ++i)
	{
		for(int j = 0; j < nCol; ++j)
		{
			if(1 == aRow[i] || 1 == aCol[j])
			{
				m[i][j] = 0;
			}
		}
	}
	
	delete [] aRow;
	delete [] aCol;
}
int main()
{
	int** Matrix;
	Matrix = new int*[5];
	for(int i = 0; i < 5; ++i)
	{
		Matrix[i] = new int[3];
		for(int j = 0; j < 3; ++j)
		{
			Matrix[i][j] = j+i;
		}
	}
	
	printf("Matrix Before Transform is :\n");
	for(int i = 0; i < 5; ++i)
	{
		for(int j = 0; j < 3; ++j)
		{
			printf("%d  ", Matrix[i][j]);
		}
		printf("\n");
	}
	
	ZeroRowAndCol(Matrix, 5, 3);
	
	printf("Matrix After Transform is :\n");
	for(int i = 0; i < 5; ++i)
	{
		for(int j = 0; j < 3; ++j)
		{
			printf("%d  ", Matrix[i][j]);
		}
		printf("\n");
	}
	return 0;
}