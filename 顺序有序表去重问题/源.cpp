/*
	问题：去除有序表中重复元素
	分析：因为有序，重复元素邻近；k记录重复元素个数，其余元素向前平移类似于前面。
*/
#include<stdio.h>
#include"顺序表.h"

int main()
{
	int a[8] = { 1,1,2,2,2,3,3,3 };
	SqList* L;
	CreateSqList(L, a, 8);
	int k = 1;
	for (int i = 1; i < L->length; i++)
	{
		if (L->data[i] != L->data[i - 1])
		{
			k++;
			L->data[k-1] = L->data[i];
		}
	}
	L->length = k;
	DispSqList(L);
}