/*
	Ë³Ðò±í²âÊÔ³ÌÐò
*/
#include"SqList.h"
void test()
{
	SqList* list;
	int a[] = { 2,4,1,2,3 };
	CreateList(list, a, 5);
	DispList(list);
}

void testMove()
{
	SqList* L1, * L2;
	int a[10] = { 5,2,8,1,2,6,5,3,9,4 };
	CreateList(L1, a, 10);
	CreateList(L2, a, 10);
	DispList(L1);
	move1(L1);
	DispList(L1);
	printf("============\n");
	DispList(L2);
	move2(L2);
	DispList(L2);
}
void testDelnode()
{
	SqList* L;
	int a[8] = { 2,2,3,5,3,6,6,3 };
	int x;
	CreateList(L, a, 8);
	DispList(L);
	printf("É¾³ýx=?\n");
	scanf_s("%d", &x);
	delnode1(L, x);
	DispList(L);
}

int main()
{
	test();
	testMove();
	testDelnode();
}