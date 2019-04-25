#include<stdio.h>
#include"DLinkList.h"
//≤‚ ‘Ω®±Ì
void testCreateList()
{
	//≤‚ ‘Ω®±Ì
	DLinkList* L1;
	DLinkList* L2;
	int a[4] = { 2,4,5,2, };
	CreateDLinkListF(L1, a, 4);
	CreateDLinkListR(L2, a, 4);
	DispList(L1);
	DispList(L2);
}
//≤‚ ‘≤Â»Î
void testInsert()
{
	DLinkList* L;
	int a[4] = { 2,4,5,2 };
	CreateDLinkListR(L, a, 4);
	DispList(L);
	ListInsert(L, 5, 3);
	DispList(L);
}
//≤‚ ‘…æ≥˝
void testDelete()
{
	DLinkList* L;
	int a[4] = { 2,5,2,1 };
	CreateDLinkListR(L, a, 4);
	DispList(L);
	int e=-1;
	ListDelete(L, 5, e);
	DispList(L);
	printf("%d", e);
}
int main()
{
	//testCreateList();
	testInsert();
	//testDelete();
}