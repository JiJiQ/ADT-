typedef struct{
	int x;
	int y;
}PosType;
typedef struct{
	bool value;//ͨ�������ǽ����·,trueΪ·��falseΪǽ��
	PosType seat;//ͨ������ġ����ꡱ
	int di;//ת����ʱ��һ��ͨ����������λ�ã�1��2��3��4�����������ϣ�����
	bool Footprint;//��־��ǰ����Ƿ��߹�,1Ϊ���߹�
}Elemtype;
typedef struct Stack
{
	Elemtype* elem;
	int top;//topָ��ջ��Ԫ�ص���һ��λ��
	int base;//baseָ��ջ��Ԫ��
	int stacksize;//ջ�Ĵ�С
}Stack;
typedef struct Queue//�߼��ṹΪѭ������
{
	Elemtype* elem;
	int rear;//ָ���βԪ�صĺ�һ��λ��
	int front;//ָ���ͷԪ��
	int queuesize;
}Queue;
//ջ
void InitStack(Stack&,int);
bool StackEmpty(Stack&);
void PushS(Stack&,Elemtype&);
Elemtype& PopS(Stack&,Elemtype&);
void TraverseStack(Stack&);
void conversion(int,int);
void LineEidt(char* ,int);
void MarkPrint(Elemtype&);
bool Pass(Elemtype&);
PosType& NextPos(Elemtype&,int);
bool Posjudge(PosType&,PosType&);
void CurAssign(Elemtype& e,bool value,PosType seat,int di,bool foot);
