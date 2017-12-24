#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include"Declaration.h"
void InitStack(Stack& p,int size)
{
	p.elem = (Elemtype*)malloc(size*(sizeof Elemtype));
	p.base = 0;
	p.top = p.base;
	p.stacksize = size;
}
void PushS(Stack& p,Elemtype& e)
{
	if(p.top < p.stacksize)
	{
		p.elem[p.top++] = e;
	}else{
		printf("Stack full\n");
	}
}
Elemtype& PopS(Stack& p,Elemtype& e)
{
	if(p.top != p.base)
	{
		e = p.elem[--p.top];//按照字面意思访问栈顶元素，即top的前一个位置
		return e;
	}else{
		printf("Stack empty\n");
	}
}
void TraverseStack(Stack& p)
{
	int i = p.top,j = p.base;
	if(1 == j)
	{
		printf("Stack empty\n");
	}else{
		while(i !=j)
		{
			printf("%c",p.elem[--i]);//top应减一以定位到当前栈顶元素
		}
		printf("\n");
	}
}
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