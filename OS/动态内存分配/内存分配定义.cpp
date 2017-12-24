#include<stdio.h>
#include"Dec.h"
bool Access(FreeSList& FS,int fHead,AccessedSList& AS,int aHead,PCB& p)
{
	int fCursor = FS[fHead].next;//寻找最适合分配空闲块时用
	int aCursor = aHead;//添加已分配块表项时用；
	int newNode = -1;//新添加的已分配块表项
	int FnewNode = -1;//记录分割产生空闲块表用
	int cursor = fHead;//将分割产生的空闲块插入空闲块表时用。
	int piror = fHead;//fCursor的前一个节点，删除已分配节点时用到
	bool statu = false;
	//定位到已分配块表的最后一个结点
	while(AS[aCursor].next > 0)
	{
		aCursor = AS[aCursor].next;
	}
	//空间由小到大排序好的空闲块表结点遍历
	while(fCursor > 0)
	{
		if(FS[fCursor].data.PartitionSize >= p.SpaceSize)
		{
			//下标为fCursor的空闲块为最适合分配
			newNode = AMalloc(AS);
			AS[newNode].data.Name = p.Name;
			if(aCursor == aHead)
			{
				//原已占内存表为空
				AS[newNode].data.Number = 1;
				AS[aHead].next = newNode;
				AS[newNode].next = -1;
			}else{	
				//原已占内存表不为空
				AS[newNode].data.Number = AS[aCursor].data.Number + 1;
				AS[newNode].next = AS[aCursor].next;
				AS[aCursor].next = newNode;
			}
			if(FS[fCursor].data.PartitionSize - p.SpaceSize <= minSize)
			{
				//空闲块不可以再分割，修改两张表的数据。
				AS[newNode].data.PartitionSize = FS[fCursor].data.PartitionSize;
				AS[newNode].data.StartAddress = FS[fCursor].data.StartAddress;
				AS[newNode].data.EndAddress = FS[fCursor].data.EndAddress;
				//在空闲分区表中删除已被分配的结点信息
				while(FS[piror].next != fCursor)
				{
					piror = FS[piror].next;
				}
				FS[piror].next = FS[fCursor].next;
				fCursor = FS[fCursor].next;
				while(fCursor > 0)
				{
					FS[fCursor].data.Number--;
					fCursor = FS[fCursor].next;
				}
				statu = true;
				printf("内存分配成功，进程执行。。。。。。\n");
				return statu;
			}else{
				//空闲块可以再分割，修改两张表的数据
				AS[newNode].data.PartitionSize = p.SpaceSize;
				AS[newNode].data.StartAddress = FS[fCursor].data.StartAddress;
				AS[newNode].data.PartitionSize = p.SpaceSize;
				AS[newNode].data.EndAddress = AS[newNode].data.StartAddress + AS[newNode].data.PartitionSize - 1;
				FnewNode = FMalloc(FS);
				FS[FnewNode].data.StartAddress = AS[newNode].data.EndAddress + 1;
				FS[FnewNode].data.EndAddress = FS[fCursor].data.EndAddress;
				FS[FnewNode].data.PartitionSize = FS[fCursor].data.PartitionSize - p.SpaceSize;
				//将分割产生的新的分区信息插入有序空闲分区表恰当位置。
				while(FS[cursor].next > 0)
				{
					if(FS[FnewNode].data.PartitionSize <= FS[FS[cursor].next].data.PartitionSize)
					{
						//将分割后的空闲块按序插入空闲块表，并修改编号。
						//应该先修改编号，
						if(FS[FS[cursor].next].next == -1)
						{
							FS[FnewNode].data.Number = 1;
						}else{
							FS[FnewNode].data.Number = FS[cursor].data.Number + 1;
						}
						FS[FnewNode].next = FS[cursor].next;
						FS[cursor].next = FnewNode;
						break;
					}else{
						cursor = FS[cursor].next;
					}
				}
				//分割产生的空闲块空间最大，放在空闲块表末尾
				if(FS[cursor].next < 0){
					FS[cursor].next = FnewNode;
					FS[FnewNode].next = -1;
					statu = true;
					printf("内存分配成功，进程执行。。。。。。\n");
					return statu;
				}
				//删除未分割前的空闲块表项，下标为fCuror
				while(FS[piror].next != fCursor)
				{
					piror = FS[piror].next;
				}
				FS[piror].next = FS[fCursor].next;
				//刷新空闲块的编号值。
				int cursor = FS[fHead].next;
				for(FS[cursor].data.Number = 1;FS[cursor].next > 0;cursor = FS[cursor].next)
				{
					FS[FS[cursor].next].data.Number = FS[cursor].data.Number+1;
				}
				statu = true;
				printf("内存分配成功，进程执行。。。。。。\n");
				return statu;
			}
		}else{
			continue;
		}
	}
	//若所有空闲块都比请求空间小，打印分配结果，返回分配状态
	printf("内存分配失败\n");
	AS[aCursor].next = AS[newNode].next;
	Afree(AS,newNode);
	return statu;
}