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
	printf("10进制数%d转换成%d进制数为：\n",a,b);
	TraverseStack(stack);
}