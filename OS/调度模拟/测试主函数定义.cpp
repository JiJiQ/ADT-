#include<stdio.h>
#include<stdlib.h>
#include"Dec1�����ȣ�.h"	
int main()
{
	JcbSet JCBSET;
	JcbSet BackUp;
	OutJcb OUTJCBSET;
	InitJcbset(JCBSET,5);
	InitJcbset(BackUp,5);
	InitOutJcbset(OUTJCBSET,5);
	printf("OUT:%10d��JCB:%10d\n",OUTJCBSET.elem,JCBSET.elem);
	SJF(JCBSET,OUTJCBSET,BackUp);
	printf("SJFִ�гɹ�\n");
	printf("OUT:%10d��JCB:%10d\n",OUTJCBSET.elem,JCBSET.elem);
	free(OUTJCBSET.elem);
	printf("OUTJCBSET�ռ��ͷųɹ�\n");
	free(JCBSET.elem);
	printf("JCBSET�ռ��ͷųɹ�\n");
	return 0;
}