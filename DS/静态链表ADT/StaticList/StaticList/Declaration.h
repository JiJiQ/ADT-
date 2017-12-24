#define MAXSIZE 100
typedef int data;
typedef struct Node//静态链表结点
{
	data data;
	int next;//指针
}Node,SList[MAXSIZE];
void InitStaticList(SList&);
int Malloc(SList&,int);
void free(Node&,SList&,int);
