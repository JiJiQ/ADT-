#include"Declaration.h"
#include<stdio.h>
bool Index(char* arr,int length)
{
	//�任��ƥ��������ŵļ����Ըߵ�
	int i = 0;
	Stack stack;
	char A;
	InitStack(stack,100);
	for(i = 0;i < length;i++)
	{
		printf("��ʱ��֤Ԫ��Ϊ��%c\n",arr[i]);
		printf("ջ��Ԫ��Ϊ��%c\n",stack.elem[stack.top-1]);
		switch(arr[i]){
			case'(':
				PushS(stack,arr[i]);
				break;
			case'[':
				PushS(stack,arr[i]);
				break;
			case']':
				if(stack.elem[stack.top-1] == '['){
					PopS(stack,A);
				}else{
					return false;
				}
				break;//���κ�����¶�Ҫдbreak����������������
			case')':
				if(stack.elem[stack.top-1] == '('){
					PopS(stack,A);
				}else{
					return false;
				}
				break;//���κ�����¶�Ҫдbreak����������������
		}
		
	}
	if(EmptyS(stack))
	{
		return true;
	}

}
