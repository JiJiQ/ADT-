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
		e = p.elem[--p.top];//����������˼����ջ��Ԫ�أ���top��ǰһ��λ��
		return e;
	}else{
		printf("Stack empty\n");
	}
}
bool EmptyS(Stack& p)
{
	return(p.top == p.base);
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
			printf("%c",p.elem[--i]);//topӦ��һ�Զ�λ����ǰջ��Ԫ��
		}
		printf("\n");
	}
}
void InitQueue(Queue& p,int size)
{
	p.elem = (Elemtype*)malloc(size*sizeof Elemtype);
	p.rear = 0;//ָ���βԪ�ص���һ��λ��
	p.front = p.rear;//frontָ���ͷԪ��
	p.queuesize = size;
}
int GetQueLength(Queue& p)
{
	return (p.rear-p.front+p.queuesize)%p.queuesize;
}
void EnQueue(Queue& p,Elemtype& e)//��β���룬��βָ��+1
{
	if( (p.rear+1)%p.queuesize != p.front)//��������
	{
		p.elem[p.rear] = e;
		p.rear = (p.rear+1)%p.queuesize;
	}else{
		printf("Queue full\n");
	}
}
Elemtype& DeQueue(Queue& p,Elemtype& e)//��ͷɾ������ͷָ��+1
{
	if(p.rear != p.front)//�����п�
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