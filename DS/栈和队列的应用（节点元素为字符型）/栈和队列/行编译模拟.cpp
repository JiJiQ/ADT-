#include"Declaration.h"
#include<stdio.h>
#include<stdlib.h>
void LineEidt(char* a,int length)
{
	Stack s;
	int i = 0;
	Stack s1;
	char e;
	printf("�㷨������ջģ���б������\n");
	InitStack(s,length);
	InitStack(s1,length);
	printf("���뾭У����봮��%s���м�ջ\n",a);
	for(i = 0;i<length;i++)
	{ 
		if(a[i] == '\0'){break;}//���ַ�����ȡ�ս��ʶ����\0��Ϊѭ����ֹ����
		PushS(s,a[i]);
	}
	printf("�м�ջ��\n");
	TraverseStack(s);
	printf("ɸѡ�����﷨�ַ�����ջ\n");
	while(s.top != s.base)
	{
		if(s.elem[s.top - 1] == '#')
		{
			printf("�˸��#������\n");
			s.top = s.top-2;
			continue;
		}
		if(s.elem[s.top - 1] == '@')
		{
			printf("���з�@������\n");
			s.top = s.base;
			continue;
		}
		else{
			PushS(s1,PopS(s,e));
		}
	}
	printf("��Ч�����\n");
	TraverseStack(s1);
}