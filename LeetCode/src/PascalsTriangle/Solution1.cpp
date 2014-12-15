/*
 * Solution1.cpp
 *
 *  Created on: 2014-12-15
 *      Author: liya
 *
 * Given numRows, generate the first numRows of Pascal's triangle.
 *
 * For example, given numRows = 5,
 * Return
 *
 * [
 *      [1],
 *     [1,1],
 *    [1,2,1],
 *   [1,3,3,1],
 *  [1,4,6,4,1]
 * ]
 */
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > generate(int numRows) {
	vector<vector<int> > ret;

	vector<int> vecTop(1, 1);
	vector<int> vecSecond(2, 1);

	for (int i = 0; i < numRows; ++i) {
		if (i == 0) {
			ret.push_back(vecTop);
		} else if (i == 1) {
			ret.push_back(vecSecond);
		} else {
			vector<int> vecLast = ret[i-1];
			vector<int> vecCur(i+1);
			vecCur[0] = 1;
			for (int j = 0; j < vecLast.size()-1; ++j) {
				vecCur[j+1] = vecLast[j] + vecLast[j+1];
			}
			vecCur[i] = 1;
			ret.push_back(vecCur);
		}
	}

	return ret;
}

int main() {
	return 0;
}

