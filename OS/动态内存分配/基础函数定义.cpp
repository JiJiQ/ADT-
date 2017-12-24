#include<stdio.h>
#include"Dec.h"
void FreeInit(FreeSList& p)
{
	int i = 0;
	for(i=0;i<MAXSIZE-1;i++)
	{
		p[i].next = i+1;
	}
	p[MAXSIZE-1].next = 0;
}
void AccessedInit(AccessedSList& p)
{
	int i = 0;
	for(i=0;i<MAXSIZE-1;i++)
	{
		p[i].next = i+1;
	}
	p[MAXSIZE-1].next = 0;
}
int FMalloc(FreeSList& p)
{
	int i = p[0].next;
	if(p[0].next)
	{
		p[0].next = p[i].next;//1,p[0].next并不一定等于1。
		return i;
	}else{
		return -1;
	}
}
void Ffree(FreeSList& p,int k)
{
	p[k].next =p[0].next;
	p[0].next = k;
}
int AMalloc(AccessedSList& p)
{
	int i = p[0].next;
	if(p[0].next)
	{
		p[0].next = p[i].next;//1,p[0].next并不一定等于1。
		return i;
	}else{
		return -1;
	}
}
void Afree(AccessedSList& p,int k)
{
	p[k].next =p[0].next;
	p[0].next = k;
}
//初始化状态为空闲块表有一个表项，记录一整个空闲块。
//			 已占块表没有表项。
void Init(FreeSList& FS,int fHead,AccessedSList& AS,int aHead)
{
	int fCursor = FMalloc(FS);
	FS[fCursor].data.Number = 1;
	FS[fCursor].data.StartAddress = 11;
	FS[fCursor].data.EndAddress = 110;
	FS[fCursor].data.PartitionSize = 100;
	FS[fHead].next = fCursor;
	FS[fCursor].next = -1;
	AS[aHead].next = -1;
}
void FVisit(FreeSList& FS,int fHead)
{
	int cursor = FS[fHead].next;
	printf("空闲块表状态：\n");
	if(cursor < 0)
	{
		printf("空闲块表为空，没有空闲内存可以使用\n");
	}
	while(cursor > 0)
	{
		printf("编号：%d，大小：%d，首地址：%2d，末地址：%d\n",FS[cursor].data.Number,
															 FS[cursor].data.PartitionSize,
															 FS[cursor].data.StartAddress,
															 FS[cursor].data.EndAddress);
		cursor = FS[cursor].next;
	}
}
void AVisit(AccessedSList& AS,int aHead)
{
	int cursor = AS[aHead].next;
	printf("已占表状态：\n");
	if(cursor < 0)
	{
		printf("已占块表为空，没有作业执行\n");
	}
	while(cursor > 0)
	{
		printf("编号：%d，作业名：%c,大小：%d，首地址：%2d，末地址：%d\n",AS[cursor].data.Number,
															 AS[cursor].data.Name,
															 AS[cursor].data.PartitionSize,
															 AS[cursor].data.StartAddress,
															 AS[cursor].data.EndAddress);
		cursor = AS[cursor].next;
	}
}