#include<stdio.h>
#include"Dec1�����ȣ�.h"
void FCFS(JcbSet& j)//�����ȷ����㷨
{
	printf("�����ȷ���ģ������ִ��˳�����\n");
	//���յ���ʱ���jcb�еĽ���������,�����㷨Ϊð������
	//������˳��Ϊ��ҵ��ִ��˳��
	JCB swap;//�����м���
	int x = 0,y = 0;
	for( x = 1;x <= j.num;x++)//��x������
	{
		for( y = 0;y < j.num - x;y++)//ÿ�˽ϴ�ֵ����ƶ�
		{
			if(j.elem[y].arriveTime > j.elem[y+1].arriveTime)
			{
				swap = j.elem[y];
				j.elem[y] = j.elem[y+1];
				j.elem[y+1] = swap;
			}
		}
	}
	//����ÿ����ҵ�����ʱ��
	int Time(0);//ʱ�ӣ���ʱ�̿�ʼ
	for( x = 0;x < j.num;x++)
	{
		j.elem[x].complishTime = Time + j.elem[x].processTime;
		Time += j.elem[x].processTime;
	}
	//����ÿ����ҵ����תʱ�䡢��Ȩ��תʱ��
	for(x = 0;x < j.num;x++)
	{
		j.elem[x].T = j.elem[x].complishTime - j.elem[x].arriveTime;
		j.elem[x].W = j.elem[x].T/j.elem[x].processTime;
	}
	//��ӡģ���㷨���,��ӡ�������ģ��ִ��˳�����
	for(x = 0;x < 5;x++)
	{
		printf("��ҵ��ţ�%2c , ��ҵ���ʱ�䣺%2d����ҵ��תʱ�䣺%2d����ҵ��Ȩ��תʱ�䣺%2d",j.elem[x].number,
																							j.elem[x].complishTime,
																							j.elem[x].T,
																							j.elem[x].W);
		printf("\n");
	}
	int num(0);//��Ȩʱ���ܺ�
	for(x = 0;x < j.num;x++)
	{
		num += j.elem[x].W;
	}
	printf("FCFS�£���ҵ��ƽ����Ȩʱ��Ϊ��%d\n",num/j.num);
}