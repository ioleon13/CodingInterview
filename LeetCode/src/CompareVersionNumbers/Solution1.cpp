/*
 * Solution1.cpp
 *
 *  Created on: 2014-12-16
 *      Author: liya
 *
 * Compare two version numbers version1 and version1.
 * If version1 > version2 return 1, if version1 < version2 return -1,
 * otherwise return 0.
 *
 * You may assume that the version strings are non-empty and contain only
 * digits and the . character.
 * The . character does not represent a decimal point and is used to separate
 * number sequences.
 * For instance, 2.5 is not "two and a half" or "half way to version three",
 * it is the fifth second-level revision of the second first-level revision.
 *
 * Here is an example of version numbers ordering:
 *
 * 0.1 < 1.1 < 1.2 < 13.37
 *
 * Credits:
 * Special thanks to @ts for adding this problem and creating all test cases.
 */
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int compareVersion(string version1, string version2) {
	while(1) {
		int pos1 = version1.find('.');
		int pos2 = version2.find('.');

		string subStr1;
		string subStr2;
		if (pos1 == string::npos) {
			subStr1 = version1;
			version1 = "0";
		} else {
			subStr1 = version1.substr(0, pos1);
			version1 = version1.substr(pos1+1, version1.length()-pos1-1);
		}

		if (pos2 == string::npos) {
			subStr2 = version2;
			version2 = "0";
		} else {
			subStr2 = version2.substr(0, pos2);
			version2 = version2.substr(pos2+1, version2.length()-pos2-1);
		}

		int nVersion1 = atoi(subStr1.c_str());
		int nVersion2 = atoi(subStr2.c_str());

		if (nVersion1 > nVersion2) {
			return 1;
		} else if (nVersion1 < nVersion2) {
			return -1;
		}

		if (pos1 == string::npos
				&& pos2 == string::npos
				&& nVersion1 == nVersion2) {
			return 0;
		}
	}
}

int main() {
	return 0;
}



