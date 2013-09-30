#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <string>
using namespace std;

//simple method, used two string
void ReplaceSpace(const string &strSrc, string &strDst)
{
	int nSrcLen = strSrc.length();
	
	int nSpaceNum = 0;
	for(int i = 0; i < nSrcLen; ++i)
	{
		if(' ' == strSrc[i])
			nSpaceNum++;
	}

	if(0 == nSpaceNum)
		strDst = strSrc;

	int nDstLen = nSrcLen + nSpaceNum * 2;

	for(int i = nSrcLen-1; i >= 0; --i)
	{
		if(' ' == strSrc[i])
		{
			strDst[nDstLen-1] = '0';
			nDstLen--;
			strDst[nDstLen-1] = '2';
			nDstLen--;
			strDst[nDstLen-1] = '%';
			nDstLen--;
		}
		else
		{
			strDst[nDstLen-1] = strSrc[i];
			nDstLen--;
		}			
	}
}


int main()
{
	string strSrc = "I love you!  ";
	string strDst = "";
	ReplaceSpace(strSrc, strDst);
	printf("The Source String is: %s\n", strSrc.c_str());
	printf("Replace the space is: %s\n", strDst.c_str());
	return 0;
}
