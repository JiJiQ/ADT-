#define MAXSIZE 100
static int minSize = 2;typedef struct FreeTable
{
	int Number;//空闲分区号
	int PartitionSize;//空闲分区大小，单位为KB
	int StartAddress;//空闲分区起始地址，单位为K
	int EndAddress;//空闲分区块最后末尾地址，单位为K
}FreeTable;
typedef struct AccessedTable
{
	int Number;//分区号
	char Name;//使用该分区的作业名
	int PartitionSize;//分区大小，单位为KB;
	int StartAddress;//分区起始地址，单位为K
	int EndAddress;//分区末尾地址，单位为K
}AccessedTable; 
typedef struct FNode
{
	FreeTable data;
	int next;//指针
}FNode,FreeSList[MAXSIZE];//空闲分区表数据结构：静态链表
typedef struct ANode
{
	AccessedTable data;
	int next;//指针
}ANode,AccessedSList[MAXSIZE];//已占分区表数据结构：静态链表
typedef struct PCB
{
	char Name;//进程名
	int SpaceSize;//申请内存空间大小
}PCB;
void FreeInit(FreeSList&);//初始化空闲分区表，只有头节点表示表为空
void AccessedInit(AccessedSList&);//初始化已占分区表，只有头节点表示表为空
int FMalloc(FreeSList&);//空闲分区表项申请函数
void Ffree(FreeSList&,int);//空闲分区表项释放函数
int AMalloc(AccessedSList&);//已占分区表项申请函数
void Afree(AccessedSList&,int);//空闲分区表项释放函数
void Init(FreeSList&,int,AccessedSList&,int);//两张表初始化，形参为静态链表空间以及两张表的头节点
bool Access(FreeSList&,int,AccessedSList&,int,PCB&);//内存分配方法，形参为静态链表空间，两张表的头节点，提交的进程
bool Recover(FreeSList&,int,AccessedSList&,int,PCB&);//内存回收方法，形参为静态链表空间，两张表的头节点，执行完的进程
void FVisit(FreeSList&,int);//空闲分区表遍历，形参为静态链表空间，空闲分区表头节点
void AVisit(AccessedSList&,int);//已占分区表遍历，形参为静态链表空间，已占分区表头节点