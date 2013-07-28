#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <cstring>
using namespace std;

//ascII
bool isUnique1(string s)
{
	int nArrary[256] = {0};
	int nSize = s.length();
	int i = 0;
	for(; i < nSize; ++i)
	{
		int nValue = (int)s[i];
		if(1 == nArrary[nValue])
		{
			return false;
		}
		
		nArrary[nValue] = 1;
	} 

	return true;
}


//bit
bool isUnique2(string s)
{
	int a[8];
	memset(a, 0, sizeof(a));
	
	for(unsigned int i = 0; i < s.length(); ++i)
	{
		int nValue = (int)s[i];
		int nIndex = nValue / 32;
		int nShift = nValue % 32;
		
		if(a[nIndex] & 0x1<<nShift)
			return false;
		
		a[nIndex] |= 0x1<<nShift;		
	}

	return true;
}

int main()
{
	//printf("hello world!\n");
	string str = "12345678aggegeji";
	//bool bUnique = isUnique1(str);
	bool bUnique = isUnique2(str);
	if(bUnique)
		printf("String %s is unique!\n", str.c_str());
	else
		printf("String %s is not unique!\n", str.c_str());
	return 0;
}
