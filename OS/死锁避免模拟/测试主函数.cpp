#include<stdio.h>
#include<stdlib.h>
#include"dec.h"
int main()
{
	//变量的定义、声明、数据结构的初始化。
	vectors V;
	request R;
	InitVector(V);
	InitRequest(R,1,1,0,2);
	//是否分配P1进程请求的资源
	BankerAlgorithm(V,R);
	free(R.elem);
	system("pause");
	//是否分配P4进程请求的资源
	InitRequest(R,4,3,3,0);
	BankerAlgorithm(V,R);
	free(R.elem);
	system("pause");
	//是否分配P0进程请求的资源
	InitRequest(R,0,0,2,0);
	BankerAlgorithm(V,R);
	free(R.elem);
	return 0;
}