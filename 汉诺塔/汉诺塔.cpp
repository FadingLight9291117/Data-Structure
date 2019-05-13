/*汉诺塔问题算法*/
#include<stdio.h>
static int count = 0;
void hanoi(int n, char a = 'A', char c = 'C', char b = 'B')
{
	if (n > 0)
	{
		hanoi(n - 1, a, b, c);
		printf("%c==>%c\n", a, c);
		count++;
		hanoi(n - 1, b, c, a);
	}
}
int main()
{
	hanoi(3);
	printf("%d",count);
}