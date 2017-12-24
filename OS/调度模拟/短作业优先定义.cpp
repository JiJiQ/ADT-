#include<stdio.h>
#include<stdlib.h>
#include"Dec1（调度）.h"	
void SJF(JcbSet& j,OutJcb& OJ,JcbSet& Back)
{
	printf("SJF模拟过程。。。。。。\n");
	int Time(0);//时钟，从零时刻开始
	//按照执行时间长短对JcbSet作业集中的作业进行排序,排序算法为冒泡排序。
	//排序结果顺序即为作业的执行顺序
	JCB swap;//排序中间量
	int x = 0,y = 0;
	int backPT = 0;//备份作业服务时间。
	Back.rear = Back.front;//备份作业集，保持作业集初始状态。
	for( x = 1;x <= j.num;x++)//第x趟排序
	{
		for( y = 0;y < j.num - x;y++)//每趟较小值向后移动,以满足双端队列数据结构限定：队头指针增加使元素入队，front > rear
		{
			if(j.elem[y].arriveTime < j.elem[y+1].arriveTime)
			{
				swap = j.elem[y];
				j.elem[y] = j.elem[y+1];
				j.elem[y+1] = swap;
			}
		}
	}
	//计算每个作业的完成时间
	int NextJob = -1;//下一个到达作业的下标，初值为-1。若大于等于0，则当前时刻有新的作业提交，若小于0，则没有作业提交。
	for(Time = j.elem[j.front-1].arriveTime ;j.front > j.rear;  Time++,j.elem[j.front-1].processTime--)
	//以单位时间的速度开始计时,直到所有的作业执行完。同时当前作业的剩余时间减少一个时间单位，
	{
		printf("%2d时刻",Time);
		printf("作业编号：%2c , 作业到达时间：%2d，作业服务时间：%2d\n",j.elem[j.front-1].number,
																		  j.elem[j.front-1].arriveTime,
																		  j.elem[j.front-1].processTime);
		if(j.elem[j.front-1].processTime > 0)
		{
			//当前作业还没有执行完
			NextJob = StartProcess(j,Time);
			if(NextJob < 0)
				{//没有新的作业到达
				//当前作业继续顺利执行，开始下一轮循环，时钟增加一个单位时间，作业的剩余执行时间减少一个单位时间
			}else if(j.elem[j.front-1].processTime <= j.elem[NextJob].processTime){
					//当前作业还没有执行完，有新的作业到达
					//当前作业剩余执行时间比当到达作业执行时间短，当前作业继续执行
					OutProcess(j,OJ,NextJob);
					continue;//开始下一次，时钟增加一个时间单位，当前作业的剩余执行时间减少一个时间单位。
				}else{
					//当前作业还没有执行完，有新的作业到达
					//当前作业剩余执行时间比新到作业的执行时间长
					OutProcess(j,OJ,j.front-1);
				}
		}
		else{
			//当前作业执行完毕。
			//获取作业的完成时间
			j.elem[j.front-1].complishTime = Time;
			Back.rear--;
			backPT = Back.elem[Back.rear].processTime;//备份作业的服务时间。
			Back.elem[Back.rear] = j.elem[j.front-1];
			Back.elem[Back.rear].processTime = backPT;
			//备份作业集记录对应
			//在中断作业队列与未执行作业中选择剩余执行时间最短的作业。
			NextJob = StartProcess(j,Time);
			j.front--;//可能出现越界：应在循环末设置越界中断
									/*for(;j.front > j.rear;j.elem[j.front-1].processTime--)
								{
									j.front--;	
								}*/
			if(OJ.OutNum != 0){
				//存在被中断的作业
				InProcess(j,OJ);
				if(NextJob < 0){
					//此时没有提交作业
					continue;
				}else{
					if(j.elem[NextJob].processTime >= j.elem[j.front-1].processTime){
						OutProcess(j,OJ,NextJob);
						continue;
					}else{
						OutProcess(j,OJ,j.front-1);
					}
				}
			}
			else{
				//没有被中断的作业，存在还没有开始执行的作业，选中一个还没有开始执行的作业
				if(j.front > j.rear){
					j.front = NextJob+1;
					continue;
				}else{
					printf("所有作业均已执行完.\n");
				}
			}
		}
		if(j.front-1 < 0){break;}//越界中断
	}
	for(x = 0;x < Back.num;x++)
	{
		Back.elem[x].T = Back.elem[x].complishTime - Back.elem[x].arriveTime;
		Back.elem[x].W = Back.elem[x].T/Back.elem[x].processTime;
	}
	printf("打印模拟算法结果,打印结果按照模拟执行顺序输出\n");
	int i = Back.front - 1;
	if(i >= Back.rear){
		for(;i >= Back.rear;i--)
		{
			printf("作业编号：%2c , 作业完成时间：%2d，作业周转时间：%2d，作业带权周转时间：%2d",Back.elem[i].number,
																							Back.elem[i].complishTime,
																							Back.elem[i].T,
																							Back.elem[i].W);
		printf("\n");
		}
	}else{
		printf("队列中没有剩余作业\n");
	}
	int num(0);//带权时间总和
	for(x = 0;x < Back.num;x++)
	{
		num += Back.elem[x].W;
	}
	printf("SJF下，作业的平均带权时间为：%d\n",num/Back.num);
}