#include<stdio.h>
#include<stdlib.h>
#include"Dec1�����ȣ�.h"	
void SJF(JcbSet& j,OutJcb& OJ,JcbSet& Back)
{
	printf("SJFģ����̡�����������\n");
	int Time(0);//ʱ�ӣ�����ʱ�̿�ʼ
	//����ִ��ʱ�䳤�̶�JcbSet��ҵ���е���ҵ��������,�����㷨Ϊð������
	//������˳��Ϊ��ҵ��ִ��˳��
	JCB swap;//�����м���
	int x = 0,y = 0;
	int backPT = 0;//������ҵ����ʱ�䡣
	Back.rear = Back.front;//������ҵ����������ҵ����ʼ״̬��
	for( x = 1;x <= j.num;x++)//��x������
	{
		for( y = 0;y < j.num - x;y++)//ÿ�˽�Сֵ����ƶ�,������˫�˶������ݽṹ�޶�����ͷָ������ʹԪ����ӣ�front > rear
		{
			if(j.elem[y].arriveTime < j.elem[y+1].arriveTime)
			{
				swap = j.elem[y];
				j.elem[y] = j.elem[y+1];
				j.elem[y+1] = swap;
			}
		}
	}
	//����ÿ����ҵ�����ʱ��
	int NextJob = -1;//��һ��������ҵ���±꣬��ֵΪ-1�������ڵ���0����ǰʱ�����µ���ҵ�ύ����С��0����û����ҵ�ύ��
	for(Time = j.elem[j.front-1].arriveTime ;j.front > j.rear;  Time++,j.elem[j.front-1].processTime--)
	//�Ե�λʱ����ٶȿ�ʼ��ʱ,ֱ�����е���ҵִ���ꡣͬʱ��ǰ��ҵ��ʣ��ʱ�����һ��ʱ�䵥λ��
	{
		printf("%2dʱ��",Time);
		printf("��ҵ��ţ�%2c , ��ҵ����ʱ�䣺%2d����ҵ����ʱ�䣺%2d\n",j.elem[j.front-1].number,
																		  j.elem[j.front-1].arriveTime,
																		  j.elem[j.front-1].processTime);
		if(j.elem[j.front-1].processTime > 0)
		{
			//��ǰ��ҵ��û��ִ����
			NextJob = StartProcess(j,Time);
			if(NextJob < 0)
				{//û���µ���ҵ����
				//��ǰ��ҵ����˳��ִ�У���ʼ��һ��ѭ����ʱ������һ����λʱ�䣬��ҵ��ʣ��ִ��ʱ�����һ����λʱ��
			}else if(j.elem[j.front-1].processTime <= j.elem[NextJob].processTime){
					//��ǰ��ҵ��û��ִ���꣬���µ���ҵ����
					//��ǰ��ҵʣ��ִ��ʱ��ȵ�������ҵִ��ʱ��̣���ǰ��ҵ����ִ��
					OutProcess(j,OJ,NextJob);
					continue;//��ʼ��һ�Σ�ʱ������һ��ʱ�䵥λ����ǰ��ҵ��ʣ��ִ��ʱ�����һ��ʱ�䵥λ��
				}else{
					//��ǰ��ҵ��û��ִ���꣬���µ���ҵ����
					//��ǰ��ҵʣ��ִ��ʱ����µ���ҵ��ִ��ʱ�䳤
					OutProcess(j,OJ,j.front-1);
				}
		}
		else{
			//��ǰ��ҵִ����ϡ�
			//��ȡ��ҵ�����ʱ��
			j.elem[j.front-1].complishTime = Time;
			Back.rear--;
			backPT = Back.elem[Back.rear].processTime;//������ҵ�ķ���ʱ�䡣
			Back.elem[Back.rear] = j.elem[j.front-1];
			Back.elem[Back.rear].processTime = backPT;
			//������ҵ����¼��Ӧ
			//���ж���ҵ������δִ����ҵ��ѡ��ʣ��ִ��ʱ����̵���ҵ��
			NextJob = StartProcess(j,Time);
			j.front--;//���ܳ���Խ�磺Ӧ��ѭ��ĩ����Խ���ж�
									/*for(;j.front > j.rear;j.elem[j.front-1].processTime--)
								{
									j.front--;	
								}*/
			if(OJ.OutNum != 0){
				//���ڱ��жϵ���ҵ
				InProcess(j,OJ);
				if(NextJob < 0){
					//��ʱû���ύ��ҵ
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
				//û�б��жϵ���ҵ�����ڻ�û�п�ʼִ�е���ҵ��ѡ��һ����û�п�ʼִ�е���ҵ
				if(j.front > j.rear){
					j.front = NextJob+1;
					continue;
				}else{
					printf("������ҵ����ִ����.\n");
				}
			}
		}
		if(j.front-1 < 0){break;}//Խ���ж�
	}
	for(x = 0;x < Back.num;x++)
	{
		Back.elem[x].T = Back.elem[x].complishTime - Back.elem[x].arriveTime;
		Back.elem[x].W = Back.elem[x].T/Back.elem[x].processTime;
	}
	printf("��ӡģ���㷨���,��ӡ�������ģ��ִ��˳�����\n");
	int i = Back.front - 1;
	if(i >= Back.rear){
		for(;i >= Back.rear;i--)
		{
			printf("��ҵ��ţ�%2c , ��ҵ���ʱ�䣺%2d����ҵ��תʱ�䣺%2d����ҵ��Ȩ��תʱ�䣺%2d",Back.elem[i].number,
																							Back.elem[i].complishTime,
																							Back.elem[i].T,
																							Back.elem[i].W);
		printf("\n");
		}
	}else{
		printf("������û��ʣ����ҵ\n");
	}
	int num(0);//��Ȩʱ���ܺ�
	for(x = 0;x < Back.num;x++)
	{
		num += Back.elem[x].W;
	}
	printf("SJF�£���ҵ��ƽ����Ȩʱ��Ϊ��%d\n",num/Back.num);
}