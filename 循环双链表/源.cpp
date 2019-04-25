#include<stdio.h>
#include"Ñ­»·Ë«Á´±í.h"
void testCreateDLinkListF()
{
	int a[4] = { 2,6,3,9 };
	DLinkList* L;
	CreateDLinkListF(L, a, 4);
	DispDLinkList(L);
}
void testCreateDLinkListR()
{
	int a[4] = { 2,6,3,9 };
	DLinkList* L;
	CreateDLinkListR(L, a, 4);
	DispDLinkList(L);
}
int main()
{
	//testCreateDLinkListF();
	testCreateDLinkListR();
}