#include<stdio.h>
#include"Dec1（调度）.h"
void FCFS(JcbSet& j)//先来先服务算法
{
	printf("先来先服务模拟结果按执行顺序输出\n");
	//按照到达时间对jcb中的结点进行排序,排序算法为冒泡排序。
	//排序结果顺序即为作业的执行顺序
	JCB swap;//排序中间量
	int x = 0,y = 0;
	for( x = 1;x <= j.num;x++)//第x趟排序
	{
		for( y = 0;y < j.num - x;y++)//每趟较大值向后移动
		{
			if(j.elem[y].arriveTime > j.elem[y+1].arriveTime)
			{
				swap = j.elem[y];
				j.elem[y] = j.elem[y+1];
				j.elem[y+1] = swap;
			}
		}
	}
	//计算每个作业的完成时间
	int Time(0);//时钟，零时刻开始
	for( x = 0;x < j.num;x++)
	{
		j.elem[x].complishTime = Time + j.elem[x].processTime;
		Time += j.elem[x].processTime;
	}
	//计算每个作业的周转时间、带权周转时间
	for(x = 0;x < j.num;x++)
	{
		j.elem[x].T = j.elem[x].complishTime - j.elem[x].arriveTime;
		j.elem[x].W = j.elem[x].T/j.elem[x].processTime;
	}
	//打印模拟算法结果,打印结果按照模拟执行顺序输出
	for(x = 0;x < 5;x++)
	{
		printf("作业编号：%2c , 作业完成时间：%2d，作业周转时间：%2d，作业带权周转时间：%2d",j.elem[x].number,
																							j.elem[x].complishTime,
																							j.elem[x].T,
																							j.elem[x].W);
		printf("\n");
	}
	int num(0);//带权时间总和
	for(x = 0;x < j.num;x++)
	{
		num += j.elem[x].W;
	}
	printf("FCFS下，作业的平均带权时间为：%d\n",num/j.num);
}