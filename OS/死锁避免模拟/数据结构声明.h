typedef struct vectors{
	int Available[3];//ϵͳ��ǰʱ�̿���Rj����Դ��
	int Max[5][3];//Pi���̶�Rj����Դ�������������
	int Allocation[5][3];//ϵͳ��ǰʱ��Pi����ռ��Rj��Դ����Ŀ
	int Need[5][3];//Pi����ִ�����Rj��Դ����������
	int Request[5][3];//Pi�����ύ��Rj��Դ����������
	int work[3];//ϵͳ��ǰʱ�̿���Rj��Դ����Ŀ����̬�仯��
	bool Finish[5];//Pi�����Ƿ�ִ����״̬��ʶ��
	int pNum;
}vectors;//ϵͳ��Դ����������
typedef struct request
{
	int cursor;//�ύ��Դ������̱��
	int* elem;//�ѷ���洢�ύ����Դ����
}request;//
void InitVector(vectors&);//����Ҫ���ʼ��ϵͳ��Դ��������
void InitRequest(request&,int,int,int,int);//��ʼ����Դ�����������β�Ϊ���������������̱�ţ���Դ���������
bool SafetyCheck(vectors&);//ϵͳ���ض���Դ��������µİ�ȫ�Լ�飬�β�Ϊ��Դ����������
bool BankerAlgorithm(vectors&,request&);//���м��㷨���β�Ϊ��Դ��������������Դ��������