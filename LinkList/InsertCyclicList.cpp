/*
 * Given a node from a cyclic linked list which has been sorted,
 * write a function to insert a value into the list such that it
 * remains a cyclic sorted list. The given node can be any 
 * single node in the list.
 * */
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <map>

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


/*
 * (1) prev→val ≤ x ≤ current→val:
 * Insert between prev and current.
 * 
 * (2)x is the maximum or minimum value in the list:
 * Insert before the head. (ie, the head has the smallest value and its prev→val > head→val.
 * 
 * (3)Traverses back to the starting point:
 * Insert before the starting point.
 * */
void Insert(ListNode* &node, int x)
{
	if(NULL == node)
	{
		node = new ListNode();
		node->nValue = x;
		node->next = node;
		return;
	}
	
	ListNode *p = node;
	ListNode *pre = NULL;
	
	do
	{
		pre = p;
		p = p->next;
		
		//for case (1)
		if(x >= pre->nValue && x <= p->nValue)
			break;
		
		//for case (2)
		if(pre->nValue > p->nValue
		&& (x > pre->nValue || x < p->nValue))
			break;
	}while(p != node); //for case (3)
	
	ListNode* newNode = new ListNode();
	newNode->nValue = x;
	newNode->next = p;
	pre->next = newNode;
}

void printList(ListNode* node)
{
	ListNode* p = node;
	while (p)
	{
		if (node == p->next)
		{
			printf("%d\n", p->nValue);
			break;
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
	
	ListNode* head = NULL;
	
	for(int i = 0; i < n; ++i)
	{
		Insert(head, arrayList[i]);
		
		if(head)
		{
			printList(head);
		}
		else
		{
			printf("Failed to insert to sorted cyclic link list\n");
		}
	}

	return 0;
}