/*
 * Solution1.cpp
 *
 *  Created on: 2014-12-29
 *      Author: liya
 *
 * Reverse digits of an integer.
 *
 * Example1: x = 123, return 321
 * Example2: x = -123, return -321
 *
 * Have you thought about this?
 * Here are some good questions to ask before coding. Bonus points for you if
 * you have already thought through this!
 *
 * If the integer's last digit is 0, what should the output be? ie, cases such
 * as 10, 100.
 *
 * Did you notice that the reversed integer might overflow? Assume the input
 * is a 32-bit integer, then the reverse of 1000000003 overflows. How should
 * you handle such cases?
 *
 * For the purpose of this problem, assume that your function returns 0 when
 * the reversed integer overflows.
 */
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int reverse(int x) {
	bool bNegative = false;
	if (x < 0) {
		x = 0-x;
		bNegative = true;
	}

	int ret = 0;
	while(x) {
		ret = ret * 10 + x % 10;
		x = x/10;
	}

	if (bNegative) {
		return -ret;
	} else {
		return ret;
	}
}

int main() {
	int x = 123;
	int ret = reverse(x);
	printf("The integer is: %d, return: %d", x, ret);

	x = -123;
	ret = reverse(x);
	printf("The integer is: %d, return: %d", x, ret);

	x = 123100;
	ret = reverse(x);
	printf("The integer is: %d, return: %d", x, ret);
	return 0;
}

