/*
	两个二维表的自然连接问题
*/
#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 10
typedef struct Node1
{
	int data[MAX_SIZE];
	struct Node1* next;
}DList;
typedef struct Node2
{
	int row, col;
	struct Node1* next;
}HList;
//交互式创建单链表
void CreateTable(HList*& L)
{
	int row, col;
	DList* p, * r;
	printf("请输入行数和列数:\n");
	printf("row:");
	scanf("%d", &row);
	printf("column:");
	scanf("%d", &col);
	L = (HList*)malloc(sizeof(HList));
	L->col = col;
	L->row = row;
	L->next = NULL;
	for (int i = 0; i < row; i++)
	{
		printf("请输入第%d行：\n", i + 1);
		p = (DList*)malloc(sizeof(DList));
		p->next = NULL;
		for (int j = 0; j < col; j++)
		{
			scanf("%d", &p->data[j]);
		}
		if (L->next == NULL)
		{
			L->next = p;
			r = p;
		}
		else
		{
			r->next = p;
			r = p;
		}
	}
	r->next = NULL;//最后尾指针所指元素next域置NULL
}
//销毁线性表
void DestroyTable(HList*& L)
{
	DList* pre = L->next;
	DList* p = pre->next;
	while (p != NULL)
	{
		free(pre);
		pre = p;
		p = p->next;
	}
	free(pre);
	free(L);
}
//输出单链表
void DispTable(HList* L)
{
	DList* p = L->next;
	for (int i = 0; i < L->row; i++)
	{
		for (int j = 0; j < L->col; j++)
		{
			printf("%d ", p->data[j]);
		}
		printf("\n");
		p = p->next;
	}
}
//表连接算法
void LinkTables(HList* h1, HList* h2, HList*& h)
{
	int i, j;
	DList* p1 = h1->next;
	DList* p2;
	DList* p, * r;
	printf("连接的字段是:第1个表序号，第二个表序号：");
	scanf("%d%d", &i, &j);
	//printf("%d %d", i, j);此处导致问题
	h = (HList*)malloc(sizeof(HList));
	h->row = 0;
	h->col = h1->col + h2->col;
	h->next = NULL;

	while (p1 != NULL)
	{
		p2 = h2->next;
		while (p2 != NULL)
		{
			if (p1->data[i - 1] == p2->data[j - 1])
			{
				p = (DList*)malloc(sizeof(DList));
				for (int k = 0; k < h1->col; k++)
				{
					p->data[k] = p1->data[k];
				}
				for (int k = 0; k < h2->col; k++)
				{
					p->data[h1->col + k] = p2->data[k];
				}
				if (h->next == NULL)
				{
					h->next = p;
				}
				else
				{
					r->next = p;
				}
				r = p;
				h->row++;
			}
			p2 = p2->next;
		}
		p1 = p1->next;
	}
	r->next = NULL;
}
int main()
{
	HList* L1, * L2, * L;
	CreateTable(L1);
	DispTable(L1);
	CreateTable(L2);
	DispTable(L2);
	//printf("%d %d", L1->next->data[1], L2->next->next->data[1]);
	LinkTables(L1, L2, L);
	DispTable(L);
}