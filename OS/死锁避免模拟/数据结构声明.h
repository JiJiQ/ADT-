typedef struct vectors{
	int Available[3];//系统当前时刻可用Rj类资源。
	int Max[5][3];//Pi进程对Rj类资源的最大需求量。
	int Allocation[5][3];//系统当前时刻Pi进程占用Rj资源的数目
	int Need[5][3];//Pi进程执行完对Rj资源的需求量；
	int Request[5][3];//Pi进程提交对Rj资源的需求量。
	int work[3];//系统当前时刻可用Rj资源的数目。动态变化。
	bool Finish[5];//Pi进程是否执行完状态标识。
	int pNum;
}vectors;//系统资源分配向量集
typedef struct request
{
	int cursor;//提交资源请求进程标号
	int* elem;//堆分配存储提交的资源请求。
}request;//
void InitVector(vectors&);//按照要求初始化系统资源分配向量
void InitRequest(request&,int,int,int,int);//初始化资源请求向量。形参为请求向量集，进程标号，资源请求分量。
bool SafetyCheck(vectors&);//系统在特定资源分配情况下的安全性检查，形参为资源请求向量集
bool BankerAlgorithm(vectors&,request&);//银行家算法，形参为资源分配向量集和资源请求向量