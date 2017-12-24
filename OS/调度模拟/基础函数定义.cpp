#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include"Dec1（调度）.h"	
void InitJcbset(JcbSet& j,int num)//作业集初始化
{
	j.elem = (JCB*)malloc(5 * sizeof(JCB));
	j.num = num;
	j.elem[0].number = 'A';j.elem[0].arriveTime = 0;j.elem[0].processTime = 4;
	j.elem[1].number = 'B';j.elem[1].arriveTime = 1;j.elem[1].processTime = 3;
	j.elem[2].number = 'C';j.elem[2].arriveTime = 5;j.elem[2].processTime = 4;
	j.elem[3].number = 'D';j.elem[3].arriveTime = 3;j.elem[3].processTime = 2;
	j.elem[4].number = 'E';j.elem[4].arriveTime = 6;j.elem[4].processTime = 4;
	j.rear = 0;
	j.front = 5;
}
void InitOutJcbset(OutJcb& OJ,int num)
{
	OJ.elem = (JCB*)malloc(5*sizeof(JCB));
	OJ.OutNum = 0;
}
int StartProcess(JcbSet& j,int time)
{
	int i = j.front-2;
	if(time >= j.elem[i].arriveTime){
		return i;
	}else{
		return -1;
	}
}
bool OutProcess(JcbSet& j,OutJcb& OJ,int index)
{
	if(j.num > 0){
		OJ.elem[OJ.OutNum] = j.elem[index];
		OJ.OutNum++;
		for(;index < j.front-1;index++)
		{
			j.elem[index] = j.elem[index + 1];
		}
		j.front--;
		j.num--;
		return true;
	}else{
		return false;
	}
}
bool InProcess(JcbSet& j,OutJcb& OJ)
{
	int corsor = 0;
	JCB swap;
	if(OJ.OutNum > 0){
		//阻塞队列中筛选剩余执行时间最少的作业；
		//心得：
		for(corsor;corsor < OJ.OutNum - 1;corsor++)
		{
			if(OJ.elem[corsor].processTime <= OJ.elem[corsor+1].processTime){
				swap = OJ.elem[corsor];
				OJ.elem[corsor] = OJ.elem[corsor+1];
				OJ.elem[corsor+1] = swap;
			}
		}
		//筛选结束后，剩余时间最短的结点的下标为0。

		if(OJ.OutNum > 0){
		
				j.elem[j.front] = OJ.elem[OJ.OutNum-1];
				j.front++;
				j.num++;
				OJ.OutNum--;
				return true;
		}else{
			return false;//若执行队列已满，无法插入。
			}
	}else{
		return false;//若中断队列中没有作业，无法插入
	}
}
void PSA(JcbSet& j){}
void HRRM(JcbSet& j){}
void Visit1(JcbSet& j)
{
	int i = j.front - 1;
	if(i >= j.rear){
		for(;i >= j.rear;i--)
		{
			printf("作业编号：%2c , 作业到达时间：%2d，作业服务时间：%2d",j.elem[i].number,
																		  j.elem[i].arriveTime,
																		  j.elem[i].processTime);
			printf("\n");
		}
	}else{
		printf("队列中没有剩余作业\n");
	}
}
void Visit2(OutJcb& OJ)
{
	int i = 0;
	for(i;i < OJ.OutNum;i++)
	{
		printf("作业编号：%2c , 作业到达时间：%2d，作业服务时间：%2d",OJ.elem[i].number,
																	OJ.elem[i].arriveTime,
																	OJ.elem[i].processTime);
			printf("\n");
	}
}