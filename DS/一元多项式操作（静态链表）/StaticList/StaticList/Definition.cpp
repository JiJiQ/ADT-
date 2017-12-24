#include<stdio.h>
#include"Declaration.h"

void InitStaticList(SList& p)
{
	int i = 0;
	for(i=0;i<MAXSIZE-1;i++)
	{
		p[i].next = i+1;
	}
	p[MAXSIZE-1].next = 0;
}
int Malloc(SList& p)
{
	int i = p[0].next;
	if(p[0].next)
	{
		p[0].next = p[i].next;//1,p[o].next并不一定等于1。
		return i;
	}
}
void free(SList& p,int k)
{
	p[k].next =p[0].next;
	p[0].next = k;
}
int CreatPoly(SList& p,int size)
{
	int head = Malloc(p);
	int i = 1;
	int corsor = Malloc(p);
	p[head].next = corsor;
	p[head].e = -1;//设多项式所有的值都大于零；
	p[head].m = -1;
	for(i = 1;i < size;i++)
	{
		p[corsor].next = Malloc(p);
		corsor = p[corsor].next;
	}
	p[corsor].next = 0;
	return head;
}
void PrintPoly(SList&p,int head)
{
	int corsor = p[head].next;
	printf("多项式遍历：\n");
	for(;p[corsor].next>0;corsor = p[corsor].next)
	{
		if(p[corsor].m==0){continue;}
		else{printf("%d*X^%d + ",p[corsor].m,p[corsor].e);}
	}
	printf("%d*X^%d\n",p[corsor].m,p[corsor].e);
}
int cmp(SList&p,int A,int B)
{
	if(p[A].e>p[B].e)
	{return 1;}
	if(p[A].e==p[B].e)
	{return 0;}
	 return -1;
	
}
void AddPoly(SList&p,int A,int B)
{
	int corsorA = p[A].next;
	int corsorB = p[B].next;
	int i = 0,j = 0;
	int value;
	int swap;
	while(corsorA!=0 && corsorB!=0)
	{
		value = cmp(p,corsorA,corsorB);
		switch(value)
		{
			case -1:
				corsorA = p[corsorA].next;
				break;
			case 0:
				p[corsorA].m += p[corsorB].m;
				corsorA = p[corsorA].next;
				corsorB = p[corsorB].next;
				break;
			case 1:
				for(i = p[A].next;p[i].next!=corsorA;i = p[i].next){};
				for(j = p[B].next;p[j].next!=corsorB;j = p[j].next){};
				p[j].next = p[corsorB].next;
				p[corsorB].next = corsorA;
				p[i].next = corsorB;
				corsorB = p[j].next;
				break;
		}
	}
	if(corsorA==0)
	{
		for(i = p[A].next;p[i].next!=0;i = p[i].next){};
		p[i].next = corsorB;
	}
}