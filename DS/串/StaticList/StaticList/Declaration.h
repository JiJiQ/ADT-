#define MAXSIZE 1000
typedef char Data;	
typedef int Index;
typedef struct Node//静态链表结点
{
	Data data;
	int next;//指针
}Node,SList[MAXSIZE];
void InitStaticList(SList&);
int Malloc(SList&,int);
void Free(SList&,int);
//串ADT
Index Initchar(SList&,char*);
void Visit(SList&,Index);
Index StrAssign(SList&,Index);//由已知静态链表索引下标的串得到一个新的值相等的串，返回新串的下标
int StrCompare(SList&,Index,Index);//串判等
int StrLength(SList&,Index);//返回串的长度
Index StrConcat(SList&,Index,Index);//串连接
Index SubString(SList&,Index,Index);//求已知位置开始的子串
Index GetIndex(SList&,Index,Index,Index);





