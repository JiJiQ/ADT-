#define MAXSIZE 100
typedef struct Node
{
	int e;//ָ��
	int m;//ϵ��
	int next;//ָ��
}Node,SList[MAXSIZE];
void InitStaticList(SList&);
int Malloc(SList&);
void free(Node&,SList&,int);
int CreatPoly(SList&,int size);//����size��Ķ���ʽ������ͷ�ڵ���±�
void PrintPoly(SList&,int);//�ṩ��������̬��������ʽͷ�ڵ���±�
int PolyLength(SList&,int);//�ṩ��������̬��������ʽͷ�ڵ��±�
void AddPoly(SList&,int,int);//a=a+b��������b
int cmp(SList&,int,int);
