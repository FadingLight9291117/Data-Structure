#include<stdio.h>
#include"LiStack.h"
bool Match(char exp[], int n)
{
	LiStack* s;
	bool match = true;
	InitStack(s);
	for (int i = 0; i < n; i++)
	{
		if (exp[i] == '(')
		{
			Push(s, '(');
			continue;
		}
		else if (exp[i] == '(')
		{
			if()
		}
	}
}
int main()
{

}