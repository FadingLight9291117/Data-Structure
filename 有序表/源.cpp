#include<stdio.h>
#include"单链表.h"
#include"顺序表.h"

/*
	======================
	有序顺序表的二路归并算法
	======================
*/
void UnionSqList(SqList* L1, SqList* L2, SqList*& L)
{
	L = (SqList*)malloc(sizeof(SqList));
	L->length = 0;
	int i = 0, j = 0, k = 0;
	while (i < L1->length && j < L2->length)
	{
		if (L1->data[i] < L2->data[j])
		{
			L->data[k] = L1->data[i];
			k++;
			i++;
		}
		else
		{
			L->data[k] = L2->data[j];
			k++;
			j++;
		}
	}
	while (i < L1->length)
	{
		L->data[k] = L1->data[i];
		i++;
		k++;
	}
	while (j < L2->length)
	{
		L->data[k] = L2->data[j];
		k++;
		j++;
	}
	L->length = k;
}

/*
	====================
	有序链表的二路归并算法
	====================
*/
void UnionLinkList(LinkList* L1, LinkList* L2, LinkList*& L)
{
	LinkList* p1 = L1->next;
	LinkList* p2 = L2->next;
	LinkList* p;
	LinkList* r;//指向L的尾节点
	L = (LinkList*)malloc(sizeof(LinkList));
	L->next = NULL;
	r = L;
	while (p1 != NULL && p2 != NULL)
	{
		if (p1->data < p2->data)
		{
			p = (LinkList*)malloc(sizeof(LinkList));
			p->data = p1->data;
			p->next = NULL;
			r->next = p;
			r = p;
			p1 = p1->next;
		}
		else
		{
			p = (LinkList*)malloc(sizeof(LinkList));
			p->data = p2->data;
			p->next = NULL;
			r->next = p;
			r = p;
			p2 = p2->next;
		}
	}
	while (p1 != NULL)
	{
		p = (LinkList*)malloc(sizeof(LinkList));
		p->data = p1->data;
		p->next = NULL;
		r->next = p;
		r = p;
		p1 = p1->next;
	}
	while (p2 != NULL)
	{
		p = (LinkList*)malloc(sizeof(LinkList));
		p->data = p2->data;
		p->next = NULL;
		r->next = p;
		r = p;
		p2 = p2->next;
	}

}
int main()
{
	/*SqList* L;
	int a[4] = { 2,4,3,6 };
	CreateSqList(L, a, 4);
	DispSqList(L);
	getchar();
	LinkList* L1;
	CreateLinkList(L1, a, 4);
	DispLinkList(L1);*/
	//顺序表二路归并
	/*SqList* L1, * L2, * L;
	int a[4] = { 2,4,5,2 };
	CreateSqList(L1, a, 4);
	int b[5] = { 2,6,9,11,3 };
	CreateSqList(L2, b, 5);
	UnionSqList(L1, L2, L);
	DispSqList(L1);
	DispSqList(L2);
	DispSqList(L);*/
	//链表二路归并
	LinkList* L1, * L2, * L;
	int a[4] = { 2,4,5,2 };
	CreateLinkList(L1, a, 4);
	int b[5] = { 2,6,9,11,3 };
	CreateLinkList(L2, b, 5);
	UnionLinkList(L1, L2, L);
	DispLinkList(L1);
	DispLinkList(L2);
	DispLinkList(L);
}