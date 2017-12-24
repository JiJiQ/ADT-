//方便模拟，作业个数，每个作业属性由Init函数内部设定，不再键入，具体设定情况为教材P94页实例
#define MAXSIZE 100
typedef struct jobControlblock{
	char number;
	int processTime;//预计处理时间
	int arriveTime;//到达时间
	int complishTime;//完成时间，初值为-1；
	int T;//周转时间
	int W;//带权周转时间
}JCB;//作业控制块
typedef struct JcbSet{
	JCB* elem;//作业集合基址
	int front;//队列头指针,指向队头元素的下一个位置。
	int rear;//队列尾指针，指向队尾元素。
	int num;//作业数量
}JcbSet;//执行作业双端队列
typedef struct OutJcb
{
	JCB* elem;//中断作业基址，存储结构为静态链表；
	int OutNum;//中断作业数量
}OutJcb;//阻塞作业线性表
void InitJcbset(JcbSet&,int num);//num个作业提交。
void InitOutJcbset(OutJcb& OJ,int num);
int StartProcess(JcbSet&,int);
bool OutProcess(JcbSet&,OutJcb&,int);//被中断作业出执行队列，入中断队列。返回值为函数执行状态。
bool InProcess(JcbSet&,OutJcb&);//被中断作业中剩余时间最短的作业出阻塞队列，入执行队列。返回值为函数执行状态
void FCFS(JcbSet&);//先来先服务算法模拟
void SJF(JcbSet&,OutJcb&,JcbSet&);//短作业优先算法模拟
void PSA(JcbSet&);//优先级调度算法模拟
void HRRM(JcbSet&);//高响应比优先调度算法模拟
void Visit1(JcbSet&);//用于作业集遍历
void Visit2(OutJcb&);
