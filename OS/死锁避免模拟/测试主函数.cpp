#include<stdio.h>
#include<stdlib.h>
#include"dec.h"
int main()
{
	//�����Ķ��塢���������ݽṹ�ĳ�ʼ����
	vectors V;
	request R;
	InitVector(V);
	InitRequest(R,1,1,0,2);
	//�Ƿ����P1�����������Դ
	BankerAlgorithm(V,R);
	free(R.elem);
	system("pause");
	//�Ƿ����P4�����������Դ
	InitRequest(R,4,3,3,0);
	BankerAlgorithm(V,R);
	free(R.elem);
	system("pause");
	//�Ƿ����P0�����������Դ
	InitRequest(R,0,0,2,0);
	BankerAlgorithm(V,R);
	free(R.elem);
	return 0;
}