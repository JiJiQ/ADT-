#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include"Declaration.h"
void CreaSMatrix(TSMatrix& M)
{
	M.data = (Triple*)malloc((100+1)*sizeof(Triple));
	M.mu = 0;
	M.nu = 0;
	M.tu = 0;
}
void resign(TSMatrix& M)
{
	M.tu = 8;
	M.mu = 20;M.nu = 40;
	M.data[0].e = -1;M.data[0].i = -1;M.data[0].j = -1;
	M.data[1].e = 12;M.data[1].i = 1;M.data[1].j = 2;
	M.data[2].e = 9;M.data[2].i = 1;M.data[2].j = 3;
	M.data[3].e = -3;M.data[3].i = 3;M.data[3].j = 1;
	M.data[4].e = 14;M.data[4].i = 3;M.data[4].j = 6;
	M.data[5].e = 24;M.data[5].i = 4;M.data[5].j = 3;
	M.data[6].e = 18;M.data[6].i = 5;M.data[6].j = 2;
	M.data[7].e = 15;M.data[7].i = 6;M.data[7].j = 1;
	M.data[8].e = -7;M.data[8].i = 6;M.data[8].j = 4;

}
void PrintSMatrix(TSMatrix& M)
{
	int m = 0,n = 0;
	int num = 1;
	int arr[50][50];
	printf("矩阵打印。。。\n");
	for(m = 0;m < M.mu;m++)//nima
	{	
		for(n = 0;n < M.nu;n++)//nima
		{
			for(num = 1;num <= M.tu;num++)
			{
				if(m == M.data[num].i - 1 && n == M.data[num].j-1){
					arr[m][n] = M.data[num].e;
					break;
				}else{
					arr[m][n] = 0;
				}
			}
		}
	}
	for(m = 0;m < M.mu;m++){
		for(n = 0;n < M.nu;n++){
			printf("%3d",arr[m][n]);
		}printf("\n");
	}
}
void TransposeSMatrix(TSMatrix&M,TSMatrix&T)
{
	int i = 0;
	int m = 0,n = 0; 
	int col = 0;
	int num[10];
	int cpot[10];
	printf("稀疏矩阵的快速转置。。。\n");
	for(i = 0;i < 10;i++)//初始化
	{
		num[i] = 0;
		cpot[i] = 0;
	}
	for(i = 1;i <= M.tu;i++)//计算每一列非零元素的个数
	{	
		num[M.data[i].j]++;
	}
	cpot[1] = 1;
	for(i = 2;i < 10;i++)//计算每一列第一个元素所在转置后矩阵三元组的位置
	{
		cpot[i] = cpot[i-1] + num[i-1];
	}
	for(m = 1;m <= M.tu;m++)
	{
		col = M.data[m].j;
		n = cpot[col];
		T.data[n].i = M.data[m].j;
		T.data[n].j = M.data[m].i;
		T.data[n].e = M.data[m].e;
		cpot[col]++;
	}
	T.mu = M.nu;T.nu = M.mu;T.tu = M.tu;
}