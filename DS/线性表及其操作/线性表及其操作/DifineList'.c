#include<stdio.h>
#include"DList'.h"
#include<malloc.h>
void InitList(pList p,int size)
{
	int i = 0;
	Node*  head = p->elem;
	for(i=0;i<size;i++)
	{
		head->next = (Node*)malloc(sizeof(Node));
		head = head->next;
	}
	p->length = 0;
	p->ListSize = size;
}
int GetLength(pList p)
{
	return p->length;
}
void ListInsert(pList p,int i,ElemType e)
{
	int Location=0;
	Node* corsor=p->elem;
	Node* NewNode;
	NewNode =(Node*)malloc(sizeof(Node));
	NewNode->data= e;
	if(i<0||i>p->length+1){}//插入的位置过小或者过大
	else{
		for(Location;Location<i-2;Location++)
		{
			corsor = corsor->next;
		}
		NewNode->next = corsor->next;
		corsor->next = NewNode;
		p->length++;
		}
}
ElemType* GetElem(pList p,int i,ElemType* e)
{
	Node* corsor=p->elem;
	int location = 0;
	for(;location<i;location++)
	{
		corsor = corsor->next;
	}
	return &(corsor->data);
}
void Visit(pList p)
{
	Node* corsor=p->elem;
	while(corsor)
	{
		printf("%2d",corsor->data);
		corsor = corsor->next;
	}
}