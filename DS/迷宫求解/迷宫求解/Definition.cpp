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
bool StackEmpty(Stack& p)
{
	if(p.top == p.base){
		return true;
	}else{
		return false;
	}
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
void TraverseStack(Stack& p)
{
	int i = p.top,j = p.base;
	if(1 == j)
	{
		printf("Stack empty\n");
	}else{
		while(i !=j)
		{
			printf("��%d,%d)->",p.elem[--i].seat.x-1,p.elem[--i].seat.y-1);//topӦ��һ�Զ�λ����ǰջ��Ԫ��
		}
		printf("\n");
	}
}
void MarkPrint(Elemtype& elem)
{
	elem.Footprint = 1;
}
bool Pass(Elemtype& elem)//����ֵΪtrueʱ��Ϊ��ͨ��
{
	if(elem.value&&!elem.Footprint)//��ͨ�����Ϊ·��û���߹���ʱ��Ϊ��ͨ��
	{
		return true;
	}else{return false;}
}
PosType& NextPos(Elemtype& elem,int di)
{
	switch(di)
	{
		case 1: elem.seat.x++;break;
		case 2: elem.seat.x--;break;
		case 3: elem.seat.x++;elem.seat.y++;break;
		case 4: elem.seat.y++;break;
	}
	return elem.seat;
}
bool Posjudge(PosType& A,PosType& B)
{
	if(A.x == B.x && A.y == B.y){
		return true;
	}else{
		return false;
	}
}
void CurAssign(Elemtype& e,bool value,PosType seat,int di,bool foot)
{
	e.value = value;
	e.seat = seat;
	e.di = di;
	e.Footprint  = foot;
}

