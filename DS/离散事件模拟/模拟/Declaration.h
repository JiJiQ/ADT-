#define MAXSIZE 100
typedef struct Elemtype
{
	int ArrivalTime;//用户到达时间
	int DuraTimr;//用户办理业务需要花费的时间
}Elemtype;//用户队列结点
typedef struct Node
{
	int OccurTime;//事件发生时刻
	int NType;//事件类型
	int next;//指针
}Node,SList[MAXSIZE];//事件链表节点
typedef struct Queue//逻辑结构为循环队列
{
	Elemtype* elem;
	int rear;//指向队尾元素的后一个位置
	int front;//指向队头元素
	int queuesize;
}Queue;
//链表：
void InitStaticList(SList&);
int Malloc(SList&);
void free(Node&,SList&,int);
//队列：
void InitQueue(Queue&,int);
void EnQueue(Queue&,Elemtype&);
Elemtype& DeQueue(Queue&,Elemtype&);
int Empty(Queue&);
int GetQueLength(Queue&);
void TraverseQueue(Queue&);
//任务处理函数：
void CustomerArrived();//客户到达事件。
//依据当前客户（已经出待处理事件链表）相关信息得到下一个刚到客户的相关信息；
//设定第i队列的一个离开事件并插入事件链表	
void CustomerDeparture();//客户离开时间。
//删除待处理事件链表头节点使之成为当前用户。
