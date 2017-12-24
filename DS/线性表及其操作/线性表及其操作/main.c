#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include"DList.h"
int main(void)
{
	ElemType x;//用以存储线性表操作的中间数据
	int i = 1;
	List A,B;
	List C;
	printf("工程：线性表ADT及常用算法\n");
	InitList(&A,4);
	InitList(&B,7);
	InitList(&C,A.ListSize+B.ListSize);
	
	A.elem[0]=3;A.elem[1]=5;A.elem[2]=8;A.elem[3]=11;A.length=4;
	B.elem[0]=2;B.elem[1]=6;B.elem[2]=8;B.elem[3]=9;B.elem[4]=11;B.elem[5]=15;B.elem[6]=20;B.length=7;
	MergeList(&A,&B,&C);
	Visit(&A);
	Visit(&B);
	Visit(&C);
	
	system("PAUSE");
}
