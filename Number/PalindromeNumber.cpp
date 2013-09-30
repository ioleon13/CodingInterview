#include <stdio.h>
#include <stdlib.h>


// reverse the number, if the same. it seemed to work, but it might overflow
bool reverse(int num, int &ret)
{
	ret = 0;
	if(num < 0)
		return false;
	
	while(num != 0)
	{
		ret = ret*10 + num % 10;
		num = num / 10;
	}
	
	return true;
}

bool isPalindromeByRev(int num)
{
	int ret = 0;
	if(reverse(num, ret))
	{
		if(num == ret)
			return true;
		else
			return false;
	}
	else
	{
		return false;
	}
}


//compare the first digit and the last digit
bool isPalindrome(int num)
{
	if(num < 0)
		return false;
		
	int nDiv = 1;
	while(num / nDiv >= 10)
	{
		nDiv *= 10;
	}
	
	while(num != 0)
	{
		int nFirst = num / nDiv;
		int nLast = num % 10;
		
		if(nFirst != nLast)
			return false;
			
		num = (num % nDiv) / 10;
		nDiv /= 100;
	}
	
	return true;
}


int main()
{
	int num = 1234321;
	bool bPalindrome = isPalindrome(num);
	
	printf("The num %d %s palindrome number\n", num, bPalindrome ? "is" : "is not");
	return 0;
}