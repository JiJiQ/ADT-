#include<stdio.h>
#include<stdlib.h>
#include"Declaration.h"
int main(void)
{
	printf("工程：一元多项式的表示及运算\n");
	printf("数据结构：静态链表\n");
	SList Spare;
	Node A[4];
	Node B[3];
	int i = 0;
	InitStaticList(Spare);
	int headA = CreatPoly(Spare,4);
	int corsorA = Spare[headA].next;
	int headB = CreatPoly(Spare,3);
	int corsorB = Spare[headB].next;
	Spare[headA].next = corsorA;
	A[0].m = 7;A[0].e = 0;A[1].m = 3;A[1].e = 1;A[2].m = 9;A[2].e = 8;A[3].m = 5;A[3].e = 17;
	B[0].m = 8;B[0].e = 1;B[1].m = 22;B[1].e = 7;B[2].m = -9;B[2].e = 8;
	for(i = 0;i<4;i++,corsorA = Spare[corsorA].next)
	{
		Spare[corsorA].m = A[i].m;
		Spare[corsorA].e = A[i].e;
	}
	for(i = 0;i<3;i++,corsorB = Spare[corsorB].next)
	{
		Spare[corsorB].m = B[i].m;
		Spare[corsorB].e = B[i].e;
	}
	corsorA = Spare[headA].next;
	corsorB = Spare[headB].next;
	printf("A:\n");
	PrintPoly(Spare,headA);
	printf("B:\n");
	PrintPoly(Spare,headB);
	AddPoly(Spare,headA,headB);
	printf("A+B:\n");
	PrintPoly(Spare,headA);
}