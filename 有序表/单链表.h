//有序单链表
#include<stdlib.h>
#include<stdio.h>
typedef struct LNode {	//定义单链表节点类型 
	int data;
	struct LNode* next;	//指向后继节点 
}LinkList;

void LinkListInsert(LinkList*& L, int e)
{
	LinkList* pre, * p;
	pre = L;
	p = L->next;
	LinkList* s = (LinkList*)malloc(sizeof(LinkList));
	s->data = e;
	while (p != NULL&&e>p->data)
	{
		pre = p;
		p = p->next;
	}
	pre->next = s;
	s->next = p;
}
void CreateLinkList(LinkList*& L, int a[], int n)
{
	L = (LinkList*)malloc(sizeof(LinkList));
	L->next = NULL;
	for (int i = 0; i < n; i++)
	{
		LinkListInsert(L, a[i]);
	}
}
void DispLinkList(LinkList* L)
{
	LinkList* p = L->next;
	while (p != 0)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}