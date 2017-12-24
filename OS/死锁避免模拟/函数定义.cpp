#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include"dec.h"
void InitVector(vectors& v)//��ʼ����Դ�������
{
	int max[5][3] = {{7,5,3},{3,2,2},{9,0,2},{2,2,2},{4,3,3}};
	int allocation[5][3] = {{0,1,0},{2,0,0},{3,0,2},{2,1,1},{0,0,2}};
	int need[5][3] = {{7,4,3},{1,2,2},{6,0,0},{0,1,1},{4,3,1}};
	int available[3] = {3,3,2};
	for(int i = 0;i < 5;i++)
	{
		for(int j = 0;j < 3;j++)
		{
			v.Max[i][j] = max[i][j];
			v.Allocation[i][j] = allocation[i][j];
			v.Need[i][j] = need[i][j];
		}
		v.Finish[i] = false;//��ʼ״̬���̶�û��ִ����
	}
	for(int i = 0;i < 3;i++)
	{
		v.Available[i] = available[i];
		v.work[i] = available[i];
	}
}
void InitRequest(request& r,int cursor,int a,int b,int c)//��ʼ����Դ�������
{
	r.elem = (int*)malloc(3*sizeof(int));
	r.cursor = cursor;
	r.elem[0] = a;
	r.elem[1] = b;
	r.elem[2] = c;
}
bool SafetyCheck(vectors& v)//��ȫ�Լ��
{
	int i = 0,j = 0;
	int corsor = -1;
	int FinishNum = 0;
	int CheckNum = 0;//������ѭ�����õ���ֹ��������ϵͳ��������ʱFinishNum�ܻ�С��5��
	while(FinishNum < 5)
	{
		CheckNum++;
		for(i = 0;i < 5 && v.Finish[i] == false;i++)
		{
			//Ѱ��һ������ִ����Ľ��̣�ģ��ִ���겢���ոý��̵���Դ
			for(j = 0;j < 3;j++)
			//�����̵�ÿһ����Դ�Ƿ��п��ܷ��䵽
			{
				if(v.Need[i][j] <= v.work[j])
				{
					continue;
				}else{
					break;
				}
			}
			if(j == 3)
			{
				corsor = i;
			}
		}
		if(corsor >= 0)
		{
			//ģ����տ���ִ������̵��ѷ�����Դ
			for(j = 0;j < 3;j++)
			{
				v.work[j] += v.Allocation[corsor][j];
			}
			v.Finish[corsor] = true;
			FinishNum++;
		}
		if(CheckNum > 50)
		{
			//��ѭ������
			return false;
		}
	}
	if(FinishNum == 5)
	{
		return true;
	}
}
bool BankerAlgorithm(vectors& v,request& r)//���м��㷨
{
	int i = 0,j = 0;
	for(j = 0;j < 3;j++)
	{
		v.Request[r.cursor][j] = r.elem[j];
	}
	for(j = 0;j < 3;j++)
	{
		if(v.Request[r.cursor][j] > v.Max[r.cursor][j])
		{
			printf("�������趨�����޷�ΪP%d�����������Դ\n",r.cursor);
			return false;
		}
		if(v.Request[r.cursor][j] > v.Available[j])
		{
			printf("ϵͳ��ǰʣ����Դ̫�١��޷�ΪP%d�����������Դ\n",r.cursor);
			return false;
		}
	}
	//����ϵͳ��ǰ��Դ������ʶ
	for(j = 0;j < 3;j++)
	{
		v.Available[j] -= r.elem[j];
		v.Allocation[r.cursor][j] += r.elem[j];
	}
	if(SafetyCheck(v))
	{//�������ϵͳ��ȫ������䣬���ؿɷ����־
		printf("���Է���P%d�����������Դ\n",r.cursor);
		return true;
	}else{
			for(j = 0;j < 3;j++)
		{//�������ϵͳ����ȫ����ȡ�����䲢��ԭϵͳ��Դ����������������
			v.Available[j] += r.elem[j];
			v.Allocation[r.cursor][j] -= r.elem[j];
		}//���ز��ɷ����־
			printf("���ڷ����ᵼ��ϵͳ�������޷�����P%d�����������Դ\n",r.cursor);
			return false;
		}
}