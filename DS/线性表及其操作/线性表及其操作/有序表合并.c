#include"DList.h"
#include<stdio.h>
void MergeList(pList A,pList B,pList C)
{
	int i=1,j=1;
	int min = 0;
	ElemType d,e;
	printf("�㷨:MergeList(���������ϲ�Ϊһ�������)\n");
	while(i<=GetLength(A)&&j<=GetLength(B))//�����ѵ���ж�����Ӧ��Ϊ<=,�����ǣ�=
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