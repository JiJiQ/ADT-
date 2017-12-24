#include<stdio.h>
#include"Dec.h"
bool Access(FreeSList& FS,int fHead,AccessedSList& AS,int aHead,PCB& p)
{
	int fCursor = FS[fHead].next;//Ѱ�����ʺϷ�����п�ʱ��
	int aCursor = aHead;//����ѷ�������ʱ�ã�
	int newNode = -1;//����ӵ��ѷ�������
	int FnewNode = -1;//��¼�ָ�������п����
	int cursor = fHead;//���ָ�����Ŀ��п������п��ʱ�á�
	int piror = fHead;//fCursor��ǰһ���ڵ㣬ɾ���ѷ���ڵ�ʱ�õ�
	bool statu = false;
	//��λ���ѷ���������һ�����
	while(AS[aCursor].next > 0)
	{
		aCursor = AS[aCursor].next;
	}
	//�ռ���С��������õĿ��п�������
	while(fCursor > 0)
	{
		if(FS[fCursor].data.PartitionSize >= p.SpaceSize)
		{
			//�±�ΪfCursor�Ŀ��п�Ϊ���ʺϷ���
			newNode = AMalloc(AS);
			AS[newNode].data.Name = p.Name;
			if(aCursor == aHead)
			{
				//ԭ��ռ�ڴ��Ϊ��
				AS[newNode].data.Number = 1;
				AS[aHead].next = newNode;
				AS[newNode].next = -1;
			}else{	
				//ԭ��ռ�ڴ��Ϊ��
				AS[newNode].data.Number = AS[aCursor].data.Number + 1;
				AS[newNode].next = AS[aCursor].next;
				AS[aCursor].next = newNode;
			}
			if(FS[fCursor].data.PartitionSize - p.SpaceSize <= minSize)
			{
				//���п鲻�����ٷָ�޸����ű�����ݡ�
				AS[newNode].data.PartitionSize = FS[fCursor].data.PartitionSize;
				AS[newNode].data.StartAddress = FS[fCursor].data.StartAddress;
				AS[newNode].data.EndAddress = FS[fCursor].data.EndAddress;
				//�ڿ��з�������ɾ���ѱ�����Ľ����Ϣ
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
				printf("�ڴ����ɹ�������ִ�С�����������\n");
				return statu;
			}else{
				//���п�����ٷָ�޸����ű������
				AS[newNode].data.PartitionSize = p.SpaceSize;
				AS[newNode].data.StartAddress = FS[fCursor].data.StartAddress;
				AS[newNode].data.PartitionSize = p.SpaceSize;
				AS[newNode].data.EndAddress = AS[newNode].data.StartAddress + AS[newNode].data.PartitionSize - 1;
				FnewNode = FMalloc(FS);
				FS[FnewNode].data.StartAddress = AS[newNode].data.EndAddress + 1;
				FS[FnewNode].data.EndAddress = FS[fCursor].data.EndAddress;
				FS[FnewNode].data.PartitionSize = FS[fCursor].data.PartitionSize - p.SpaceSize;
				//���ָ�������µķ�����Ϣ����������з�����ǡ��λ�á�
				while(FS[cursor].next > 0)
				{
					if(FS[FnewNode].data.PartitionSize <= FS[FS[cursor].next].data.PartitionSize)
					{
						//���ָ��Ŀ��п鰴�������п�����޸ı�š�
						//Ӧ�����޸ı�ţ�
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
				//�ָ�����Ŀ��п�ռ���󣬷��ڿ��п��ĩβ
				if(FS[cursor].next < 0){
					FS[cursor].next = FnewNode;
					FS[FnewNode].next = -1;
					statu = true;
					printf("�ڴ����ɹ�������ִ�С�����������\n");
					return statu;
				}
				//ɾ��δ�ָ�ǰ�Ŀ��п����±�ΪfCuror
				while(FS[piror].next != fCursor)
				{
					piror = FS[piror].next;
				}
				FS[piror].next = FS[fCursor].next;
				//ˢ�¿��п�ı��ֵ��
				int cursor = FS[fHead].next;
				for(FS[cursor].data.Number = 1;FS[cursor].next > 0;cursor = FS[cursor].next)
				{
					FS[FS[cursor].next].data.Number = FS[cursor].data.Number+1;
				}
				statu = true;
				printf("�ڴ����ɹ�������ִ�С�����������\n");
				return statu;
			}
		}else{
			continue;
		}
	}
	//�����п��п鶼������ռ�С����ӡ�����������ط���״̬
	printf("�ڴ����ʧ��\n");
	AS[aCursor].next = AS[newNode].next;
	Afree(AS,newNode);
	return statu;
}