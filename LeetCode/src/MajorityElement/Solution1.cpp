/*
 * Solution1.cpp
 *
 *  Created on: 2014-12-23
 *      Author: liya
 */
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
//#include <map>
using namespace std;

/*int majorityElement(vector<int> &num) {
	map<int, int> mapCount;
	int size = num.size();
	for (int i = 0; i < size; ++i) {
		mapCount[num[i]]++;
		if (mapCount[num[i]] > size / 2) {
			return num[i];
		}
	}

	return 0;
}*/

// a triky solution, fit for vast array
int majorityElement(vector<int> &num) {
	int nResult = num[0];
	int nDeltaCount = 1;
	for (int i = 1; i < num.size(); ++i) {
		if (nDeltaCount == 0) {
			nResult = num[i];
			nDeltaCount++;
		} else {
			if (num[i] == nResult) {
				nDeltaCount++;
			} else {
				nDeltaCount--;
			}
		}
	}

	if (nDeltaCount > 0) {
		return nResult;
	} else {
		printf("There was no majority element in the array");
		return -1;
	}
}

int main() {
	vector<int> testNum;
	testNum.push_back(2);
	testNum.push_back(5);
	testNum.push_back(3);
	testNum.push_back(1);
	testNum.push_back(4);
	testNum.push_back(2);
	testNum.push_back(1);

	int nMajority = majorityElement(testNum);
	printf("The majority element is: %d \r\n", nMajority);
	return 0;
}



