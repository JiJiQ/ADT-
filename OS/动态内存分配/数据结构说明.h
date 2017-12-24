#define MAXSIZE 100
static int minSize = 2;typedef struct FreeTable
{
	int Number;//���з�����
	int PartitionSize;//���з�����С����λΪKB
	int StartAddress;//���з�����ʼ��ַ����λΪK
	int EndAddress;//���з��������ĩβ��ַ����λΪK
}FreeTable;
typedef struct AccessedTable
{
	int Number;//������
	char Name;//ʹ�ø÷�������ҵ��
	int PartitionSize;//������С����λΪKB;
	int StartAddress;//������ʼ��ַ����λΪK
	int EndAddress;//����ĩβ��ַ����λΪK
}AccessedTable; 
typedef struct FNode
{
	FreeTable data;
	int next;//ָ��
}FNode,FreeSList[MAXSIZE];//���з��������ݽṹ����̬����
typedef struct ANode
{
	AccessedTable data;
	int next;//ָ��
}ANode,AccessedSList[MAXSIZE];//��ռ���������ݽṹ����̬����
typedef struct PCB
{
	char Name;//������
	int SpaceSize;//�����ڴ�ռ��С
}PCB;
void FreeInit(FreeSList&);//��ʼ�����з�����ֻ��ͷ�ڵ��ʾ��Ϊ��
void AccessedInit(AccessedSList&);//��ʼ����ռ������ֻ��ͷ�ڵ��ʾ��Ϊ��
int FMalloc(FreeSList&);//���з����������뺯��
void Ffree(FreeSList&,int);//���з��������ͷź���
int AMalloc(AccessedSList&);//��ռ�����������뺯��
void Afree(AccessedSList&,int);//���з��������ͷź���
void Init(FreeSList&,int,AccessedSList&,int);//���ű��ʼ�����β�Ϊ��̬����ռ��Լ����ű��ͷ�ڵ�
bool Access(FreeSList&,int,AccessedSList&,int,PCB&);//�ڴ���䷽�����β�Ϊ��̬����ռ䣬���ű��ͷ�ڵ㣬�ύ�Ľ���
bool Recover(FreeSList&,int,AccessedSList&,int,PCB&);//�ڴ���շ������β�Ϊ��̬����ռ䣬���ű��ͷ�ڵ㣬ִ����Ľ���
void FVisit(FreeSList&,int);//���з�����������β�Ϊ��̬����ռ䣬���з�����ͷ�ڵ�
void AVisit(AccessedSList&,int);//��ռ������������β�Ϊ��̬����ռ䣬��ռ������ͷ�ڵ�