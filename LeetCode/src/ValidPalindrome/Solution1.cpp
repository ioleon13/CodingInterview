/*
 * Solution1.cpp
 *
 *  Created on: 2014-12-11
 *      Author: liya
 *
 * Given a string, determine if it is a palindrome, considering only
 * alphanumeric characters and ignoring cases.
 *
 * For example,
 * "A man, a plan, a canal: Panama" is a palindrome.
 * "race a car" is not a palindrome.
 *
 * Note:
 * Have you consider that the string might be empty? This is a good question
 * to ask during an interview.
 *
 * For the purpose of this problem, we define empty string as valid palindrome.
 */
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

bool isAlphanumeric(char c) {
	if (isalpha(c) || isdigit(c)) {
		return true;
	} else {
		return false;
	}
}

bool isPalindrome(string s) {
	int nLen = s.length();
	if (nLen <= 1) {
		return true;
	}

	char cBegin = s[0];
	char cEnd = s[nLen-1];
	if (isAlphanumeric(cBegin) && isAlphanumeric(cEnd)) {
		if (toupper(cBegin) == toupper(cEnd)) {
			return isPalindrome(s.substr(1, nLen-2));
		} else {
			return false;
		}
	} else {
		int nPos = 0;
		int nSub = 0;
		if (!isAlphanumeric(cBegin) && !isAlphanumeric(cEnd)) {
			nPos = 1;
			nSub = 2;
		} else if(!isAlphanumeric(cBegin)) {
			nPos = 1;
			nSub = 1;
		} else {
			nPos = 0;
			nSub = 1;
		}
		return isPalindrome(s.substr(nPos, nLen-nSub));
	}
	return false;
}

int main() {
	//string testStr = "A man, a plan, a canal: Panama";
	string testStr = "race a car";
	bool bPalin = isPalindrome(testStr);
	printf("The string \"%s\" is %s a palindrome.\r\n", testStr.c_str(),
			bPalin ? "" : "not");
	return 0;
}

