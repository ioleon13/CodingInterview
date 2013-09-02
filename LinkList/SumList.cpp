#include <stdio.h>
#include <stdlib.h>
#include <cstring>

using namespace std;

struct ListNode 
{
	int nValue;
	ListNode* next;

	ListNode()
		: nValue(0)
		, next(NULL)
	{}

	ListNode(const ListNode& node)
		: nValue(node.nValue)
		, next(node.next)
	{}

	ListNode & operator = (const ListNode& node)
	{
		if (this != &node)
		{
			nValue = node.nValue;
			next = node.next;
		}

		return *this;
	}
};

//ÀûÓÃÊý×é¹¹Ôìµ¥Á´±í
ListNode* init(int arrayList[], int nLen)
{
	ListNode* head;
	ListNode* p;
	for (int i = 0; i < nLen; ++i)
	{
		ListNode* tmp = new ListNode();
		tmp->nValue = arrayList[i];

		if (0 == i)
		{
			head = p = tmp;
			continue;
		}

		p->next = tmp;
		p = tmp;
	}

	return head;
}

void printList(ListNode* node)
{
	ListNode* p = node;
	while (p)
	{
		if (NULL == p->next)
		{
			printf("%d\n", p->nValue);
		}
		else
		{
			printf("%d, ", p->nValue);
		}
	
		p = p->next;
	}
}


/***Add two link list
 * You have two numbers represented by a linked list,
 * where each node contains a single digit. 
 * The digits are stored in reverse order, 
 * such that the 1’s digit is at the head of the list. 
 * Write a function that adds the two numbers and returns the sum as a linked list.
 * EXAMPLE
 * Input: (3 –> 1 –> 5), (5 –> 9 –> 2)
 * Output: 8 –> 0 –> 8
*/

//1st Brute force solution
ListNode* AddTwoList(ListNode* pHeadL, ListNode* pHeadR)
{
	//fist point
	if(NULL == pHeadL)
		return pHeadR;
	if(NULL == pHeadR)
		return pHeadL;
		
	ListNode* pL = pHeadL;
	ListNode* pR = pHeadR;
	
	ListNode* pResHead;
	ListNode* pRes;
	
	int nCount = 0;
	int nAdd = 0;
	int nSum = 0;
	int nResValue = 0;
	while(NULL != pL && NULL != pR)
	{
		nSum = pL->nValue + pR->nValue;
		nResValue = nSum % 10 + nAdd;
		nAdd = nSum / 10;
		
		pL = pL->next;
		pR = pR->next;
		
		ListNode* tmp = new ListNode();
		tmp->nValue = nResValue;
		
		nCount++;

		if (1 == nCount)
		{
			pResHead = pRes = tmp;
			continue;
		}

		pRes->next = tmp;
		pRes = tmp;
	}
	

	if(NULL == pL && NULL != pR)
	{
		while(NULL != pR)
		{
			nSum = nAdd + pR->nValue;
			nResValue = nSum % 10;
			nAdd = nSum / 10;
			ListNode* tmp = new ListNode();
			tmp->nValue = nResValue;
			pRes->next = tmp;
			pRes = tmp;
			
			pR = pR->next;
		}
	}
	else if(NULL != pL && NULL == pR)
	{
		while(NULL != pL)
		{
			nSum = nAdd + pL->nValue;
			nResValue = nSum % 10;
			nAdd = nSum / 10;
			ListNode* tmp = new ListNode();
			tmp->nValue = nResValue;
			pRes->next = tmp;
			pRes = tmp;
			
			pL = pL->next;
		}
	}
	
	if(nAdd > 0)
	{
		ListNode* tmp = new ListNode();
		tmp->nValue = nAdd;
		pRes->next = tmp;
		pRes = tmp;
	}
	
	return pResHead;
}

int main()
{
	int n = 1;
	int arrayListL[] = {1};
	
	int m = 3;
	int arrayListR[] = {9, 9, 9};
	
	ListNode* headL = init(arrayListL, n);
	printf("The left link list is:");
	printList(headL);
	
	ListNode* headR = init(arrayListR, m);
	printf("The right link list is:");
	printList(headR);
	
	ListNode* pResult = AddTwoList(headL, headR);
	printf("The sum of two link lists is:");
	printList(pResult);
	
	return 0;
}