#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <string>
using namespace std;

//used two array, foolish!
bool IsAnagrams(const char* szStr1, const char* szStr2)
{
	int nLen1 = strlen(szStr1);
	int nLen2 = strlen(szStr2);

	if(nLen1 != nLen2)
		return false;

	if(0 == strcmp((char*)szStr1, (char*)szStr2))
		return false;

	int a1[256] = {0};
	int a2[256] = {0};

	while(*szStr1 != '\0')
	{
		int nValue = (int)(*szStr1);
		a1[nValue]++;
		++szStr1;
	}

	while(*szStr2 != '\0')
	{
		int nValue = (int)(*szStr2);
		a2[nValue]++;
		++szStr2;	
	}

	for(int i = 0; i < 256; ++i)
	{
		if(a1[i] != a2[i])
			return false;
	}
	return true;
}

//used only one array
bool IsAnagrams2(const char* szStr1, const char* szStr2)
{
	int nLen1 = strlen(szStr1);
	int nLen2 = strlen(szStr2);

	if(nLen1 != nLen2)
		return false;

	if(0 == strcmp((char*)szStr1, (char*)szStr2))
		return false;

	int a[256] = {0};

	while(*szStr1 != '\0')
	{
		int nValue = (int)(*szStr1);
		a[nValue]++;
		++szStr1;
	}

	while(*szStr2 != '\0')
	{
		int nValue = (int)(*szStr2);
		a[nValue]--;
		++szStr2;	
	}

	for(int i = 0; i < 256; ++i)
	{
		if(0 != a[i])
			return false;
	}
	return true;
}
int main()
{
	string str1 = "abbcd";
	string str2 = "abcdd";
	bool bAnagrams = IsAnagrams2(str1.c_str(), str2.c_str());
	printf("Str1: %s and Str2: %s are %s anagrams!\n", str1.c_str(), str2.c_str(), bAnagrams ? "" : "not");
	return 0;
}
