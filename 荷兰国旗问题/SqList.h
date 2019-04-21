/*
	=============2019.4.12===============
	1.定义顺序表结构，数据元素int类型；
	2.定义顺序表的基本运算。
	=====================================
*/
#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100

typedef struct
{
	int data[MAX_SIZE];
	int length;
}SqList;

//1. 建立顺序表 
//整体创建顺序表
//引用符号“&”放在形参L的前面。
//输出型参数均使用“&”，不论参数值是否改变 
void CreateList(SqList*& L, int a[], int n)
{
	int i;
	L = (SqList*)malloc(sizeof(SqList));
	for (i = 0; i < n; i++)
	{
		L->data[i] = a[i];
	}
	L->length = n;
}

//2.顺序表基本运算算法 
//（1）初始化线性表InitList(L) 
//该运算的结果时构造一个空的线性表L。实际上只需将length成员设置为0即可。 
void InitList(SqList*& L)
{
	L = (SqList*)malloc(sizeof(SqList));
	L->length = 0;
}
//（2）销毁线性表DestroyList(L)
//该运算的结果时释放线性表L占用的内存空间。 
void DestoryList(SqList*& L)
{
	free(L);
	L = NULL;
}
//（3）判断是否为空表ListEmpty(L)
//该运算返回一个值表示L是否为空表。若为空表，
//则返回true，否则返回false 
bool ListEmpty(SqList* L)
{
	return (L->length == 0);
}
//(4)求线性表的表长Listlength(L)
//该运算返回顺序表L的长度。实际只需返回length成员的值即可。 
int ListLength(SqList * L)
{
	return L->length;
}
//(5)输出线性表DispList(L)
//该运算当线性表L不为空时，顺序显示L中各元素的值。 
void DispSqList(SqList * L)
{
	int i;
	if (ListEmpty(L))	return;
	for (i = 0; i < L->length; i++)
	{
		printf("%d", L->data[i]);
	}
	printf("\n");
}
//（6）求某个数据元素的值GetElem(L,i,e)
//该运算返回L中第i(1<=i<=ListLength(L))的元素的值，存放在e中 
bool GetElem(SqList * L, int i, int& e)
{
	if (i<1 || i>L->length)	return false;
	e = L->data[i];
	return true;
}
//（7）按元素值查找LocateElem(L,e)
//该运算查找第一个值域与e相等的元素的逻辑位序。若这样的元素不存在，则返回值为0 
int LocateElem(SqList * L, int e)
{
	int i = 0;
	while (i <= L->length && L->data[i] != e)
	{
		i++;
	}
	if (i >= L->length) return 0;
	return i + 1;
}
//（8）插入数据元素ListInsert（L,i,e)
//该运算在顺序表L的第i(1<=i<=ListLength(L)+1)个位置上插入新的元素e。 
bool ListInsert(SqList * &L, int i, int e)
{
	int j;
	if (i<1 || i>L->length)	return false;
	i--;
	for (j = L->length; j > i; j--)
	{
		L->data[j] = L->data[j - 1];
	}
	L->data[i] = e;
	L->length++;
	return true;
}
//（ 9）删除数据元素ListDelete(L,i,e)
//该运算删除顺序表L的第i(i<=i<=ListLength(L))个元素 
bool ListDelete(SqList * &L, int i, int& e)
{
	int j;
	if (i<1 || i>L->length)	return false;
	i--;
	e = L->data[i];
	for (j = i; j < L->length; j++)
	{
		L->data[j] = L->data[j + 1];
	}
	L->length--;
	return true;
}

/*
	=================2019.4.12================
	问题：删除顺序表中所有值为x的数据元素。
	要求：时间复杂度O(n),空间复杂度为O(1)
					两种算法。
	==========================================
*/
/*
	解法一：扫描顺序表L，重建A只包含不等于x的元素
*/
void delnode1(SqList * &L, int x)
{
	int i = 0;
	int k = 0;					//k值记录保留的元素的个数 
	while (i < L->length)
	{
		if (L->data[i] != x)
		{
			L->data[k] = L->data[i];
			k++;
		}
		i++;
	}
	L->length = k;
}
/*
	解法二：将不为x的元素前移k个位置，最后修改L的长度。
*/
void delnode2(SqList * &L, int x)
{
	int i = 0;
	int k = 0;					//k值记录删除的元素的个数 
	while (i < L->length)
	{
		if (L->data[i] == x)
		{
			k++;
		}
		else
		{
			L->data[i - k] = L->data[i];
		}
		i++;
	}
	L->length -= k;
}



/*
	问题：
		设顺序表中有10个整数。设计算法，以第一个元素为分界线（基准），
	将所有小于等于它的元素移到该元素的前面，将所有大于它的元素移到该
	元素的后面 。
		----  --------------------------------------
		| x | |				无序整数序列		        |
		----  --------------------------------------
							 |
							\/
		-------- -------   ----	 ------------------
		|		<=x		| | x |	 |		>x	       |
		-------- -------   ----	 ------------------
*/
/*
	两种解法move1和move2
	都是
			j从后向前找<=pivot的元素
			i从前向后找>pivot的元素
	不同点为:
			move1需要两个记录a,b交换：temp=a;a=b;b=temp;
			move2多个相邻记录连续交换。
*/
void move1(SqList * &L)
{
	int i, j;
	int pivot;
	int temp;
	i = 0;
	j = L->length - 1;
	pivot = L->data[0];					//以data[0]为基准 
	while (i < j)
	{
		while (i<j && L->data[j]>pivot)
		{
			j--;						//从后往前扫描，找到一个<=pivot的元素 
		}
		while (i < j && L->data[i] <= pivot)	//从前往后扫描，找到一个>pivot的元素 
		{
			i++;
		}
		if (i < j)
		{
			temp = L->data[i];			//L->data[i]和L->data[j]互换 
			L->data[i] = L->data[j];
			L->data[j] = temp;
		}
	}
	temp = L->data[i];					//L->data[0]和L->data[j]互换 
	L->data[i] = pivot;
	L->data[0] = temp;
}
//解法2 
void move2(SqList * &L)
{
	int i, j;
	int pivot;
	i = 0;
	j = L->length - 1;
	pivot = L->data[0];	//以data[0]为基准 
	while (i < j)
	{
		while (i<j && L->data[j]>pivot)	//从后往前扫描，找到一个<=pivot的元素 
		{
			j--;
		}
		L->data[i] = L->data[j];			//将其放入data[i]处 
		while (i < j && L->data[i] <= pivot)	//从前往后扫描，找到一个>pivot的元素 
		{
			i++;
		}
		L->data[j] = L->data[i];			//将其放入data[j]处 
	}
	L->data[i] = pivot;					//放置基准 
}


