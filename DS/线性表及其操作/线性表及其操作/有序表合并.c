#include"DList.h"
#include<stdio.h>
void MergeList(pList A,pList B,pList C)
{
	int i=1,j=1;
	int min = 0;
	ElemType d,e;
	printf("算法:MergeList(两个有序表合并为一个有序表)\n");
	while(i<=GetLength(A)&&j<=GetLength(B))//经验教训：判断条件应该为<=,而不是！=
	{
		if( *GetElem(A,i,&d) <= *GetElem(B,j,&e) ) 
		{
			ListInsert(C,++min,d);
			i++;
			
		}else{
			ListInsert(C,++min,e);
			j++;
		}
	}
	//while(i<=A->length){
	//	GetElem(A,i++,&d);
	//	ListInsert(C,++min,d);
	//}
	//while(j<=B->length){
	//	GetElem(B,j++,&e);
	//	ListInsert(C,++min,e);
	//}
	for(;i>A->length&&j<=B->length;j++)
	{
		GetElem(B,j,&e);
		ListInsert(C,++min,e);
	}
	for(;j>B->length&&i<=A->length;i++)
	{
		GetElem(A,i,&d);
		ListInsert(C,++min,d);
		C->length++;
	}
}