#define MAXSIZE 100
typedef struct Elemtype
{
	int ArrivalTime;//�û�����ʱ��
	int DuraTimr;//�û�����ҵ����Ҫ���ѵ�ʱ��
}Elemtype;//�û����н��
typedef struct Node
{
	int OccurTime;//�¼�����ʱ��
	int NType;//�¼�����
	int next;//ָ��
}Node,SList[MAXSIZE];//�¼�����ڵ�
typedef struct Queue//�߼��ṹΪѭ������
{
	Elemtype* elem;
	int rear;//ָ���βԪ�صĺ�һ��λ��
	int front;//ָ���ͷԪ��
	int queuesize;
}Queue;
//����
void InitStaticList(SList&);
int Malloc(SList&);
void free(Node&,SList&,int);
//���У�
void InitQueue(Queue&,int);
void EnQueue(Queue&,Elemtype&);
Elemtype& DeQueue(Queue&,Elemtype&);
int Empty(Queue&);
int GetQueLength(Queue&);
void TraverseQueue(Queue&);
//����������
void CustomerArrived();//�ͻ������¼���
//���ݵ�ǰ�ͻ����Ѿ����������¼����������Ϣ�õ���һ���յ��ͻ��������Ϣ��
//�趨��i���е�һ���뿪�¼��������¼�����	
void CustomerDeparture();//�ͻ��뿪ʱ�䡣
//ɾ���������¼�����ͷ�ڵ�ʹ֮��Ϊ��ǰ�û���
