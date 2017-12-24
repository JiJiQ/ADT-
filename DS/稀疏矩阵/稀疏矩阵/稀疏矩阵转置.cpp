#include<stdio.h>
#include"Declaration.h"
int main()
{
	TSMatrix matrix,a;
	CreaSMatrix(matrix);
	CreaSMatrix(a);
	resign(matrix);
	TransposeSMatrix(matrix,a);
	PrintSMatrix(matrix);
	PrintSMatrix(a);
}