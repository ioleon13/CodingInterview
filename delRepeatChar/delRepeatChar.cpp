#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>

bool DelRepeatChar(char a[])
{
	int nLen = strlen(a);

	if(nLen < 2)
		return true;
	
	int p = 0, i = 0;
	int array[8];
	memset(array, 0, sizeof(array));

	int nIndex, nShift = 0;
	for(; i < nLen; ++i)
	{
		int nValue = (int)a[i];
		nIndex = nValue / 32;
		nShift = nValue % 32;
		
		if(0 == (array[nIndex] & 0x1<<nShift))
		{
			a[p++] = a[i];

			array[nIndex] |= 0x1<<nShift;
		}
	} 

	a[p] = '\0';

	return true;
}


int main()
{
	char ss[]="abagcegegr";
	printf("Before delete repeat char: %s\n", ss);
	DelRepeatChar(ss);
	printf("After delete repeat char: %s\n", ss);
	return 0;
}
