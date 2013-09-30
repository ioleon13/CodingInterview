#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <string>

using namespace std;

bool isSubstring(string s1, string s2)
{
	if(string::npos != s1.find(s2))
		return true;
	else
		return false;
}


bool isRotation(string s1, string s2)
{
	if(s1.length() != s2.length()
	|| s1.length() <= 0)
		return false;
		
	if(isSubstring(s1+s1, s2))
		return true;
	else
		return false;
}


int main()
{
	string s1 = "little";
	string s2 = "tlelit";
	
	if(isRotation(s1, s2))
		printf("%s is rotation of %s!\n", s2.c_str(), s1.c_str());
	else
		printf("%s is not rotation of %s!\n", s2.c_str(), s1.c_str());
	
	return 0;
}