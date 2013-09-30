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


//use two pointer,p and q
ListNode* findNthToLast(ListNode* head, int n)
{
	if(NULL == head || n < 1)
		return NULL;
		
	ListNode *p = head;
	ListNode *q = head;
	
	while(n > 0 && p)
	{
		p = p->next;
		n--;
	}
	
	if(n > 0)
		return NULL;
		
	while(p)
	{
		p = p->next;
		q = q->next;
	}
	
	return q;
}


//recursive method
int nth;
ListNode* pNth;
void findNthToLastByRecur(ListNode* head)
{
	if(NULL == head)
		return;
		
	findNthToLastByRecur(head->next);
	
	if(1 == nth)
		pNth = head;
		
	nth--;
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


int main()
{
	int n = 18;
	int arrayList[] = {4, 2, 1, 1, 2, 5, 1, 9, 8, 2, 0, 6, 2, 4, 0, 3, 3, 2};
	
	ListNode* head = init(arrayList, n);
	printf("The original link list is:");
	printList(head);
	
	ListNode* pNthToLast = findNthToLast(head, 7);
	
	if(pNthToLast)
	{
		printf("The 7th to last element is: %d\n", pNthToLast->nValue);
	}
	else
	{
		printf("The length of link is not long enough\n");
	}
	
	nth = 6;
	findNthToLastByRecur(head);
	if(pNth)
	{
		printf("Recursive method, the 6th to last element is: %d\n", pNth->nValue);
	}

	return 0;
}