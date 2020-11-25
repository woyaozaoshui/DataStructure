#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10 //每次增加栈单元
using namespace std;

typedef int ElemType;
typedef int Status;

int success = 0;

 typedef struct{
 	ElemType *base;
 	ElemType *top;
 	int stacksize;
 }SqStack;
 
 Status InitStack(SqStack &S){
 	S.base=(ElemType*)malloc(STACK_INIT_SIZE*sizeof(ElemType));
 	S.top=S.base;
 	S.stacksize=STACK_INIT_SIZE;
 	success=1;
 	return OK;
 } 
 
 Status DestroyStack(SqStack &S){
 	S.top=NULL;
 	S.stacksize = 0;
 	free(S.base);
 	success=0;
 	return OK;
 }
 
 Status ClearStack(SqStack &S){
 	S.top=S.base;
 	return OK;
 }
 
 Status IfEmpty(SqStack S){
 	if(S.top==S.base)
 	{
 		return TRUE; 
	 }	 else	 {
	 	return FALSE;
	 }
 }
 
 Status StackLength(SqStack S){
 		if(S.top==S.base)
 		{return FALSE;
		 } else	 {
	 	return (S.top-S.base);
		 }
 }
 
 Status GetTop(SqStack &S,ElemType &e)
 {
 	if(S.top==S.base)
 	{
 		return ERROR;
	 }	 else	 {
	 	e=*(S.top-1);
	 	return OK;
	 }
 }
 
 Status Push(SqStack &S,ElemType &k)
 {
 	if (S.top - S.base >= STACK_INIT_SIZE)
    {
        S.base = (ElemType *)realloc(S.base, (S.stacksize + STACKINCREMENT) * sizeof(ElemType));
        if (!S.base)
        {
            return false;
        }
        S.top = S.base + STACK_INIT_SIZE;//栈底地址可能改变，重新定位栈顶元素
        S.stacksize = S.stacksize + STACKINCREMENT;
    }
    *S.top = k;
    S.top++;
    return OK;
 }
 
 Status Pop(SqStack &S, ElemType &l)
{
    if (S.top == S.base)
        return ERROR;
    else  {
        S.top--;
        l = *S.top;//此元素并没真正删除
        return l;
    }
}

Status coutStack(SqStack S)
{
    if (S.top == S.base)
       return ERROR;
       
    ElemType *p;
    p = S.top;
    while (p > S.base)
    {
        p--;
        cout<<*p<<endl;
    }
    return OK;
}

Status cinStack(SqStack &S,int &num)
{
	S.base=(ElemType*)malloc(STACK_INIT_SIZE*sizeof(ElemType));
 	S.top=S.base;
 	S.stacksize=STACK_INIT_SIZE;
 	success=1;
	while(S.top-S.base<num)
	{
		cin>>*S.top;
		S.top++;
	}
}

int main()
{
	while(1){

	cout<<"1.初始化为空栈"<<endl; 
	cout<<"2.销毁栈"<<endl;
	cout<<"3.置空栈"<<endl;
	cout<<"4.判断栈是否为空"<<endl;
	cout<<"5.返回栈长度"<<endl;
	cout<<"6.求栈顶元素"<<endl;
	cout<<"7.向栈顶插入元素"<<endl;
	cout<<"8.删除栈顶元素，并返回其值"<<endl;
	cout<<"9.输出栈内元素"<<endl;
	cout<<"10.创建栈并输入栈元素"<<endl;
	cout<<"11.退出"<<endl; 
	cout<<"**********************************"<<endl; 
	SqStack begin;
	int choose=0;
	cout<<"请选择"<<endl;
	cin>>choose;
	switch(choose)
	{
		case 1:
			{
				InitStack(begin);
				cout<<"初始化成功"<<endl;
				break;
			}
		case 2:
			{
				if(success==1)
				{
					DestroyStack(begin);
					cout<<"销毁成功"<<endl;
				}else{
					cout<<"尚未初始化"<<endl;
				}
			break;
			}
		case 3:
			{
				if(success==1)
				{
					ClearStack(begin);
					cout<<"置空成功"<<endl;
				}else{
					cout<<"尚未初始化"<<endl;
				}
			break;
			}
		case 4:
			{
				if(success==1)
				{
					int status;
					status=IfEmpty(begin);
					if(status==0)
					{
						cout<<"不为空"<<endl;
					}else{
						cout<<"为空"<<endl;
					}
				}else{
					cout<<"尚未初始化"<<endl;
				}
			break;
			}
		case 5:
			{
					if(success==1)
			{
				int status1=StackLength(begin);
				cout<<"栈的长度为:"<<status1<<endl;
			}else{
				cout<<"尚未初始化"<<endl;
			}
			break;
			}
		
		
		case 6:
			if(success==1)
			{
				int e,status2;
				status2=GetTop(begin,e);
				if(status2==0)
				{
					cout<<"空栈"<<endl;
				}else{
					cout<<"栈顶元素:"<<e<<endl;
				}
			}else{
				cout<<"尚未初始化"<<endl;
			}
			break;
		case 7:
			if(success==1)
			{
				int k;
				cout<<"请输入要插入的元素"<<endl;
				cin>>k;
				Push(begin,k);
				cout<<"插入成功"<<endl;
			}else{
				cout<<"尚未初始化"<<endl;
			}
			break;
		case 8:
			{
			if(success==1)
			{
				int l,status3;
				status3=Pop(begin,l);
				if(status3==0)
				{
					cout<<"空栈"<<endl;
				}else{
					cout<<"删除成功，删除值为："<<l<<endl;
				}
			}else{
				cout<<"尚未初始化"<<endl;
			}
			break;
			}
		case 9:
			{
				if(success==1)
				{
					int status4 = coutStack(begin);
					if(status4==0)
					{
						cout<<"空栈"<<endl;
					}else{
						cout<<"输出成功"<<endl; 
					}
				}else{
					cout<<"尚未初始化"<<endl; 
				}
				break;
			}
		case 10:
			{
				int num1;
				cout<<"请输入要输入的元素个数"<<endl;
				cin>>num1;
				cout<<"请依次输入"<<endl;
				cinStack(begin,num1);
				cout<<"输入成功"<<endl;
				break;
			}
		case 11:
			{
				return 0;
				break;
			}
		default:
			{
				cout<<"输入有误"<<endl;
			}
	}
		}
} 
