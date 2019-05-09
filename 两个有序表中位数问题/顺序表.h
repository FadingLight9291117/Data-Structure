//ÓÐÐòË³Ðò±í
#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100

typedef struct
{
	int data[MAX_SIZE];
	int length;
}SqList;

void SqListInsert(SqList*& L,int e)
{
	int i=0, j=0;
	while (i<L->length && e>L->data[i])
	{
		i++;
	}
	for ( j = L->length; j > i; j--)  //×¢Òâ--
	{
		L->data[j] = L->data[j - 1];
	}
	L->data[i] = e;
	L->length++;
}
void CreateSqList(SqList*& L, int a[], int n)
{
	L = (SqList*)malloc(sizeof(SqList));
	L->length =0;
	for (int i = 0; i < n; i++)
	{
		SqListInsert(L, a[i]);
	}
}
void DispSqList(SqList* L)
{
	for (int i = 0; i < L->length; i++)
	{
		printf("%d ", L->data[i]);
	}
	printf("\n");
}