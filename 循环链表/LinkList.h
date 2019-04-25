/*
	循环单链表链表
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct LNode
{
	int data;
	struct LNode* next;
}LinkList;

//头插法创建循环单链表
void CreateLinkListF(LinkList*& L, int a[], int length)
{
	L = (LinkList*)malloc(sizeof(LinkList));
	L->next = L;
	LinkList* p;
	for (int i = 0; i < length; i++)
	{
		p = (LinkList*)malloc(sizeof(LinkList));
		p->data = a[i];
		p->next = L->next;
		L->next = p;
	}
}
//尾插法建表
void CreateLinkListR(LinkList*& L, int a[], int length)
{
	LinkList* p, * r;
	L = (LinkList*)malloc(sizeof(LinkList));
	r = L;
	L->next = NULL;
	for (int i = 0; i < length; i++)
	{
		p = (LinkList*)malloc(sizeof(LinkList));
		p->data = a[i];
		r->next = p;
		r = p;
	}
	r->next = L;
}
//输出单链表
void DispLinkList(LinkList* L) {
	LinkList* p = L->next;
	while (p != L)
	{
		printf("%d", p->data);
		p = p->next;
	}
	printf("\n");
}