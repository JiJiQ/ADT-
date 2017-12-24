#include<stdio.h>
#include<stdlib.h>
#include"Dec1（调度）.h"	
int main()
{
	JcbSet JCBSET;
	JcbSet BackUp;
	OutJcb OUTJCBSET;
	InitJcbset(JCBSET,5);
	InitJcbset(BackUp,5);
	InitOutJcbset(OUTJCBSET,5);
	printf("OUT:%10d、JCB:%10d\n",OUTJCBSET.elem,JCBSET.elem);
	SJF(JCBSET,OUTJCBSET,BackUp);
	printf("SJF执行成功\n");
	printf("OUT:%10d、JCB:%10d\n",OUTJCBSET.elem,JCBSET.elem);
	free(OUTJCBSET.elem);
	printf("OUTJCBSET空间释放成功\n");
	free(JCBSET.elem);
	printf("JCBSET空间释放成功\n");
	return 0;
}