#define MAXSIZE 100;
typedef int ElemType;
typedef struct{
	int i,j;
	ElemType e;
}Triple;
typedef struct{
	Triple * data;
	int mu,tu,nu;
}TSMatrix;
void CreaSMatrix(TSMatrix&);
void resign(TSMatrix&);
void PrintSMatrix(TSMatrix&);
void TransposeSMatrix(TSMatrix&,TSMatrix&);