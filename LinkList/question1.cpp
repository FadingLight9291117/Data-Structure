
/*
	问题：
		一个带头结点的单链表L，每个节点由单个数字，小写字母或大写字母组成。
		设计算法将其拆分成三个带头结点的单链表L1，L2,L3，L1包含所有数字，
		L2包含所有小写字母,L3包含所有小写字母。
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct LNode
{
	char data;
	struct LNode* next;
}LinkList;
void createList(LinkList*& L, char a[], int length)
{
	LinkList* p;
	L = (LinkList*)malloc(sizeof(LinkList));
	L->next = NULL;
	for (int i = 0; i < length; i++)
	{
		p = (LinkList*)malloc(sizeof(LinkList));
		p->data = a[i];
		p->next = L->next;
		L->next = p;
	}
}
void dispList(LinkList* L)
{
	LinkList* p;
	p = L->next;
	while (p != NULL)
	{
		printf("%c ", p->data);
		p = p->next;
	}
	printf("\n");
}
void ListInsertF(LinkList*& L, char a)
{
	LinkList* p = (LinkList*)malloc(sizeof(LinkList));
	p->data = a;
	p->next = L->next;
	L->next = p;
}
void main()
{
	char a[10] = { 'a','1','S','4','e','4','V','n','5','p' };
	LinkList* L;
	LinkList* L1, * L2, * L3;
	createList(L, a, 10);
	dispList(L);
	createList(L1, NULL, 0);
	createList(L2, NULL, 0);
	createList(L3, NULL, 0);
	for (int i = 0; i < 10; i++)
	{
		if ('0' <= a[i] && a[i] <= '9')
		{
			ListInsertF(L1, a[i]);
		}
		else if ('a' <= a[i] && a[i] <= 'z')
		{
			ListInsertF(L2, a[i]);
		}
		else if ('A' <= a[i] && a[i] <= 'Z')
		{
			ListInsertF(L3, a[i]);
		}
	}
	printf("L1:\n");
	dispList(L1);
	printf("L2:\n");
	dispList(L2);
	printf("L3:\n");
	dispList(L3);
}