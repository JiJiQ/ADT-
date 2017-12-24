#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include"dec.h"
void InitVector(vectors& v)//初始化资源分配矩阵
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
		v.Finish[i] = false;//初始状态进程都没有执行完
	}
	for(int i = 0;i < 3;i++)
	{
		v.Available[i] = available[i];
		v.work[i] = available[i];
	}
}
void InitRequest(request& r,int cursor,int a,int b,int c)//初始化资源请求矩阵
{
	r.elem = (int*)malloc(3*sizeof(int));
	r.cursor = cursor;
	r.elem[0] = a;
	r.elem[1] = b;
	r.elem[2] = c;
}
bool SafetyCheck(vectors& v)//安全性检查
{
	int i = 0,j = 0;
	int corsor = -1;
	int FinishNum = 0;
	int CheckNum = 0;//避免死循环设置的终止变量（当系统可能死锁时FinishNum总会小于5）
	while(FinishNum < 5)
	{
		CheckNum++;
		for(i = 0;i < 5 && v.Finish[i] == false;i++)
		{
			//寻找一个可以执行完的进程，模拟执行完并回收该进程的资源
			for(j = 0;j < 3;j++)
			//检查进程的每一个资源是否都有可能分配到
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
			//模拟回收可以执行完进程的已分配资源
			for(j = 0;j < 3;j++)
			{
				v.work[j] += v.Allocation[corsor][j];
			}
			v.Finish[corsor] = true;
			FinishNum++;
		}
		if(CheckNum > 50)
		{
			//死循环避免
			return false;
		}
	}
	if(FinishNum == 5)
	{
		return true;
	}
}
bool BankerAlgorithm(vectors& v,request& r)//银行家算法
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
			printf("需求量设定有误：无法为P%d分配请求的资源\n",r.cursor);
			return false;
		}
		if(v.Request[r.cursor][j] > v.Available[j])
		{
			printf("系统当前剩余资源太少。无法为P%d分配请求的资源\n",r.cursor);
			return false;
		}
	}
	//更改系统当前资源向量标识
	for(j = 0;j < 3;j++)
	{
		v.Available[j] -= r.elem[j];
		v.Allocation[r.cursor][j] += r.elem[j];
	}
	if(SafetyCheck(v))
	{//若分配后系统安全，则分配，返回可分配标志
		printf("可以分配P%d进程请求的资源\n",r.cursor);
		return true;
	}else{
			for(j = 0;j < 3;j++)
		{//若分配后系统不安全，则取消分配并还原系统资源分配向量各项数据
			v.Available[j] += r.elem[j];
			v.Allocation[r.cursor][j] -= r.elem[j];
		}//返回不可分配标志
			printf("由于分配后会导致系统死锁，无法分配P%d进程请求的资源\n",r.cursor);
			return false;
		}
}