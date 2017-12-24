#include<stdio.h>
#include<stdlib.h>
#include"Dec.h"
int main()
{
	FreeSList FList;
	AccessedSList AList;
	FreeInit(FList);
	AccessedInit(AList);
	int fHead = FMalloc(FList);
	int aHead = AMalloc(AList);
	Init(FList,fHead,AList,aHead);
	AVisit(AList,aHead);
	FVisit(FList,fHead);
	PCB p1,p2;
	p1.Name = 'A';p1.SpaceSize = 20;
	p2.Name = 'B',p2.SpaceSize = 40;
	Access(FList,fHead,AList,aHead,p1);
	AVisit(AList,aHead);
	FVisit(FList,fHead);
	system("pause");
	Access(FList,fHead,AList,aHead,p2);
	AVisit(AList,aHead);
	FVisit(FList,fHead);
	system("pause");
	Recover(FList,fHead,AList,aHead,p1);
	AVisit(AList,aHead);
	FVisit(FList,fHead);
	system("pause");
	return 0;
}