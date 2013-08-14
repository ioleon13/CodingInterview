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

bool hashTable[1000];

//ɾ���ظ�Ԫ�أ�ʹ�ö���Ĵ洢�ռ�hashTable��ʱ�临�Ӷ�O(N)
void RemoveDuplicate1(ListNode* head)
{
	if (NULL == head)
	{
		return;
	}

	ListNode* p = head;
	ListNode* q = head->next;

	hashTable[head->nValue] = true;

	while (q)
	{
		if (hashTable[q->nValue])
		{
			ListNode* tmp = q;
			p->next = q->next;
			q = p->next;

			delete tmp;
		}
		else
		{
			hashTable[q->nValue] = true;

			p = q;
			q = p->next;
		}
	}
}


//ɾ���ظ�Ԫ�أ���ʹ�ö���Ŀռ䣬ʱ�临�Ӷ�O(N^2)
void RemoveDuplicate2(ListNode* head)
{
	if (NULL == head)
	{
		return;
	}

	ListNode *p, *q, *c = head;

	while (c)
	{
		p = c;
		q = c->next;
		int nValue = c->nValue;
		while (q)
		{
			//�ظ���ɾ��q
			if (nValue == q->nValue)
			{
				ListNode* tmp = q;
				p->next = q->next;
				q = p->next;

				delete tmp;
			}
			else
			{
				p = q;
				q = q->next;
			}
		}

		c = c->next;
	}
}


//�������鹹�쵥����
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


int main()
{
	int n = 18;
	int arrayList[] = {4, 2, 1, 1, 2, 5, 1, 9, 8, 2, 0, 6, 2, 4, 0, 3, 3, 2};
	
	memset(hashTable, false, sizeof(hashTable));

	ListNode* head = init(arrayList, n);
	printf("The original link list is:");
	printList(head);

	//RemoveDuplicate1(head);
	RemoveDuplicate2(head);

	printf("Removed duplicates link list is:");
	printList(head);
	return 0;
}