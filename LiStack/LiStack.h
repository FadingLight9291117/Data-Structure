/*
	链栈
*/
#include<stdio.h>
#include<stdlib.h>
//链栈的定义
typedef struct linknode
{
	char data;
	struct linknode* next;
}LiStack;

//初始化栈
void InitStack(LiStack*& s)
{
	s = (LiStack*)malloc(sizeof(LiStack));
	s->next = NULL;
}
void DestroyStack(LiStack*& s)
{
	LiStack* p = s, * q = s->next;
	if (q != NULL)
	{
		free(p);
		p = q;
		q = q->next;
	}
	free(p);
}
//判断栈是否为空
bool StackEmpty(LiStack* s)
{
	return s->next == NULL;
}
//进栈
void Push(LiStack*& s, char e)
{
	LiStack* p = (LiStack*)malloc(sizeof(LiStack));
	p->data = e;
	p->next = s->next;
	s->next = p;
}
//出栈
bool Pop(LiStack*& s, int& e)
{
	LiStack* p = s->next;
	s->next = p->next;
	e = p->data;
	free(p);
	return true;
}
//取栈顶元素
bool GetTop(LiStack* s, int& e)
{
	if (StackEmpty(s))
	{
		return false;
	}
	e = s->next->data;
	return true;
}
