typedef char Elemtype;
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
void PushS(Stack&,Elemtype&);
Elemtype& PopS(Stack&,Elemtype&);
void TraverseStack(Stack&);
void conversion(int,int);
bool EmptyS(Stack&);
//����
void InitQueue(Queue&,int);
void EnQueue(Queue&,Elemtype&);
Elemtype& DeQueue(Queue&,Elemtype&);
int Empty(Queue&);
int GetQueLength(Queue&);
void TraverseQueue(Queue&);
void LineEidt(char* ,int);
bool Index(char*,int);
