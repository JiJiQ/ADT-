#include<stdio.h>
#include<stdlib.h>
#include"Declaration.h"
int main(void)
{
	SList List;
	InitStaticList(List);
	//测试：数据类型为int
	/*int cursor = head;
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
	}*/
	char a[] = "卿";
	char b[] = "吉俊卿";
	Index headA = Initchar(List,a);
	Index headB = Initchar(List,b);
	Index pos = 3;
	printf("匹配串\n");
	Visit(List,headA);
	printf("主串\n");
	Visit(List,headB);
	printf("匹配串在主串第%d个位置起始后的起始位置为：%d\n",pos,GetIndex(List,headB,headA,pos));
	return 0;
}