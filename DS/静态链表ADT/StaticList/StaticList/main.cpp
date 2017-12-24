#include<stdio.h>
#include<stdlib.h>
#include"Declaration.h"
int main(void)
{
	int head;
	SList List;
	InitStaticList(List);
	head = Malloc(List,10);
	//测试：数据类型为int
	int cursor = head;
	for(int i = 0; cursor > 0 ;i++)
	{
		List[cursor].data = i;
		cursor = List[cursor].next;
	}
	cursor = head;
	for(;cursor > 0;)
	{
		printf("%d\n",List[cursor].data);
		cursor = List[cursor].next;
	}
	return 0;
}