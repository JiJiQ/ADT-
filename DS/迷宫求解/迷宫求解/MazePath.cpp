#include"Declaration.h"
#include<stdio.h>
bool MazePath(Elemtype Maze[10][10],PosType start,PosType end)
{
	//����������ջ����¼��ǰͨ�������ǰһ��ͨ�����
	//��ǰλ�����������ߣ�����ǰλ�ò���·���򷵻���һ��û�������ĸ������ͨ���������ͨ������ķ����¼diִ�м�һ����ʵ��˳ʱ�뷽����ת
	printf("nima");
	Stack stack;
	InitStack(stack,100);
	PosType curpos = start;
	Elemtype* e;//�����¼��ǰͨ�����
	Elemtype tem;//��ȷ���ó�ջ�����ã���ʵ������
	do{
		if(Pass( Maze[ curpos.x ][ curpos.y ] ))
		{
			e = &(Maze[ curpos.x ][ curpos.y ]);
			e->Footprint = 1;//��ǰͨ��������¡��߹����ۼ�
			PushS(stack,*e);//��ǰͨ�������ջ������·��
			if(Posjudge(curpos,end)){//��ǰͨ�����Ϊ����
				TraverseStack(stack);
				return true;
			}
			curpos = NextPos(*e,1);//��ǰλ�û�û����ջ
			
		}else{
			if(!StackEmpty(stack))
			{
				PopS(stack,tem);
				while(stack.elem[stack.top-1].di == 4&&!StackEmpty(stack))//Ѱ��һ����û���ĸ������߹���ͨ�����
				{
					MarkPrint(stack.elem[stack.top-1]);
					PopS(stack,tem);//������һ��ͨ�����
				}
			}
			if(stack.elem[stack.top - 1].di < 4)
			{
				e = &stack.elem[stack.top - 1];
				e->di++;//��һ��ͨ���������һ������˳ʱ����ת
				PushS(stack,*e);//��ͨ������������·��
				curpos = NextPos(*e,e->di);
			}/*else{ʱ�临�ӶȱȽϴ�
				PopS(stack,tem);
				stack.elem[stack.top - 1].di++;
				e = &stack.elem[stack.top - 1];
				curpos = NextPos(*e,e->di);
			}*/
		}
	}while(!StackEmpty(stack));
	return false;
}