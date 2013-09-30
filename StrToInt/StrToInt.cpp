#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
using namespace std;

enum Status
{
	kValid = 0,
	kInvalid
};

int g_nStatus = kValid;

long long StrToIntCore(const char* szStr, bool bMinus)
{
	long long num = 0;
	
	while(*szStr != '\0')
	{
		if(*szStr >= '0' && *szStr <= '9')
		{
			int flag = bMinus ? -1 : 1;
			num  = num * 10 + flag * (*szStr - '0');

			if((!bMinus && num > 0x7FFFFFFF)
			|| (bMinus && num < (signed int)0x80000000))
			{
				num  = 0;
				break;
			}

			szStr++;
		}
		else
		{
			num = 0;
			break;
		}
	}

	if(*szStr == '\0')
	{
		g_nStatus = kValid;
	}

	return num;
}


int StrToInt(const char* szStr)
{
	g_nStatus = kInvalid;
	long long num = 0;

	if(szStr != NULL && *szStr != '\0')
	{
		bool bMinus = false;
		if(*szStr == '+')
			szStr++;
		else
		{
			szStr++;
			bMinus = true;	
		}

		if(*szStr != '\0')
		{
			num = StrToIntCore(szStr, bMinus);
		}
	}

	return (int)num;
}


int main()
{
	string strDigit = "-12349";
	printf("Digit String is: %s\n", strDigit.c_str());
	int nDigit = StrToInt(strDigit.c_str());
	
	if(g_nStatus == kValid)
	{
		printf("String convert to Int is: %d\n", nDigit);	
	}
	else
	{	
		printf("Input String is Invalid!\n");
	}
	
	return 0;
}
