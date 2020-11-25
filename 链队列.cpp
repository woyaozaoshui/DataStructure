#include<iostream>
#include<malloc.h>
#include<stdlib.h>
#include<math.h>
using namespace std;

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int QElemType;

typedef struct QNode {
	QElemType data;
	struct QNode *next;
} QNode,*QueuePtr;

typedef struct {
	QueuePtr front,rear;
} LinkQueue;

//初始化队列
int InitQueue(LinkQueue &Q) {
	Q.front=Q.rear=(QueuePtr)malloc(sizeof(QNode));
	if(!Q.front) {
		cout<<"初始化失败！"<<endl;
		return ERROR;
	}
	Q.front->next=NULL;
	return OK;
}

//销毁队列
int DestroyQueue(LinkQueue &Q) {
	while(Q.front) {
		Q.rear=Q.front->next;
		free(Q.front);
		Q.front=Q.rear;
	}
	return OK;
}

//清空队列
int ClearQueue(LinkQueue &Q) {
	QueuePtr p,q;
	Q.rear=Q.front;
	p=Q.front->next;
	Q.front->next=NULL;
	while(p) {
		q=p;
		p=p->next;
		free(q);
	}
	return OK;
}

//判断队列是否为空
int QueueEmpty(LinkQueue Q) {
	if(Q.front==Q.rear) {
		cout<<"队列为空！"<<endl;
		return TRUE;
	} else {
		cout<<"队列不为空！"<<endl;
		return FALSE;
	}
}

//返回队列中元素个数
int QueueLength(LinkQueue Q) {
	QueuePtr p;
	int i=0;
	p=Q.front;
	while(p!=Q.rear) {
		i++;
		p=p->next;
	}
	cout<<"队列中元素个数为："<<i<<endl;
	return OK;
}

//返回队列队头元素
int QueueFront(LinkQueue Q) {
	QueuePtr p;
	if(Q.front==Q.rear) {
		cout<<"该队列是空的！"<<endl;
		return ERROR;
	}
	p=Q.front->next;
	cout<<"队列头元素为："<<p->data<<endl;
	return OK;
}

//插入新的队尾元素
int InsertQueue(LinkQueue &Q,QElemType e) {
	QueuePtr s=(QueuePtr)malloc(sizeof(QNode));
	if(!s) {
		cout<<"插入失败！"<<endl;
		return ERROR;
	}
	s->data=e;
	s->next=NULL;
	Q.rear->next=s;
	Q.rear=s;
	return OK;
}

//删除队头元素
int DeQueue(LinkQueue &Q) {
	QueuePtr p;
	if(Q.front==Q.rear) {
		cout<<"该队列是空的，删除失败！"<<endl;
		return ERROR;
	}
	p=Q.front->next;
	Q.front->next=p->next;
	if(Q.rear==p) Q.rear=Q.front;
	free(p);
	cout<<"删除成功！"<<endl;
	return OK;
}

//初始化并创建队列
int PutIn(LinkQueue &Q) {
	InitQueue(Q);
	QElemType e;
	while((cin>>e)!=0) {
		if(e<0) return ERROR;
		InsertQueue(Q,e);
	}
	return OK;
}

//输出队列元素
int QueueTraverse(LinkQueue Q) {
	QueuePtr p;
	p=Q.front->next;
	while(p) {
		cout<<p->data<<" ";
		p=p->next;
	}
	return OK;
}

int main() {
	cout<<"可执行操作有：" <<endl;
	cout<<"    1.初始化队列            "<<endl;
	cout<<"    2.销毁队列              "<<endl;
	cout<<"    3.清空队列              "<<endl;
	cout<<"    4.判断队列是否为空      "<<endl;
	cout<<"    5.返回队列中元素个数    "<<endl;
	cout<<"    6.返回队列队头元素      "<<endl;
	cout<<"    7.插入新的队尾元素      "<<endl;
	cout<<"    8.删除队头元素          "<<endl;
	cout<<"    9.初始化并创建队列      "<<endl;
	cout<<"   10.输出队列元素          "<<endl;
	cout<<"   11.退出                  "<<endl;
	cout<<endl<<"请输入你的选择：";
	LinkQueue q;
	q.front=NULL;
	QElemType e;
	int num;
	while( (cin>>num) != 0 ) {
		switch(num) {
			case 1:
				if(q.front) {
					cout<<"已初始化队列！"<<endl;
					cout<<endl<<"请输入你的选择：";
					break;
				} else {
					InitQueue(q);
					cout<<"初始化成功！"<<endl;
					cout<<endl<<"请输入你的选择：";
					break;
				}
			case 2:
				if(q.front == NULL) {
					cout<<"链队列不存在！"<<endl;
					cout<<endl<<"请输入你的选择：";
					break;
				} else {
					DestroyQueue(q);
					cout<<"销毁成功！"<<endl;
					cout<<endl<<"请输入你的选择：";
					break;
				}
			case 3:
				if(q.front == NULL) {
					cout<<"链队列不存在！"<<endl;
					cout<<endl<<"请输入你的选择：";
					break;
				} else {
					ClearQueue(q);
					cout<<"清空成功！"<<endl;
					cout<<endl<<"请输入你的选择：";
					break;
				}
			case 4:
				if(q.front == NULL) {
					cout<<"链队列不存在！"<<endl;
					cout<<endl<<"请输入你的选择：";
					break;
				} else {
					QueueEmpty(q);
					cout<<endl<<"请输入你的选择：";
					break;
				}
			case 5:
				if(q.front == NULL) {
					cout<<"链队列不存在！"<<endl;
					cout<<endl<<"请输入你的选择：";
					break;
				} else {
					QueueLength(q);
					cout<<endl<<"请输入你的选择：";
					break;
				}
			case 6:
				if(q.front == NULL) {
					cout<<"链队列不存在！"<<endl;
					cout<<endl<<"请输入你的选择：";
					break;
				} else {
					QueueFront(q);
					cout<<endl<<"请输入你的选择：";
					break;
				}
			case 7:
				if(q.front == NULL) {
					cout<<"链队列不存在！"<<endl;
					cout<<endl<<"请输入你的选择：";
					break;
				} else {
					cout<<"请输入插入元素：";
					cin>>e;
					int a=InsertQueue(q,e);
					if(a==1) cout<<"插入成功！"<<endl;
					cout<<endl<<"请输入你的选择：";
					break;
				}
			case 8:
				if(q.front == NULL) {
					cout<<"链队列不存在！"<<endl;
					cout<<endl<<"请输入你的选择：";
					break;
				} else {
					DeQueue(q);
					cout<<endl<<"请输入你的选择：";
					break;
				}
			case 9:
					cout<<"请输入队列元素并以一个负数结尾！"<<endl;
					PutIn(q);
					cout<<endl<<"请输入你的选择：";
					break;
			case 10:
				if(q.front == NULL) {
					cout<<"链队列不存在！"<<endl;
					cout<<endl<<"请输入你的选择：";
					break;
				} else {
					if(q.front==q.rear) {
						cout<<"该队列中没有元素！"<<endl;
						cout<<endl<<"请输入你的选择：";
						break;
					} else {
						cout<<"队列元素为：";
						QueueTraverse(q);
						cout<<endl;
						cout<<endl<<"请输入你的选择：";
						break;
					}
				}
			case 11:
				return 0;
			default:
				cout<<"该数据无效，请重新输入：";
				break;
		}
	}
	return 0;
}
