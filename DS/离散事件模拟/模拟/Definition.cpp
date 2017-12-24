#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include"Declaration.h"
//链表：
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
		p[0].next = p[i].next;//1,p[0].next并不一定等于1。
		return i;
	}
}
void free(SList& p,int k)
{
	p[k].next =p[0].next;
	p[0].next = k;
}
//队列：
void InitQueue(Queue& p,int size)
{
	p.elem = (Elemtype*)malloc(size*sizeof Elemtype);
	p.rear = 0;
	p.front = p.rear;
	p.queuesize = size;
}
int GetQueLength(Queue& p)
{
	return (p.rear-p.front+p.queuesize)%p.queuesize;
}
void EnQueue(Queue& p,Elemtype& e)
{
	if( (p.rear+1)%p.queuesize != p.front)
	{
		p.elem[p.rear] = e;
		p.rear = (p.rear+1)%p.queuesize;
	}else{
		printf("Queue full\n");
	}
}
Elemtype& DeQueue(Queue& p,Elemtype& e)
{
	if(p.rear != p.front)
	{
		e = p.elem[p.front];
		p.front = (p.front+1)%p.queuesize;
		return e;
	}else{
		e = -1;
		return e;
		printf("Queue empty\n");
	}
}
int Empty(Queue& p)
{
	if(p.rear == p.front)
	{
		return 1;
	}else{return 0;}
}
void TraverseQueue(Queue& p)
{
	int i = p.rear,j = p.front;
	if(p.rear != p.front)
	{
		for(;j != i;j = (j+1)%p.queuesize)
		{
			printf("%3d",p.elem[j]);
		}
		printf("\n");
	}else{
		printf("Queue empty\n");

	}
}