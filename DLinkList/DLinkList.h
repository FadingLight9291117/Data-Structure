/*
	=================2019.4.24=========================
	1.定义双链表（带头结点）的数据结构，数据元素类型为int；
	2.相关运算。
	===================================================
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct DNode
{
	int data;
	struct DNode* prior;
	struct DNode* next;
}DLinkList;
//1.建立双链表
//头插法建表
void CreateDLinkListF(DLinkList*& L, int a[], int length)
{
	DLinkList* p;
	L = (DLinkList*)malloc(sizeof(DLinkList));
	L->prior = NULL;
	L->next = NULL;
	for (int i = 0; i < length; i++)
	{
		p = (DLinkList*)malloc(sizeof(DLinkList));
		p->data = a[i];
		p->next = L->next;
		if (p->next != NULL)
		{
			p->next->prior = p;
		}
		L->next = p;
		p->prior = L;
	}
}
//尾插法建表
void CreateDLinkListR(DLinkList*& L, int a[], int length)
{
	DLinkList* p;
	DLinkList* r;   //尾指针(rear)
	L = (DLinkList*)malloc(sizeof(DLinkList));
	L->next = NULL;
	L->prior = NULL;
	r = L;
	for (int i = 0; i < length; i++)
	{
		p = (DLinkList*)malloc(sizeof(DLinkList));
		p->data = a[i];
		p->prior = r;
		r->next = p;
		r = p;
	}
	r->next = NULL;
}


//输出双链表
void DispList(DLinkList* L)
{
	DLinkList* p = L->next;
	while (p != NULL)
	{
		printf("%d", p->data);
		p = p->next;
	}
	printf("\n");
}
//2.插入数据
bool ListInsert(DLinkList*& L, int i, int e)
{
	DLinkList* pre = L;
	int j = 0;
	while (pre != NULL & j < i - 1)
	{
		pre = pre->next;
		j++;
	}
	if (pre != NULL)
	{
		DLinkList* p = (DLinkList*)malloc(sizeof(DLinkList));
		p->data = e;
		if (pre->next == NULL)
		{
			pre->next = p;
			p->prior = pre;
			p->next = NULL;
			return true;
		}
		p->next = pre->next;
		pre->next->prior = p;
		pre->next = p;
		p->prior = pre;
		return true;
	}
	return false;
}
//3.删除数据
bool ListDelete(DLinkList*& L, int i, int& e)
{
	DLinkList* pre = L;
	int j = 0;
	while (pre != NULL && j < i - 1)
	{
		pre = pre->next;
		j++;
	}
	if (pre != NULL)
	{
		if (pre->next == NULL)
			return false;
		DLinkList * p = pre->next;
		pre->next = p->next;
		if (p->next != NULL)
		{
			p->next->prior = pre;
		}
		e = p->data;
		free(p);
		return true;
	}
	return false;

}