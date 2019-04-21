/*
	问题：
		设有一个条形序列，每个条块为红（0），白（1），兰（2）三种颜色中的一种。
		假设该序列采用顺序表（单链表）存储，设计一个时间复杂度为O(n)的算法，使
		得这些条块按红白兰的顺序排好，即排成荷兰国旗的图案
*/
#include<stdio.h>
#include"LinkList.h"
#include"SqList.h"
//顺序表
/*
	初始时i指向表头，j指向表尾，k指向表头
	判断元素k值，为0和元素i互换，然后i向后移动，k向后移动；
	为1时，k向后移动；为2时k和j互换，k保持不变，j向后移动。
	因为k之前的元素都已排好序。
*/
void moveh1(SqList*& L)
{
	int i = 0;
	int j = L->length - 1;
	int k = 0;
	int temp;
	while (k <= j)
	{
		switch (L->data[k])
		{
		case 0:
			temp = L->data[k];
			L->data[k] = L->data[i];
			L->data[i] = temp;
			i++;
			k++;
			break;
		case 1:
			k++;
			break;
		case 2:
			temp = L->data[k];
			L->data[k] = L->data[j];
			L->data[j] = temp;
			j--;
			break;
		}
	}
}
//链表
/*
	使用3个单链表L,L1,L2。L储存0，L1储存1，L2储存2.
	遍历完后三个单链表连接。
*/
void moveh2(LinkList*& L)
{
	LinkList* p = L->next;
	L->next = NULL;
	LinkList* r = L;
	LinkList* L1 = NULL, * r1 = NULL;
	LinkList* L2 = NULL, * r2 = NULL;
	while (p != NULL)
	{
		switch (p->data)
		{
		case 0:
			r->next = p;
			r = p;
			p = p->next;
			break;
		case 1:
			if (L1 == NULL)
			{
				L1 = p;
				r1 = p;
				p = p->next;
			}
			else
			{
				r1->next = p;
				r1 = p;
				p = p->next;
			}
			break;
		case 2:
			if (L2 == NULL)
			{
				L2 = p;
				r2 = p;
				p = p->next;
			}
			else
			{
				r2->next = p;
				r2 = p;
				p = p->next;
			}
			break;
		default:
			break;
		}
		if (r2 != NULL)
		{
			r2->next = NULL;
		}
		r->next = L1;
		r1->next = L2;
	}

}
int main()
{
	SqList* L;
	LinkList* L1;
	int a[13] = { 1,2,0,0,1,2,1,0,2,2,1,0,1 };
	CreateList(L, a, 13);
	DispSqList(L);
	moveh1(L);
	DispSqList(L);

	CreateListR(L1, a, 13);
	DispLinList(L1);
	moveh2(L1);
	DispLinList(L1);
}