#include<stdio.h>
#include<stdlib.h>
#include"Declaration.h"
int main(void)
{
	SList List;
	InitStaticList(List);
	//���ԣ���������Ϊint
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
	char a[] = "��";
	char b[] = "������";
	Index headA = Initchar(List,a);
	Index headB = Initchar(List,b);
	Index pos = 3;
	printf("ƥ�䴮\n");
	Visit(List,headA);
	printf("����\n");
	Visit(List,headB);
	printf("ƥ�䴮��������%d��λ����ʼ�����ʼλ��Ϊ��%d\n",pos,GetIndex(List,headB,headA,pos));
	return 0;
}