#include<stdio.h>
#include"Dec.h"
bool Recover(FreeSList& FS,int fHead,AccessedSList& AS,int aHead,PCB& p)
{
	int aCursor = aHead;//定位回收的内存空间
	int fcursor = -1;//定位空闲块表的元素
	int fPiror = fHead;//遍历空闲块表，定位空闲块表元素的前一项
	int acursor = -1;//将要被回收的内存空间
	FreeTable swap = FS[FS[fHead].next].data;
	while(AS[aCursor].next > 0)
	{
		if(AS[AS[aCursor].next].data.Name == p.Name)
		{
			acursor = AS[aCursor].next;
			break;
		}else{
			aCursor = AS[aCursor].next;
		}
	}
	if(AS[aCursor].next < 0){printf("没有此作业在运行，内存回收失败\n");return false;}
	AS[aCursor].next = AS[acursor].next;//回收内存空间
	//刷新已占内存表的编号
	//注意不能用acursor遍历链表
	int cursor = AS[acursor].next;
	while(cursor > 0)
	{
		AS[cursor].data.Number--;
		cursor = AS[cursor].next;
	}
	while(FS[fPiror].next > 0)
	{
		if( (FS[FS[fPiror].next].data.EndAddress+1) == AS[acursor].data.StartAddress)
		{  
			//可与前面的结点合并
			fcursor = FS[fPiror].next;
			FS[fcursor].data.EndAddress = AS[acursor].data.EndAddress;
			FS[fcursor].data.PartitionSize += AS[acursor].data.PartitionSize;
			break;
		}
		if( FS[FS[fPiror].next].data.StartAddress == (AS[acursor].data.EndAddress+1) )
		{ 
			//可与后面的结点合并
			fcursor = FS[fPiror].next;
			FS[fcursor].data.StartAddress = AS[acursor].data.StartAddress;
			FS[fcursor].data.PartitionSize += AS[acursor].data.PartitionSize;
			break;
		}
		fPiror = FS[fPiror].next;
	}
	//可以合并时，需要对只有一项没有排序好的空闲块表重新排序
	while(FS[fcursor].next > 0)
	{
		if(FS[fcursor].data.PartitionSize > FS[FS[fcursor].next].data.PartitionSize)
		{
			swap = FS[FS[fcursor].next].data;
			FS[FS[fcursor].next].data = FS[fcursor].data;
			FS[fcursor].data = swap;
			FS[fPiror].next = FS[fcursor].next;
			FS[fcursor].next = FS[FS[fcursor].next].next;
			//改变步长
			fPiror = FS[fPiror].next;
			fcursor = FS[fcursor].next;
			return true;
		}else{
			break;
		}
	}
	if(FS[fPiror].next < 0)
	{
	//没有可以合并的结点，寻找合适的位置插入空闲块表
		//创建新的空闲块表项，除编号外其他数据项赋值。
		fPiror = aHead;
		fcursor = FMalloc(FS);
		FS[fcursor].data.StartAddress = AS[acursor].data.StartAddress;
		FS[fcursor].data.EndAddress = AS[acursor].data.EndAddress;
		FS[fcursor].data.PartitionSize = AS[acursor].data.PartitionSize;
		//插入合适位置，编号赋合适的值
		//bug1;
		while(FS[fPiror].next > 0)
		{
			if(AS[acursor].data.PartitionSize <= FS[FS[fPiror].next].data.PartitionSize)
			{
				if(fPiror == fHead)
				{
					//插入空闲块表首位置
					FS[fcursor].data.Number = 1;
					FS[fcursor].next = FS[fPiror].next;
					FS[fPiror].next = fcursor;
					//return true;
					//由于要刷新标号，此处不能过早地结束函数,该改为break
					break;
				}else{
					//插入合适位置
					FS[fcursor].data.Number = FS[fPiror].data.Number + 1;
					FS[fcursor].next = FS[fPiror].next;
					FS[fPiror].next = fcursor;
					//return true;
					//由于要刷新标号，此处不能过早地结束函数,该改为break
					break;
				}
			}else{
				fPiror = FS[fPiror].next;
				continue;
			}
		}
		//刷新空闲块表的编号：
		fcursor = FS[fcursor].next;
		while(fcursor > 0)
		{
		//bug2
			FS[fcursor].data.Number++;
			fcursor = FS[fcursor].next;
		}
		//刷新已占内存表的编号，

		return true;
	}
}