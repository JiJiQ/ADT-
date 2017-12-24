#include<stdio.h>
#include<stdlib.h>
#include"Declaration.h"
bool MazePath(Elemtype Maze[10][10],PosType start,PosType end)
{
	//概述：利用栈来记录当前通道块儿的前一个通道块儿
	//当前位置总是往东走，若当前位置不是路，则返回上一个没有走完四个方向的通道块儿，此通道块儿的方向记录di执行加一操作实现顺时针方向旋转
	
	Stack stack;
	InitStack(stack,100);
	PosType curpos = start;
	Elemtype* e;//方便记录当前通道块儿
	Elemtype tem;//正确调用出栈操作用，无实际意义
	do{
		printf("nima\n");
		if(Pass( Maze[ curpos.x ][ curpos.y ] ))
		{
			e = &(Maze[ curpos.x ][ curpos.y ]);
			e->Footprint = 1;//当前通道块儿留下“走过”痕迹
			PushS(stack,*e);//当前通道块儿入栈，加入路径
			if(Posjudge(curpos,end)){//当前通道块儿为出口
				TraverseStack(stack);
				return true;
			}
			curpos = NextPos(*e,1);//当前位置还没有入栈
			
		}else{
			if(!StackEmpty(stack))
			{
				PopS(stack,tem);
				while(stack.elem[stack.top-1].di == 4&&!StackEmpty(stack))//寻找一个尚没有四个方向都走过的通道块儿
				{
					MarkPrint(stack.elem[stack.top-1]);
					PopS(stack,tem);//返回上一个通道块儿
				}
			}
			if(stack.elem[stack.top - 1].di < 4)
			{
				e = &stack.elem[stack.top - 1];
				e->di++;//上一个通道块儿的下一步方向顺时针旋转
				PushS(stack,*e);//此通道块儿进入可行路径
				curpos = NextPos(*e,e->di);
			}/*else{时间复杂度比较大
				PopS(stack,tem);
				stack.elem[stack.top - 1].di++;
				e = &stack.elem[stack.top - 1];
				curpos = NextPos(*e,e->di);
			}*/
		}
	}while(!StackEmpty(stack));
	return false;
}
int main(void)
{
	int i = 0,j = 0;
	Elemtype maze[10][10];
	PosType start,end;
	start.x = 0;
	start.y =1;
	end.x = 9;
	end.y = 9;
	for(i = 0;i < 10;i++)
	{
		for(j = 0;j < 10;j++)
		{
			maze[i][j].seat.x = i;
			maze[i][j].seat.y = j;
			maze[i][j].Footprint = false;
			maze[i][j].di = 1;
			maze[i][j].value = true;
		}
	}
	MazePath(maze,start,end);
}