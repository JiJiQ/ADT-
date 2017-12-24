#include"Declaration.h"
#include<stdio.h>
#include<stdlib.h>
void LineEidt(char* a,int length)
{
	Stack s;
	int i = 0;
	Stack s1;
	char e;
	printf("算法：利用栈模拟行编译程序\n");
	InitStack(s,length);
	InitStack(s1,length);
	printf("输入经校验代码串：%s入中间栈\n",a);
	for(i = 0;i<length;i++)
	{ 
		if(a[i] == '\0'){break;}//以字符串读取终结标识符“\0”为循环终止条件
		PushS(s,a[i]);
	}
	printf("中间栈：\n");
	TraverseStack(s);
	printf("筛选符合语法字符入结果栈\n");
	while(s.top != s.base)
	{
		if(s.elem[s.top - 1] == '#')
		{
			printf("退格符#起作用\n");
			s.top = s.top-2;
			continue;
		}
		if(s.elem[s.top - 1] == '@')
		{
			printf("退行符@起作用\n");
			s.top = s.base;
			continue;
		}
		else{
			PushS(s1,PopS(s,e));
		}
	}
	printf("有效结果：\n");
	TraverseStack(s1);
}