/*单链表算法测试程序*/
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
void testReverse() {
	LinkList* L;
	int e;
	int a[] = { 2,4,1,2,22,4,5,21,2 };
	CreateListR(L, a, 9);
	DispList(L);
	reverse(L);
	DispList(L);
}
void testSplit()
{
	int a[8] = { 1,2,3,4,5,6,7,8 };
	LinkList* L, * L1, * L2;
	CreateListR(L, a, 8);
	DispList(L);
	split(L, L1, L2);
	DispList(L1);
	DispList(L2);
}
int main()
{
	//testDelmaxnode();
	//testSort();
	//testReverse();
	testSplit();
	return 0;
}

