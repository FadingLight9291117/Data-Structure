#include<stdio.h>
#include"LinkList.h"
void testCreateLinkListF()
{
	int a[4] = { 2,5,2,8 };
	LinkList* L;
	CreateLinkListF(L, a, 4);
	DispLinkList(L);
}
void testCreateLinkListR()
{
	int a[4] = { 2,5,2,8 };
	LinkList* L;
	CreateLinkListR(L, a, 4);
	DispLinkList(L);
}
int main()
{
	//testCreateLinkListF();
	testCreateLinkListR();
}