#define MAXSIZE 1000
typedef char Data;	
typedef int Index;
typedef struct Node//��̬������
{
	Data data;
	int next;//ָ��
}Node,SList[MAXSIZE];
void InitStaticList(SList&);
int Malloc(SList&,int);
void Free(SList&,int);
//��ADT
Index Initchar(SList&,char*);
void Visit(SList&,Index);
Index StrAssign(SList&,Index);//����֪��̬���������±�Ĵ��õ�һ���µ�ֵ��ȵĴ��������´����±�
int StrCompare(SList&,Index,Index);//���е�
int StrLength(SList&,Index);//���ش��ĳ���
Index StrConcat(SList&,Index,Index);//������
Index SubString(SList&,Index,Index);//����֪λ�ÿ�ʼ���Ӵ�
Index GetIndex(SList&,Index,Index,Index);





