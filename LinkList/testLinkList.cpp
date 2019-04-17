#include"LinkList.h"
void test()
{
	LinkList* L;
	int e;
	int a[] = { 2,4,1,2,22,4,5,21,2 };
	CreateListR(L, a, 9);
	DispList(L);
	delmaxnode(L);
	DispList(L);
}
void testDelmaxnode()
{
	LinkList* L;
	int e;
	int a[] = { 2,4,1,2,22,4,5,21,2 };
	CreateListR(L, a, 9);
	DispList(L);
	delmaxnode(L);
	DispList(L);
}
void testSort()
{
	LinkList* L;
	int e;
	int a[] = { 2,4,1,2,22,4,5,21,2 };
	CreateListR(L, a, 9);
	DispList(L);
	sort(L);
	DispList(L);
}
int main()
{
	//testDelmaxnode();
	testSort();
	return 0;
}

