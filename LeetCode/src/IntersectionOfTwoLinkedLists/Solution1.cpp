/*
 * Solution1.cpp
 *
 *  Created on: 2014-12-3
 *      Author: liya
 *
 * Write a program to find the node at which the intersection of two singly linked lists begins.
 *
 *
 * For example, the following two linked lists:
 *
 * A:          a1 -> a2
 *                     \
 *                     c1 -> c2 -> c3
 *                     /
 * B:     b1 -> b2 -> b3
 * begin to intersect at node c1.
 *
 *
 * Notes:
 *
 * If the two linked lists have no intersection at all, return null.
 * The linked lists must retain their original structure after the function returns.
 * You may assume there are no cycles anywhere in the entire linked structure.
 * Your code should preferably run in O(n) time and use only O(1) memory.
 */
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* createList(int a[], int n) {
	if (n <= 0) {
		return NULL;
	}

	ListNode **list = new ListNode*[n];
	for (int i = 0; i < n; ++i) {
		list[i] = new ListNode(a[i]);
	}

	int pos = 1;
	for (int i = 0; i < n && pos < n; ++i) {
		if (list[i]) {
			list[i]->next = list[pos++];
		}
	}

	return list[0];
}

void printList(ListNode *head) {
	if(head == NULL) {
		printf("The linked list was empty");
		return;
	}

	ListNode* p = head;
	while(p) {
		printf("%d ", p->val);
		p = p->next;
		if (p != NULL) {
			printf("-> ");
		}
	}
	printf("\r\n");
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
	if (headA == NULL || headB == NULL) {
		return NULL;
	}
	int lenA = 0, lenB = 0;

	ListNode *pA = headA;
	ListNode *pB = headB;
	while(1) {
		lenA++;
		lenB++;
		pA = pA->next;
		pB = pB->next;

		if (pA == NULL) {
			while (pB) {
				lenB++;
				pB = pB->next;
			}
			break;
		} else if (pB == NULL) {
			while (pA) {
				lenA++;
				pA = pA->next;
			}
			break;
		}
	}

	int nDelta = lenA-lenB;
	ListNode* ret = NULL;
	int nCount = 0;
	while(headA != NULL && headB != NULL) {
		if (nDelta == 0) {
			if(headA->val == headB->val)
				return headA;
			headA = headA->next;
			headB = headB->next;
		} else if (nDelta < 0) {
			if (headA->val == headB->val)
				return headA;

			if (nCount >= -nDelta) {
				headA = headA->next;
			}
			headB = headB->next;
			nCount++;
		} else {
			if (headA->val == headB->val)
				return headA;

			if (nCount >= nDelta) {
				headB = headB->next;
			}
			headA = headA->next;
			nCount++;
		}
	}

	return ret;
}

int main() {
	ListNode* listA;
	ListNode* listB;
	ListNode* listIntersection;

	int a[] = {1, 2, 3, 4, 5};
	int b[] = {7, 3, 4, 5};
	listA = createList(a, sizeof(a)/sizeof(int));
	listB = createList(b, sizeof(b)/sizeof(int));
	cout << "The List A is:" << endl; // print the list A
	printList(listA);
	cout << "The List B is:" << endl; // print the list B
		printList(listB);

	listIntersection = getIntersectionNode(listA, listB);
	cout << "The intersection of two singly linked lists is:" << endl;
	printList(listIntersection);
	return 0;
}




