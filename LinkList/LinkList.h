/*
	==================2019.4.13===============
	1.定义单链表（带头结点）结构，数据元素int类型；
	2.定义单链表的基本运算。
	==========================================
*/
#include<stdlib.h>
#include<stdio.h>
typedef struct LNode {	//定义单链表节点类型 
	int data;
	struct LNode* next;	//指向后继节点 
}LinkList;

//1.建立单链表
//整体建立单链表，有两种方法，头插法和尾插法 
// （1）头插法建表front
void CreateListF(LinkList*& L, int a[], int n)
{
	LinkList* node;
	int i;
	L = (LinkList*)malloc(sizeof(LinkList));
	L->next = NULL;				//创建头节点，其next域置为NULL 
	for (i = 0; i < n; i++)			//循环建立数据节点 
	{
		node = (LinkList*)malloc(sizeof(LinkList));
		node->data = a[i];	//创建数据节点node; 
		node->next = L->next;	//将*node插在头节点后 
		L->next = node;
	}
}
//（2）尾插法建立单链表rear
void CreateListR(LinkList*& L, int a[], int n)
{
	LinkList* r;
	LinkList* node;
	int i;
	L = (LinkList*)malloc(sizeof(LinkList));	//创建头节点 
	L->next = NULL;
	r = L;									//r始终指向尾节点，开始时指向头节点 
	for (i = 0; i < n; i++)						//循环建立数据节点 
	{
		node = (LinkList*)malloc(sizeof(LinkList));
		node->data = a[i];					//创建数据节点 
		r->next = node;						//将*node插入*r之后 
		r = node;
	}
	r->next = NULL;							//尾节点next域置为NULL； 
}

//单链表的基本运算
//（1）初始化单链表
void InitList(LinkList*& L)
{
	L = (LinkList*)malloc(sizeof(LinkList));
	L->next = NULL;
}
//(2)销毁单链表
void DestroyList(LinkList*& L)
{
	LinkList* pre, * post;//post指向pre的后一个节点 
	int i;
	pre = L;				//初始时pre指向头节点 
	post = pre->next;
	while (post != NULL)	//扫描单链表 
	{
		free(pre);		//释放前一个节点pre 
		pre = post;		//pre指向后一个节点post 
		post = post->next;//post指向后一个节点 
	}
	free(pre);			//最后post指向null，释放pre 
}
//（3)判断单链表是否为空 
bool ListEmpty(LinkList* L)
{
	return L->next == NULL;
}
//(4)求单链表的长度
int ListLength(LinkList* L)
{
	int l = 0;
	LinkList* p = L;
	while (p->next != NULL)
	{
		l++;
		p = p->next;
	}
	return l;
}
//(5)输出单链表
void DispList(LinkList* L)
{
	LinkList* p = L->next;
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}
//(6)求单链表中位置i的元素值
bool GetElem(LinkList* L, int i, int& e)
{
	LinkList* p = L;
	int j = 0;
	while (i < j && p != NULL)
	{
		j++;
		p = p->next;
	}
	if (p == NULL)
	{
		return false;
	}
	else
	{
		e = p->data;
		return true;
	}
}
//(7)按元素值查找
int LocateElem(LinkList* L, int e)
{
	LinkList* p = L->next;
	int i = 1;
	while (p != NULL)
	{
		if (p->data == e)
		{
			return i;
		}
		p = p->next;
		i++;
	}
	return 0;
}
//（8)插入数据元素
bool ListInsert(LinkList*& L, int i, int e)
{
	LinkList* p = L;
	LinkList* a;
	int j = 0;
	while (j < i - 1 && p != NULL)
	{
		j++;
		p = p->next;
	}
	if (p == NULL || j != i - 1)
	{
		return false;
	}
	else
	{
		a = (LinkList*)malloc(sizeof(LinkList));
		a->data = e;
		a->next = p->next;
		p->next = a;
		return true;
	}
}
//（9）删除数据节点
bool ListDelete(LinkList*& L, int i, int& e)
{
	LinkList* p = L;
	LinkList* a;
	int j = 0;
	while (j < i - 1 && p != NULL)
	{
		p = p->next;
		j++;
	}
	if (p == NULL || j != i - 1)
	{
		return false;
	}
	else
	{
		a = p->next;
		if (a == NULL)
		{
			return false;
		}
		e = a->data;
		p->next = a->next;
		free(a);
		return true;
	}
}


/*
	==============2019.4.14=================
	问题：
		设计一个算法，删除单链表中元素值最大
		的元素（假设最大值唯一）
	========================================
*/
void delmaxnode(LinkList*& L)
{
	LinkList* p = L->next, * pre = L, * maxp = p, * maxpre = pre;//p和pre时一对同步指针 
	while (p != NULL)
	{
		if (p->data > maxp->data)						//比较p的值和最大值 
		{
			maxp = p;									//若更大，更改maxp和maxpre 
			maxpre = pre;
		}
		p = p->next;									//p和pre同步后移 
		pre = pre->next;
	}
	maxpre->next = maxp->next;					//删除maxp 
	free(maxp);									//释放maxp 
}

/*
	===============2019.4.14=========================
	问题：
		有一个带头结点的单链表（至少有一个数据节点），
		设计一个算法，使其数据元素递增有序排列
	=================================================
*/
void sort(LinkList*& L)
{
	LinkList* p, * pre, * post;
	p = L->next->next;
	L->next->next = NULL;
	while (p != NULL)
	{
		post = p->next;
		pre = L;
		while (pre->next != NULL && p->data > pre->next->data)
		{
			pre = pre->next;
		}
		p->next = pre->next;
		pre->next = p;
		p = post;
	}
}