#include<stdio.h>
#include"Declaration.h"
void InitStaticList(SList& p)
{
	int i = 0;
	for(i=0;i<MAXSIZE-1;i++)
	{
		p[i].next = i+1;
	}
	p[MAXSIZE-1].next = -1;
}
int Malloc(SList& p,int num)
{
	int head(0);
	printf("����ռ��С��%d\n",num);
	if(p[0].next)
	{
		int i = p[0].next;
		p[0].next = p[i].next;//1,p[0].next����һ������1��
		head = i;
		num--;
		while(num > 0)
		{
			p[i].next = p[0].next;
			{i = p[i].next;
			p[0].next = p[i].next;}//����˳���ܵߵ�
			num--;
		}
		p[i].next = -1;
		return head;
	}
}
void free(SList& p,int head)
{
	int i(head);
	while(i>0){
		i = p[i].next;
	}
	p[i].next = p[0].next;
	p[0].next = head;
}