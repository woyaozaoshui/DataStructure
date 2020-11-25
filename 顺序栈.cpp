#include<stdio.h>
#include<malloc.h>
#include <iostream>
using namespace std;

typedef int SElemType;
typedef int Status;

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
#define OK 1
#define Error 0
#define True 1
#define False 0
#define OVERFLOW -1 

typedef struct {
	SElemType *base;
	SElemType *top;
	int stacksize; 
}SqStack;

Status InitStack(SqStack &S){
	S.base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof (SElemType));
	if(!S.base){
		exit(OVERFLOW);
	}
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return OK;
} //初始化栈

Status DestoryStack(SqStack &S){
	
	free(S.base);
	S.base = NULL;
	S.top = NULL;
	S.stacksize=0;
	return OK; 
}

Status ClearStack(SqStack &S){
	if(S.base == S.top){
		return OK;
	}else{
		S.base = S.top;
		return OK;
	}
}

Status StackEmpty(SqStack &S){
	if(S.base == S.top){
		return True;
	}else{
		return False;
	}
}

int StackLength(SqStack S){
	S.top + 1;
	return OK;
}

Status GetTop(SqStack S,SElemType &e){
	if(S.top == S.base){
		return Error;
	}
	e = *(S.top - 1);
	return OK;
}

Status Push(SqStack &S, SElemType e){
	if(S.top - S.base >= S.stacksize){
		S.base = (SElemType * )realloc(S.base,(S.stacksize + STACKINCREMENT) * sizeof(SElemType));
	
	if(!S.base) exit(OVERFLOW);
	S.top = S.base +S.stacksize;
	S.stacksize += STACKINCREMENT;
	}
	*S.top++ = e;
	return OK;
}

Status Pop(SqStack &S, SElemType &e)
{
	if(S.top == S.base) return Error;
	e = *--S.top;
	return OK;
}

Status StackTraverse(SqStack *S,Status(*visit)(SElemType))
 {
     SElemType *b = S->base;//此处不能直接用base或top移动，即不能改变原栈的结构
     SElemType *t = S->top;
   while(t > b)
     visit(*b++);
   printf("\n");
   return OK;
 }
 
Status visit(SElemType c)
 {
   printf("%d ",c);
   return OK;
 }

int main()
{
	SqStack S;
	int e;
	char choice;
	int n;
	while(1){
		printf("请输入你的选择:\n");
		scanf("%c", &choice);
		getchar();//每输入一个数据，都要取走回车符，防止switch语句误判,getchar本来的作用是？？
 
		switch(choice) 
		{
		cout<<"1----初始化(创建)或重置顺序栈"<<endl;
		cout<<"2----清空顺序栈"<<endl;
		cout<<"3----顺序栈中数据的元素个数"<<endl;
		cout<<"4----判断栈是否为空并返回栈顶元素"<<endl;
		cout<<"5----求顺序栈中栈顶元素"<<endl;
		cout<<"6----判断栈是否为空"<<endl;
		cout<<"7----请输入元素，求直接后继"<<endl;
		cout<<"8----销毁顺序栈"<<endl;
			case '1':
				InitStack(S);
				printf("空栈创建成功");
				printf("start to create stack,plz write the num which u want the length");
				scanf("%d", &n);
				getchar();//move huichefu
				for(int i = 0; i<n; i++)
				{
					scanf("%d", &e);
					getchar();
					Push(S,e);
				}
				cout<<"stack is "<<endl; 
				break;
			case '2':
				ClearStack(S);
				cout<<"stack is null"<<endl;
				break;
			case '3':
				cout<<"length is "<<endl;
				StackLength(S);
				break;
			case '4':
				cout<<"stack top is "<<endl;
				if(!GetTop(S,e))
				cout<<"stack is null"<<endl;
				else
				cout<<e<<endl;
			case '5':
				cout<<"write the 'e'"<<endl;
				scanf("%d", &e);
				getchar();
				Push(S,e);
				cout<<"elem was pushed in the stack"<<endl;
				cout<<"now the stack is"<<endl;

				break;
			case '6':
				if(!Pop(S,e))
				cout<<"stack is null"<<endl;
				else
				cout<<"stack pop"<<e<<endl;
				cout<<"now the stack is"<<endl;

				break;
			case '7':
				if(!StackEmpty(S))
				cout<<"stack is not null"<<endl;
				else
				cout<<"stack is null"<<endl;
				break;
			case '8':
				DestoryStack(S);
				cout<<"stack was destroied"<<endl;
				break;
			default:
				exit(0);
				break;
		}
		
	}
}






























































  
