#define MAXSIZE 100
typedef struct Node
{
	int e;//指数
	int m;//系数
	int next;//指针
}Node,SList[MAXSIZE];
void InitStaticList(SList&);
int Malloc(SList&);
void free(Node&,SList&,int);
int CreatPoly(SList&,int size);//构造size项的多项式，返回头节点的下标
void PrintPoly(SList&,int);//提供参数：静态链表，多项式头节点的下标
int PolyLength(SList&,int);//提供参数：静态链表，多项式头节点下标
void AddPoly(SList&,int,int);//a=a+b，并销毁b
int cmp(SList&,int,int);
