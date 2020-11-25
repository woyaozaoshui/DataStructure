#include <iostream>
#include <stdlib.h>
using namespace std;
#define ERROR 0  
#define OK 1
#define INIT_SIZE 100
typedef int ElemType;
typedef int Status;
typedef struct queue
{
	ElemType *base;//数组首地址
	int front,rear;//一个头下标，一个尾下标
}Queue;


Status InitQueue(Queue &Q)
{
	Q.base = (ElemType *)malloc(INIT_SIZE*sizeof(ElemType));
	if (!Q.base)
	{
		cout<<"内存分配失败"<<endl;
		return ERROR;
	}
	Q.rear = 0;
	Q.front = 0;
	return OK;
}
 
Status IsEmpty(Queue &Q)
{
	if (Q.front == Q.rear)
	{
		cout<<"该队列为空"<<endl;
		return OK;
	}
	cout<<"该队列不为空"<<endl;
	return 0;
}
 
Status IsFull(Queue &Q)
{
	if ((Q.rear+1)%INIT_SIZE==Q.front)//此处判断队列是否满不能用isfull函数判断
	{
		cout<<"该队列已满"<<endl;
		return OK;
	}
	cout<<"该队列未满"<<endl;
	return 0;
}
 
Status EnQueue(Queue &Q,ElemType value)
{
	if ((Q.rear+1)%INIT_SIZE == Q.front)
	{
		cout<<"该队列已满，不能再进入数据"<<endl;
		return ERROR;
	}
	Q.base[Q.rear] = value;
	cout<<Q.base[Q.front]<<endl;
	Q.rear = (Q.rear+1)%INIT_SIZE;
	return OK;
}
 
Status DeQueue(Queue &Q,ElemType &data)
{
	if (Q.front == Q.rear)
	{
		cout<<"该队列为空！"<<endl;
		return ERROR;
	}
	data = Q.base[Q.front];
	cout<<"出队的值为："<<data<<endl;
	Q.front = (Q.front+1)%INIT_SIZE;
	return OK;
}
 
Status GetHead(Queue &Q,ElemType &head)
{
	if (Q.front == Q.rear)
	{
		cout<<"队列为空"<<endl;
		return ERROR;
	}
	head = Q.base[Q.front];
	return OK;
}

int main()
{
	int choice;
	ElemType value;
	ElemType head,data;
	Queue Q;
	Q.base = NULL;
	while (1)
	{
		cout<<"顺序循环队列的基本操作"<<endl;		
		cout<<"1.初始化队列"<<endl;
		cout<<"2.判断队列是否为空"<<endl;
		cout<<"3.判断队列是否满"<<endl;
		cout<<"4.元素入队"<<endl;
		cout<<"5.元素出队"<<endl;
		cout<<"6.获取头的值"<<endl;
		cout<<"0.退出程序"<<endl;
		cout<<"输入你的选择："<<endl;
		cin>>choice;
		switch(choice)
		{
		case 1:
			if (InitQueue(Q))
			{
				cout<<"初始化成功"<<endl;
			}
			break;
		case 2:
			IsEmpty(Q);
			break;
		case 3:
			IsFull(Q);
			break;
		case 4:
			cout<<"	输入你要入队的值:"<<endl;
			cin>>value;
			EnQueue(Q,value);
			break;
		case 5:
			cout<<"	正在执行。。。。。"<<endl;
			DeQueue(Q,data);
			break;
		case 6:
			GetHead(Q,head);
			cout<<"头的值为"<<head<<endl;
			break;
		case 0:
			exit(0);
		default:
			exit(0);
		}
	}
	system("pause");
}
