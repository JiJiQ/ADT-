#define MAXSIZE 100
typedef int data;
typedef struct Node//��̬������
{
	data data;
	int next;//ָ��
}Node,SList[MAXSIZE];
void InitStaticList(SList&);
int Malloc(SList&,int);
void free(Node&,SList&,int);
