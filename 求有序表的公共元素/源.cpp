/*
	���ö�·�鲢˼·������˳�������Ĺ���Ԫ��
	���������������������õ�����ha��hc�洢��
	����ͬһ���������в������ظ���Ԫ�أ���
*/
#include<stdio.h>
#include"������.h"
void InterSect(LinkList* ha, LinkList* hb, LinkList*& hc)
{
	hc = (LinkList*)malloc(sizeof(LinkList));
	hc->data = NULL;
	LinkList* r = hc,*p;
	LinkList* pa=ha->next, * pb=hb->next;
	while (pa != NULL && pb != NULL)
	{
		if (pa->data == pb->data)
		{
			p = (LinkList*)malloc(sizeof(LinkList));
			p->data = pa->data;
			r->next = p;
			r = p;
			pa = pa->next;
			pb = pb->next;
		}
		else if (pa->data < pb->data)
		{
			pa = pa->next;
		}
		else
		{
			pb = pb->next;
		}
	}
	r->next = NULL;
}
int main()
{
	int a[4] = { 1,2,5,6 };
	int b[6] = { 2,8,10,3,6,4 };
	LinkList* L1;
	LinkList* L2;
	LinkList* L;
	CreateLinkList(L1,a,4);
	CreateLinkList(L2, b, 6);
	InterSect(L1, L2, L);
	DispLinkList(L);
}