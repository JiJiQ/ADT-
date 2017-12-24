typedef char Elemtype;
typedef struct Stack
{
	Elemtype* elem;
	int top;//top指向栈顶元素的下一个位置
	int base;//base指向栈底元素
	int stacksize;//栈的大小
}Stack;
typedef struct Queue//逻辑结构为循环队列
{
	Elemtype* elem;
	int rear;//指向队尾元素的后一个位置
	int front;//指向队头元素
	int queuesize;
}Queue;
//栈
void InitStack(Stack&,int);
void PushS(Stack&,Elemtype&);
Elemtype& PopS(Stack&,Elemtype&);
void TraverseStack(Stack&);
void conversion(int,int);
bool EmptyS(Stack&);
//队列
void InitQueue(Queue&,int);
void EnQueue(Queue&,Elemtype&);
Elemtype& DeQueue(Queue&,Elemtype&);
int Empty(Queue&);
int GetQueLength(Queue&);
void TraverseQueue(Queue&);
void LineEidt(char* ,int);
bool Index(char*,int);
