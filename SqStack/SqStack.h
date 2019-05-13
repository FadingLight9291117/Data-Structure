/*
	˳��ջ
*/
#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100
typedef struct
{
	int data[MAX_SIZE];
	int top;
}SqStack;

//��ʼ��ջ������һ����ջ����ջ��ָ��ָ��-1
void InitStack(SqStack*& s)
{
	s = (SqStack*)malloc(sizeof(SqStack));
	s->top = -1;
}
//����ջ
void DestroyStack(SqStack*& s)
{
	free(s);
}
//�ж�ջ��
bool StackEmpty(SqStack* s)
{
	return s->top == -1;
}
//��ջ
bool Push(SqStack*& s, int e)
{
	s->top++;
	s->data[s->top] = e;
	return true;
}
//��ջ
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
//ȡջ��Ԫ��
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