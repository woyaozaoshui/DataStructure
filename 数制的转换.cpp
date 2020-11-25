#include<stdio.h>
#include<malloc.h>
typedef int ElemType;
 
typedef struct //声明顺序栈
{ 
	ElemType data[100];
	int top;
}SqStack;
 
int main()
{ 
	void InitStack(SqStack *&s); //初始化栈
	void Push(SqStack *&s,int n,int r); //进栈
	void Pop(SqStack *&s); //出栈
	int n,r;
	SqStack *s;
	printf("请输入一个10进制数字\n");
	scanf("%d",&n);
	printf("请输入所要转换的进制\n");
	scanf("%d",&r);
	InitStack(s);
	if(n==0)
		printf("%d的%d进制为0",n,r);
	else
	{
		Push(s,n,r);
		Pop(s);
	}
}
 
void InitStack(SqStack *&s) //初始化栈
{
	s=(SqStack *)malloc(sizeof(SqStack));
	s->top=-1;
}
 
void Push(SqStack *&s,int n,int r) //进栈
{ 
	while(n)
	{
		s->top++;
		s->data[s->top]=n%r;
		n=n/r;
	}
}
 
void Pop(SqStack *&s) //出栈
{ 
	ElemType e;
	printf("转换所得数为：");
	while(s->top!=-1)
	{ 
		e=s->data[s->top];
		s->top--;
		if(e<10)
			printf("%d",e);
		else
			printf("%c",e+55);
	}
	printf("\n");
} 
