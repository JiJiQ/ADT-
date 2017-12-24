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
void LocateElem(pList,ElemType);//添加数据元素关系判定函数comepare();
void PriorElem(pList,ElemType,ElemType*);
void NextElem(pList,ElemType,ElemType*);
void ListInsert(pList,int,ElemType);
void ListDelete(pList,int,ElemType);
void ListTraverse(pList);//形参添加函数visit的调用
void MergeList(pList,pList,pList);//两个有序线性表合并为一个有序线性表
void Visit(pList);
