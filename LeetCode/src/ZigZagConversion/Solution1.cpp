/*
 * Solution1.cpp
 *
 *  Created on: 2014-11-25
 *      Author: liya
 *
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number
 * of rows like this: (you may want to display this pattern in a fixed font for
 * better legibility)
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 *
 * rows = 4, should return "PINALSIGYAHRPI"
 * P     I     N
 * A   L S   I G
 * Y A   H R
 * P     I
 *
 * rows = 5, should return "PHASIYIRPLIGAN"
 * P       H
 * A     S I
 * Y   I   R
 * P L     I G
 * A       N
 *
 * And then read line by line: "PAHNAPLSIIGYIR"
 * Write the code that will take a string and make this conversion given a
 * number of rows:
 * 	string convert(string text, int nRows);
 *
 * convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
 */
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;

string convert(string s, int nRows) {
	string strRet = s;

	if (nRows <= 1) {
		return strRet;
	}

	struct strNode {
		char chValue;
		bool bValid;

		strNode() :chValue('0'), bValid(false) {};
	};

	int nLen = s.length();

	int nZigZagLen = 2 * nRows - 2;
	int nZigZagCount = 0;
	if (nLen <= nZigZagLen) {
		nZigZagCount = 1;
	} else {
		if(nLen % nZigZagLen == 0) {
			nZigZagCount = nLen / nZigZagLen;
		} else {
			nZigZagCount = nLen / nZigZagLen + 1;
		}
	}

	int nColums = nZigZagCount * (nRows-1);

	strNode **matrix = new strNode*[nRows];
	for (int i = 0; i < nRows; ++i) {
		matrix[i] = new strNode[nColums];
	}

	int nPos = 0;
	for (int i = 0; i < nZigZagCount; ++i) {
		for (int j = 0; j < nRows; ++j) {
			if (nPos < nLen) {
				matrix[j][i*(nRows-1)].chValue = s[nPos];
				matrix[j][i*(nRows-1)].bValid = true;
				nPos++;
			}
		}

		for(int n = 0; n < nRows-2; ++n) {
			if (nPos < nLen) {
				matrix[nRows-2-n][i*(nRows-1)+1+n].chValue = s[nPos];
				matrix[nRows-2-n][i*(nRows-1)+1+n].bValid = true;
				nPos++;
			}
		}
	}

	//traversing the matrix
	nPos = 0;
	for (int i = 0; i < nRows; ++i) {
		for (int j = 0; j < nColums; ++j) {
			if (matrix[i][j].bValid) {
				strRet[nPos] = matrix[i][j].chValue;
				nPos++;
			}
		}
	}

	//release the matrix
	for (int i = 0; i < nRows; ++i) {
		delete matrix[i];
		matrix[i] = NULL;
	}
	delete []matrix;
	matrix = NULL;

	return strRet;
}

int main() {
	string strSrc = "PAYPALISHIRING";
	string strDest = convert(strSrc, 3);
	printf("After zigzag conversion when nRows=3, the string was: %s\r\n", strDest.c_str());

	strDest = convert(strSrc, 4);
	printf("After zigzag conversion when nRows=4, the string was: %s\r\n", strDest.c_str());

	strDest = convert(strSrc, 5);
	printf("After zigzag conversion when nRows=5, the string was: %s\r\n", strDest.c_str());

	strDest = convert(strSrc, 2);
	printf("After zigzag conversion when nRows=2, the string was: %s\r\n", strDest.c_str());

	strDest = convert(strSrc, 1);
	printf("After zigzag conversion when nRows=1, the string was: %s\r\n", strDest.c_str());
	return 0;
}

