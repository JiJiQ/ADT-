#include"Declaration.h"
#include<stdio.h>
void difference(SList& Spare)
{
	int headA = Malloc(Spare);int headB = Malloc(Spare);
	int cursor1 = headA;
	int cursor2 = headA;
	int r;
	int num = 0;
	int A[4];
	int B[7];
	A[0]=3;A[1]=5;A[2]=8;A[3]=11;
	B[0]=2;B[1]=6;B[2]=8;B[3]=9;B[4]=11;B[5]=15;B[6]=20;
	printf("算法：求两个集合的并集\n");
	printf("存储结构：静态链表\n");
	printf("集合A载入中。。。\n");
	while(num<4)
	{
		cursor2 = Malloc(Spare);
		Spare[cursor2].data = A[num];
		Spare[cursor1].next = cursor2;
		cursor1=cursor2;
		num++;
	}
	Spare[cursor1].next = 0;
	Spare[headA].data = -1;
	for(cursor1 = Spare[headA].next;cursor1!=0;cursor1=Spare[cursor1].next){
			printf("%d\n",Spare[cursor1].data);
	}
	printf("集合A遍历结束\n");
	cursor1 = headB;
	cursor2 = headB;
	num = 0;
	printf("集合B载入中。。。\n");
	while(num<7)
	{
		cursor2 = Malloc(Spare);
		Spare[cursor2].data = B[num];
		Spare[cursor1].next = cursor2;
		cursor1=cursor2;
		num++;
	}
	Spare[cursor1].next = 0;
	Spare[headB].data =-1;
	for(cursor1 = Spare[headB].next;cursor1!=0;cursor1=Spare[cursor1].next){
			printf("%d\n",Spare[cursor1].data);
	}
	printf("运算中。。。\n");
	for(cursor2 = Spare[headB].next;cursor2!=0 ; cursor2 = Spare[cursor2].next)
	{
		for(cursor1 = Spare[headA].next;cursor1!=0;cursor1=Spare[cursor1].next)
		{
			if(Spare[cursor1].data == Spare[cursor2].data)
			{
				break;
			}
		}
			if(cursor1==0){
				cursor1 = headA;
				r = Malloc(Spare);
				while(Spare[cursor1].next != 0)
				{
					cursor1 = Spare[cursor1].next;
				}
				Spare[r].data = Spare[cursor2].data;
				Spare[cursor1].next = r;
				Spare[r].next = 0;//尼玛
			}
	}
	printf("运算结束，结果遍历开始。。。\n");
	for(cursor1 = Spare[headA].next;cursor1!=0;cursor1=Spare[cursor1].next){
			printf("%d\n",Spare[cursor1].data);
	}
	printf("结果遍历结束！\n");
	/*A链表遍历结束*/
}
	