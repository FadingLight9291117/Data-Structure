/*
	问题：两个等长的升序有序顺序表的，找出两个序列A和B的中位数。
	分析	：	1.分奇偶找中位数序号n；
			2.逐一比较直到n为止。
*/
#include<stdio.h>
#include"顺序表.h"
int Max(int a, int b)
{
	return a >= b ? 1 : 0;
}
int M_Search(SqList* L1, SqList* L2)
{
	int len = L1->length*2;
	int middle;
	int result = 0;;
	if (len % 2 == 0)		//分奇偶，找中位数序号
	{
		middle = len / 2;
	}
	else
	{
		middle = len / 2 + 1;
	}
	//printf("%d", middle);
	int m = 0, n = 0;
	for (int i = 0; i < middle; i++)	//循环遍历，找出第len个数
	{
		if (Max(L1->data[m], L2->data[n]))
		{
			result = L2->data[n];
			n++;			
		}
		else
		{
			result = L1->data[m];
			m++;
		}
	}
	return result;
}
int main()
{
	int a1[5] = { 11,13,15,17,19 };
	int a2[5] = { 2,4,6,8,20 };
	SqList* L1, * L2;
	CreateSqList(L1, a1, 5);
	CreateSqList(L2, a2, 5);
	printf("%d", M_Search(L1, L2));
}