#include<stdio.h>
#include"Declaration.h"
void conversion(int a,int b)
{
	int x(a);
	int y(x);
	int z;
	Stack stack;
	int length;
	InitStack(stack,100);
	while(x != 0)
	{
		y = x;
		x = x/b;
		y = y%b;
		PushS(stack, y);
	}
	printf("10������%dת����%d������Ϊ��\n",a,b);
	TraverseStack(stack);
}