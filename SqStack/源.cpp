#include<stdio.h>
#include"SqStack.h"
/*利用栈判断字符串是否是对称串	*/
bool symmetr(int a[])
{
	SqStack* s;
	int e;
	InitStack(s);
	for (int i = 0; a[i]!='\0'; i++)
	{
		Push(s, a[i]);
	}
	for (int i = 0; a[i]!='\0'; i++)
	{
		Pop(s, e);
		if (e != a[i])
		{
			DestroyStack(s);		//完成后销毁栈
			return false;
		}
	}
	DestroyStack(s);
	return true;
}
int main()
{
	int a[6] = { 1,2,1,1,1 };
	printf("%d", symmetr(a));
}