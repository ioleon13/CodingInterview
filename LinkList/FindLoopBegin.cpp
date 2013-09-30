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

//create a circular linked list, loop_start is the beginning of the loop.
ListNode* init(int arrayList[], int nLen, int loop_start)
{
	ListNode* head;
	ListNode* p;
	ListNode* q;
	for (int i = 0; i < nLen; ++i)
	{
		ListNode* tmp = new ListNode();
		tmp->nValue = arrayList[i];

		if (i == loop_start)
		{
			q = tmp;
		}

		if (0 == i)
		{
			head = p = tmp;
			continue;
		}

		p->next = tmp;
		p = tmp;
	}

	p->next = q;

	return head;
}


/*find the node at the beginning of the loop
* tricky solution: fast pointer and low pointer
* if two pointers are meet, there is a loop 
*/
ListNode* FindLoopBegin(ListNode* head)
{
	if(NULL == head)
		return NULL;
		
	ListNode *fast = head;
	ListNode *low = head;

	//two pointers are meet
	while(NULL != fast->next)
	{
		fast = fast->next->next;
		low = low->next;

		if (fast == low)
		{
			break;
		}
	}

	if (NULL == fast->next)
	{
		return NULL;
	}
	
	//fast pointer return to head 
	fast = head;

	while (fast != low)
	{
		fast = fast->next;
		low = low->next;
	}
	
	return fast;
}


/*find the node at the beginning of the loop
* simple solution: hash map
* the node is already exist, find the node 
*/
map<ListNode*, bool> hash;
ListNode* FindLoopBeginByHash(ListNode* head)
{
	if(NULL == head)
		return NULL;

	while (head)
	{
		if (hash[head])
		{
			return head;
		}
		else
		{
			hash[head] = true;
			head = head->next;
		}
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


int main()
{
	int n = 18;
	int loop_start = 4;
	int arrayList[] = {4, 2, 1, 1, 2, 5, 1, 9, 8, 2, 0, 6, 2, 4, 0, 3, 3, 2};
	
	ListNode* head = init(arrayList, n, loop_start);
	
	ListNode* start_node = FindLoopBegin(head);
	
	if(start_node)
	{
		printf("The beginning of the loop is: %d\n", start_node->nValue);
	}
	else
	{
		printf("Fail to find the beginning of the loop\n");
	}
	
	start_node = FindLoopBeginByHash(head);
	if(start_node)
	{
		printf("hashmap method, The beginning of the loop is: %d\n", start_node->nValue);
	}

	return 0;
}