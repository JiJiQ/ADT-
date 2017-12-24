#include"Declaration.h"
#include<stdio.h>
bool Index(char* arr,int length)
{
	//变换待匹配的左括号的急迫性高低
	int i = 0;
	Stack stack;
	char A;
	InitStack(stack,100);
	for(i = 0;i < length;i++)
	{
		printf("此时验证元素为：%c\n",arr[i]);
		printf("栈顶元素为：%c\n",stack.elem[stack.top-1]);
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
				break;//在任何情况下都要写break！！！！！！！！
			case')':
				if(stack.elem[stack.top-1] == '('){
					PopS(stack,A);
				}else{
					return false;
				}
				break;//在任何情况下都要写break！！！！！！！！
		}
		
	}
	if(EmptyS(stack))
	{
		return true;
	}

}
