#include<stdio.h>
#include<stdlib.h>
#include"Declaration.h"
#define a 100;
int main(void)
{
	char arr[] = "[([][])]";
	printf("%d",0);
	if(Index(arr,8)){
		printf("%s\n","�ַ���ƥ��");
	}
	else{
		printf("�ַ�����ƥ��\n");
	}
}