//����ģ�⣬��ҵ������ÿ����ҵ������Init�����ڲ��趨�����ټ��룬�����趨���Ϊ�̲�P94ҳʵ��
#define MAXSIZE 100
typedef struct jobControlblock{
	char number;
	int processTime;//Ԥ�ƴ���ʱ��
	int arriveTime;//����ʱ��
	int complishTime;//���ʱ�䣬��ֵΪ-1��
	int T;//��תʱ��
	int W;//��Ȩ��תʱ��
}JCB;//��ҵ���ƿ�
typedef struct JcbSet{
	JCB* elem;//��ҵ���ϻ�ַ
	int front;//����ͷָ��,ָ���ͷԪ�ص���һ��λ�á�
	int rear;//����βָ�룬ָ���βԪ�ء�
	int num;//��ҵ����
}JcbSet;//ִ����ҵ˫�˶���
typedef struct OutJcb
{
	JCB* elem;//�ж���ҵ��ַ���洢�ṹΪ��̬����
	int OutNum;//�ж���ҵ����
}OutJcb;//������ҵ���Ա�
void InitJcbset(JcbSet&,int num);//num����ҵ�ύ��
void InitOutJcbset(OutJcb& OJ,int num);
int StartProcess(JcbSet&,int);
bool OutProcess(JcbSet&,OutJcb&,int);//���ж���ҵ��ִ�ж��У����ж϶��С�����ֵΪ����ִ��״̬��
bool InProcess(JcbSet&,OutJcb&);//���ж���ҵ��ʣ��ʱ����̵���ҵ���������У���ִ�ж��С�����ֵΪ����ִ��״̬
void FCFS(JcbSet&);//�����ȷ����㷨ģ��
void SJF(JcbSet&,OutJcb&,JcbSet&);//����ҵ�����㷨ģ��
void PSA(JcbSet&);//���ȼ������㷨ģ��
void HRRM(JcbSet&);//����Ӧ�����ȵ����㷨ģ��
void Visit1(JcbSet&);//������ҵ������
void Visit2(OutJcb&);
