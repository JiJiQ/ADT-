#include"DList.h"
#include<malloc.h>
#include<stdio.h>
void InitList(pList p,int MaxSize)
{
	p->elem = (ElemType*)malloc(MaxSize*sizeof(ElemType));
	p->length = 0;
	p->ListSize = MaxSize;
}
int GetLength(pList p)
{
	return p->length;
}
void ListInsert(pList p,int i,ElemType e)
{
	int l = 0;
	if(i<1||i>p->length+1){printf("位置有误，元素插入错误");}//防止i太小和太大(i应该小于当前长度加1)。
	else{
		for(l = p->length;l > i - 1;l--)/*需要挪length-i+1个数据元素
		（即length-（i-1），length和i-1均为下标）*/
		{
			p->elem[l] = p->elem[l-1];
		}
		//i为位置，
		p->elem[i-1] = e;//插入e到第i个位置
		p->length++;
	}
}
ElemType* GetElem(pList p,int i,ElemType* e)
{
	if(i<1||i>p->length){}else{
		*e = p->elem[i-1];}
	return e;
}
void Visit(pList p)
{
	int i = 0;
	for(i=0;i<p->length;i++)
	{
		printf("%4d",p->elem[i]);
	}
	printf("\n");
}
