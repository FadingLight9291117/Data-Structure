/*
	顺序栈
*/
#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100
typedef struct
{
	int data[MAX_SIZE];
	int top;
}SqStack;

//初始化栈，建立一个空栈，将栈顶指针指向-1
void InitStack(SqStack*& s)
{
	s = (SqStack*)malloc(sizeof(SqStack));
	s->top = -1;
}
//销毁栈
void DestroyStack(SqStack*& s)
{
	free(s);
}
//判断栈空
bool StackEmpty(SqStack* s)
{
	return s->top == -1;
}
//进栈
bool Push(SqStack*& s, int e)
{
	s->top++;
	s->data[s->top] = e;
	return true;
}
//出栈
bool Pop(SqStack*& s,int &e)
{
	if (StackEmpty(s))
	{
		return false;
	}
	else
	{
		e = s->data[s->top];
		s->top--;
		return true;
	}
}
//取栈顶元素
bool GetTop(SqStack*& s, int& e)
{
	if (StackEmpty(s))
	{
		return false;
	}
	else
	{
		e = s->data[s->top];
		return true;
	}
}