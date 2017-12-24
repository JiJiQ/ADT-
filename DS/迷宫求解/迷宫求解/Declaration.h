typedef struct{
	int x;
	int y;
}PosType;
typedef struct{
	bool value;//通道块儿是墙还是路,true为路，false为墙。
	PosType seat;//通道块儿的“坐标”
	int di;//转向你时下一个通道块儿的相对位置（1，2，3，4代表东，西，南，北）
	bool Footprint;//标志当前块儿是否走过,1为已走过
}Elemtype;
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
