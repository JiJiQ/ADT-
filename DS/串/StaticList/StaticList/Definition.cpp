#include<stdio.h>
#include"Declaration.h"
void InitStaticList(SList& p)
{
	int i = 0;
	printf("2017/4/6：静态链表实现串的ADT\n");
	for(i=0;i<MAXSIZE-1;i++)
	{
		p[i].next = i+1;
	}
	p[MAXSIZE-1].next = -1;
}
int Malloc(SList& p,int num)
{
	int head(0);
	printf("申请空间大小：%d\n",num);
	if(p[0].next)
	{
		int i = p[0].next;
		p[0].next = p[i].next;//1,p[0].next并不一定等于1。
		head = i;
		num--;
		while(num > 0)
		{
			p[i].next = p[0].next;
			{i = p[i].next;
			p[0].next = p[i].next;}//两者顺序不能颠倒
			num--;
		}
		p[i].next = -1;
		return head;
	}else{
		return -1;
	}
}
void Free(SList& p,Index head)
{
	int i(head);
	while(p[i].next>0){
		i = p[i].next;
	}
	p[i].next = p[0].next;
	p[0].next = head;
}
Index Initchar(SList& p,char*string)
{
	
	int i = 0;
	int length = 0;
	for(;string[i]!='\0';i++){length++;}
	Index head = Malloc(p,length+1);
	Index cursor(p[head].next);
	i = 0;
	for(;string[i]!='\0';i++)
	{
		p[cursor].data = string[i];
		cursor = p[cursor].next;
	}
	p[head].data = length;
	return head;
}
void Visit(SList&p,Index head)
{
	Index cursor = p[head].next;
	for(;cursor > 0;cursor = p[cursor].next){printf("%c",p[cursor].data);}
	printf("\n");
}
Index StrAssign(SList& p,Index str)
{
	int length = 0;
	int cursor = str;
	//for(length = 0;cursor > 0;cursor = p[cursor].next)
	//{
	//	length++;
	//}//求串的长度
	cursor = p[str].next;
	Index head = Malloc(p,p[str].data+1);
	Index NewCursor = p[head].next;
	for(;cursor > 0;cursor = p[cursor].next,NewCursor = p[NewCursor].next)
	{
		p[NewCursor].data = p[cursor].data;
	}
	return head;
	
		
}
int StrLength(SList& p,Index head)
{
	/*int length = 0;
	head = p[head].next;
	for(;head > 0;head = p[head].next)
	{
		length++;
	}*/
	return p[head].data;
}
int StrCompare(SList& p,Index headA,Index headB)
{
	int lengthA(StrLength(p,headA));
	int lengthB(StrLength(p,headB));
	headA = p[headA].next;
	headB = p[headB].next;
	int value;
	for(;lengthA > 0&&lengthB > 0;lengthA--,lengthB--,
								  headA = p[headA].next,
								  headB = p[headB].next)
	{
		value = p[headA].data - p[headB].data;
		//
		if(value == 0)
		{
			continue;
		}else{
			return value;
		}
		//
	}
	if(lengthA==0 && lengthB == 0)
	{
		return 0;
	}else{
		//
		if(lengthA == 0){
			return -(p[headB].data);
		}else{
			return p[headA].data;
		}
	}
	return -100000;
}
Index StrConcat(SList& p,Index headFront,Index headRear)
{
	int lengthA(StrLength(p,headFront));
	int lengthB(StrLength(p,headRear));
	Index cursor(p[headFront].next);
	headRear = p[headRear].next;
	while(p[cursor].next > 0)
	{
		cursor = p[cursor].next;
	}
	p[cursor].next = headRear;
	return headFront;
}
Index SubString(SList& p,Index head,Index index)
{
	int cursor(p[head].next);
	if(index>StrLength(p,head)){return -1;}
	for(;index > 1;index--)
	{
		cursor = p[cursor].next;
	}
	Index a = Malloc(p,1);
	p[a].next = cursor;
	return a;
}	
Index GetIndex(SList& p,Index S,Index T,Index Pos)
{
	Index i(Pos),j(1);//i记录当前字符的位置
	Index cursor1 = S;//主串
	Index cursor2 = p[T].next;//匹配串
	Index cursor = p[S].next;//记录每次从匹配串第一个位置开始比较时，主串开始比较的字符的位置
	printf("串的模式匹配。。。\n");
	for(;Pos > 0;Pos--){
		cursor1 = p[cursor1].next;
	}
	while(i <= p[S].data && j <= p[T].data)
	{
		if(j == 1){cursor = cursor1;}
		if(p[cursor1].data == p[cursor2].data)
		{
			cursor1 = p[cursor1].next;
			cursor2 = p[cursor2].next;
			i++;j++;
		}else{
			cursor1 = p[cursor].next;
			cursor2 = p[T].next;
			i = i - (j - 1) + 1;
			j = 1;
		}
	}
	if(j > p[T].data){
		return i - p[T].data;}
	else{return -1;};
}