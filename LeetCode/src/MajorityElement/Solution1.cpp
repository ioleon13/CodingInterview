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
#include <map>
using namespace std;

int majorityElement(vector<int> &num) {
	map<int, int> mapCount;
	int size = num.size();
	for (int i = 0; i < size; ++i) {
		mapCount[num[i]]++;
		if (mapCount[num[i]] > size / 2) {
			return num[i];
		}
	}

	return 0;
}

int main() {
	vector<int> testNum;
	testNum.push_back(1);
	testNum.push_back(1);
	testNum.push_back(1);
	testNum.push_back(2);
	testNum.push_back(2);
	testNum.push_back(2);
	testNum.push_back(1);

	int nMajority = majorityElement(testNum);
	printf("The majority element is: %d \r\n", nMajority);
	return 0;
}



