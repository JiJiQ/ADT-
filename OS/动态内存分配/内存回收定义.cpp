#include<stdio.h>
#include"Dec.h"
bool Recover(FreeSList& FS,int fHead,AccessedSList& AS,int aHead,PCB& p)
{
	int aCursor = aHead;//��λ���յ��ڴ�ռ�
	int fcursor = -1;//��λ���п���Ԫ��
	int fPiror = fHead;//�������п����λ���п��Ԫ�ص�ǰһ��
	int acursor = -1;//��Ҫ�����յ��ڴ�ռ�
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
	if(AS[aCursor].next < 0){printf("û�д���ҵ�����У��ڴ����ʧ��\n");return false;}
	AS[aCursor].next = AS[acursor].next;//�����ڴ�ռ�
	//ˢ����ռ�ڴ��ı��
	//ע�ⲻ����acursor��������
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
			//����ǰ��Ľ��ϲ�
			fcursor = FS[fPiror].next;
			FS[fcursor].data.EndAddress = AS[acursor].data.EndAddress;
			FS[fcursor].data.PartitionSize += AS[acursor].data.PartitionSize;
			break;
		}
		if( FS[FS[fPiror].next].data.StartAddress == (AS[acursor].data.EndAddress+1) )
		{ 
			//�������Ľ��ϲ�
			fcursor = FS[fPiror].next;
			FS[fcursor].data.StartAddress = AS[acursor].data.StartAddress;
			FS[fcursor].data.PartitionSize += AS[acursor].data.PartitionSize;
			break;
		}
		fPiror = FS[fPiror].next;
	}
	//���Ժϲ�ʱ����Ҫ��ֻ��һ��û������õĿ��п����������
	while(FS[fcursor].next > 0)
	{
		if(FS[fcursor].data.PartitionSize > FS[FS[fcursor].next].data.PartitionSize)
		{
			swap = FS[FS[fcursor].next].data;
			FS[FS[fcursor].next].data = FS[fcursor].data;
			FS[fcursor].data = swap;
			FS[fPiror].next = FS[fcursor].next;
			FS[fcursor].next = FS[FS[fcursor].next].next;
			//�ı䲽��
			fPiror = FS[fPiror].next;
			fcursor = FS[fcursor].next;
			return true;
		}else{
			break;
		}
	}
	if(FS[fPiror].next < 0)
	{
	//û�п��Ժϲ��Ľ�㣬Ѱ�Һ��ʵ�λ�ò�����п��
		//�����µĿ��п�������������������ֵ��
		fPiror = aHead;
		fcursor = FMalloc(FS);
		FS[fcursor].data.StartAddress = AS[acursor].data.StartAddress;
		FS[fcursor].data.EndAddress = AS[acursor].data.EndAddress;
		FS[fcursor].data.PartitionSize = AS[acursor].data.PartitionSize;
		//�������λ�ã���Ÿ����ʵ�ֵ
		//bug1;
		while(FS[fPiror].next > 0)
		{
			if(AS[acursor].data.PartitionSize <= FS[FS[fPiror].next].data.PartitionSize)
			{
				if(fPiror == fHead)
				{
					//������п����λ��
					FS[fcursor].data.Number = 1;
					FS[fcursor].next = FS[fPiror].next;
					FS[fPiror].next = fcursor;
					//return true;
					//����Ҫˢ�±�ţ��˴����ܹ���ؽ�������,�ø�Ϊbreak
					break;
				}else{
					//�������λ��
					FS[fcursor].data.Number = FS[fPiror].data.Number + 1;
					FS[fcursor].next = FS[fPiror].next;
					FS[fPiror].next = fcursor;
					//return true;
					//����Ҫˢ�±�ţ��˴����ܹ���ؽ�������,�ø�Ϊbreak
					break;
				}
			}else{
				fPiror = FS[fPiror].next;
				continue;
			}
		}
		//ˢ�¿��п��ı�ţ�
		fcursor = FS[fcursor].next;
		while(fcursor > 0)
		{
		//bug2
			FS[fcursor].data.Number++;
			fcursor = FS[fcursor].next;
		}
		//ˢ����ռ�ڴ��ı�ţ�

		return true;
	}
}