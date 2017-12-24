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
		p[0].next = p[i].next;//1,p[0].next����һ������1��
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
		p[0].next = p[i].next;//1,p[0].next����һ������1��
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
//��ʼ��״̬Ϊ���п����һ�������¼һ�������п顣
//			 ��ռ���û�б��
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
	printf("���п��״̬��\n");
	if(cursor < 0)
	{
		printf("���п��Ϊ�գ�û�п����ڴ����ʹ��\n");
	}
	while(cursor > 0)
	{
		printf("��ţ�%d����С��%d���׵�ַ��%2d��ĩ��ַ��%d\n",FS[cursor].data.Number,
															 FS[cursor].data.PartitionSize,
															 FS[cursor].data.StartAddress,
															 FS[cursor].data.EndAddress);
		cursor = FS[cursor].next;
	}
}
void AVisit(AccessedSList& AS,int aHead)
{
	int cursor = AS[aHead].next;
	printf("��ռ��״̬��\n");
	if(cursor < 0)
	{
		printf("��ռ���Ϊ�գ�û����ҵִ��\n");
	}
	while(cursor > 0)
	{
		printf("��ţ�%d����ҵ����%c,��С��%d���׵�ַ��%2d��ĩ��ַ��%d\n",AS[cursor].data.Number,
															 AS[cursor].data.Name,
															 AS[cursor].data.PartitionSize,
															 AS[cursor].data.StartAddress,
															 AS[cursor].data.EndAddress);
		cursor = AS[cursor].next;
	}
}