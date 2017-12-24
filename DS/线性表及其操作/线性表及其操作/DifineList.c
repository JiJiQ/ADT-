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
	if(i<1||i>p->length+1){printf("λ������Ԫ�ز������");}//��ֹi̫С��̫��(iӦ��С�ڵ�ǰ���ȼ�1)��
	else{
		for(l = p->length;l > i - 1;l--)/*��ҪŲlength-i+1������Ԫ��
		����length-��i-1����length��i-1��Ϊ�±꣩*/
		{
			p->elem[l] = p->elem[l-1];
		}
		//iΪλ�ã�
		p->elem[i-1] = e;//����e����i��λ��
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
