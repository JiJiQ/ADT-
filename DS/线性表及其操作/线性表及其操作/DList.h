typedef int ElemType;
typedef struct List
{
	ElemType* elem;
	int length;
	int ListSize;
}List,*pList;
void InitList(pList,int);
void Destroy(pList);
void ClearList(pList);
void ListEmpty(pList);
int GetLength(pList);
void (*visit)(ElemType);
ElemType* GetElem(pList,int ,ElemType*);
void LocateElem(pList,ElemType);//�������Ԫ�ع�ϵ�ж�����comepare();
void PriorElem(pList,ElemType,ElemType*);
void NextElem(pList,ElemType,ElemType*);
void ListInsert(pList,int,ElemType);
void ListDelete(pList,int,ElemType);
void ListTraverse(pList);//�β���Ӻ���visit�ĵ���
void MergeList(pList,pList,pList);//�����������Ա�ϲ�Ϊһ���������Ա�
void Visit(pList);
