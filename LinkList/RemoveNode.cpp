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


bool RemoveNode(ListNode* pDel)
{
	if(NULL == pDel || NULL == pDel->next)
		return false;
		
	ListNode* pNext = pDel->next;
	pDel->nValue = pNext->nValue;
	pDel->next = pNext->next;
	
	delete pNext;
	pNext = NULL;
	
	return true;
}


bool RemoveNodeByHead(ListNode* head, ListNode* pDel)
{
	if(NULL == head || NULL == pDel)
		return false;
		
	//not the last node
	if(NULL != pDel->next)
	{
		ListNode* pNext = pDel->next;
		pDel->nValue = pNext->nValue;
		pDel->next = pNext->next;
	
		delete pNext;
		pNext = NULL;
	}
	//only one node, head node is the node to be delete 
	else if(head == pDel)
	{
		delete pDel;
		pDel = NULL;
		head = NULL;
	}
	//the node to be delete is the last node
	else
	{
		ListNode* p = head;
		while(p->next != pDel)
		{
			p = p->next;
		}
		
		p->next = NULL;
		delete pDel;
		pDel = NULL;
	}
	
	return true;
}


int main()
{
	int n = 18;
	int arrayList[] = {4, 2, 1, 1, 2, 5, 1, 9, 8, 2, 0, 6, 2, 4, 0, 3, 3, 2};
	
	ListNode* head = init(arrayList, n);
	printf("The original link list is:");
	printList(head);
	
	int nn = 18;
	
	if(nn <= n)
	{
		ListNode* pDel = head;
		for(int i = 1; i < nn; ++i)
		{
			pDel = pDel->next;
		}
		
		if(RemoveNodeByHead(head, pDel))
		{
			printf("Remove the node, the link list is:");
			printList(head);
		}
		else
		{
			printf("Remove Failed\n");
		}
	}

	return 0;
}