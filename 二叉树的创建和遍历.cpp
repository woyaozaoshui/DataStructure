#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#define True 1;
#define False 0;
#define STACK_INIT_SISE 100
#define STACKINCREMENT 10
using namespace std; 

typedef char TElemType;
typedef int Status;

typedef struct BiTNode{
	TElemType data;
	struct BiTNode *lchild,*rchild;	
}BiTNode,*BiTree;

typedef BiTree ElemType;

typedef struct QNode{
	ElemType data;
	struct QNode *next;
}QNode,*QueuePtr; 

typedef struct{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

typedef struct {
	ElemType *base;
	ElemType *top;
	int stacksize;
}SqStack;

//关于栈的基本操作

void Initstack(SqStack &S){//初始化栈为空栈 
	S.base = (ElemType *)malloc(STACK_INIT_SISE*sizeof(ElemType));//给栈底分配内存空间 
	S.top = S.base;
	S.stacksize = STACK_INIT_SISE; 
} 

void Destorystack(SqStack &S){//摧毁栈 
	free(S.base);
	S.base = NULL;
	S.stacksize = 0;
} 

int ClearStack(SqStack &S){//清空栈 
	S.stacksize = 0;
	if(S.stacksize == 0);
	return 1;
	return 0;
}

int StackEmpty(SqStack S){//判断栈是否为空 
	if(S.top == S.base)
	return 1;
	return 0;
}

int StackLength(SqStack S){//返回栈的长度
	return (S.top-S.base);
}

void Push(SqStack &S,ElemType e){
	if(S.top - S.base >= S.stacksize){
	S.base = (ElemType *)realloc(S.base,(S.stacksize + STACKINCREMENT)*sizeof(ElemType));
//	if(!S.base) exit(OVERFLOW)； 
	S.top = S.stacksize + S.base;//重新定位栈顶元素的位置
	S.stacksize += STACKINCREMENT;
	}
	*S.top++ = e;//把值传给栈顶之后，指针位置加一 
} 

void Pop(SqStack &S,ElemType &e){//删除栈顶元素，并返回其值
	S.top--;
	e=*S.top;
}

//关于队列的基本操作

void InitQueue(LinkQueue &Q){
	Q.front=Q.rear=(QueuePtr)malloc(sizeof(QNode));
//	if(!Q.front)exit(OVERFLOW);
	Q.front->next = NULL;
}

void DestroyQueue(LinkQueue &Q){//摧毁队列 
	while(Q.front){
		Q.rear = Q.front->next;
		free(Q.front);
		Q.front = Q.rear;
	}
}

int ClearQueue(LinkQueue &Q){//清理队列 
	QueuePtr p = Q.front->next;
	while(p){
		Q.front->next = p->next;
		free(p);
		p = Q.front->next;
	}
	Q.front->data = 0;
	Q.front->next = NULL;
	if(p==NULL)
	return 1;
	return 0;
}

int QueueEmpty(LinkQueue Q){//判断队列是否为空
	if(Q.front==Q.rear)
	return 1;
	return 0;
}

int QueueLength(LinkQueue Q){//返回队列中元素个数
	int n=0;
	while(Q.front!=Q.rear){
		Q.front=Q.front->next;
		n++;
	}
	return n;
}

int GetHead(LinkQueue Q,ElemType &e){//返回队列对头元素
	if(Q.rear==Q.front)
	return 0;
	QueuePtr p=Q.front->next;
	e=p->data;
	return 1;
}

void EnQueue(LinkQueue &Q,ElemType e){//插入队尾元素 
	QueuePtr p;
	p = (QueuePtr)malloc(sizeof(QNode));
	
	p->data = e;
	p->next = NULL;
	Q.rear->next = p;	//修改尾节点的指针 
	Q.rear = p;  		//移动队尾的指针 
}

void DeQueue(LinkQueue &Q,ElemType &e){//插入队头元素 
	QueuePtr p;
	p = Q.front->next;
	e = p->data;
	Q.front->next=p->next;
	if(p==Q.rear)
	Q.rear=Q.front;
	free(p);	
}

//重点来了树的操作

void CreateBiTree(BiTree &T){
	char n;
	cin>>n;
	if(n == '#'){
		T = NULL;
	}else{
		T=(BiTree)malloc(sizeof(BiTNode));
		T->data = n;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
} 

Status PreOrderTraverse(BiTree T)//先序递归 
{
	if(T==NULL){
		return False;
	}
	else{
		cout<<T->data<<endl;
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);
	}
}

Status InOrderTraverse(BiTree T)//中序递归 
{
 
    if(T==NULL){
    	return False;
	}else{
        InOrderTraverse(T->lchild);
        cout<<T->data<<endl;
        InOrderTraverse(T->rchild);
    }
}

Status PostOrderTraverse(BiTree T)//后续递归
{
 
    if(T==NULL){
    	return False;
	}else{
        InOrderTraverse(T->lchild);
        InOrderTraverse(T->rchild);
        cout<<T->data<<endl;
    }
}


void PreOrderTraverse_Nonrecursion(BiTree T){//前序非递归遍历 
	SqStack S;
	Initstack(S);
	BiTree p=T;
    while(p || !StackEmpty(S)){
        if(p){
            Push(S, p) ;
			cout<<p->data<<endl;
            p = p->lchild ;
        }else{
            Pop(S, p) ;
            p = p->rchild ;
        }
    }
}

void InOrderTraverse_Nonrecursion(BiTree T){//中序非递归遍历 
	SqStack S;
	Initstack(S);
	BiTree p=T;
	while( p || !StackEmpty(S)){
		if(p){
			Push(S,p);
			p=p->lchild;
		}else{
			Pop(S,p);
			cout<<p->data<<endl;
			p=p->rchild;
		}
	}
}

//void PostOrderTraverse_Nonrecursion//后序非递归遍历 

int TreeDeep(BiTree T){//深度 
	int deep=0;
	if(T){
		int ldeep=TreeDeep(T->lchild);
		int rdeep=TreeDeep(T->rchild);
		deep=ldeep>=rdeep?ldeep+1:rdeep+1;
	}
	return deep;
} 

void LevelOrderTraverse(BiTree T){//层序遍历 
	BiTree p=T; 
	LinkQueue Q;
	InitQueue(Q);
	EnQueue(Q,p);
	while(QueueEmpty(Q)!=1){//循环条件：Q不为空 
		DeQueue(Q,p);//弹出对头元素 存放在p中 
		cout<<p->data<<endl;; 
		if(p->lchild!=NULL)
		EnQueue(Q,p->lchild);
		if(p->rchild!=NULL)
		EnQueue(Q,p->rchild);
	}
}

int main()
{
	while(1)
	{
	BiTree T;
	cout<<endl;
	cout<<"***********************"<<endl;
	cout<<"1.创建二叉树"<<endl;
	cout<<"2.先序遍历二叉树（递归）"<<endl;
	cout<<"3.中序遍历二叉树（递归）"<<endl;	 
	cout<<"4.后序遍历二叉树（递归）"<<endl;
	cout<<"5.先序遍历二叉树（非递归）"<<endl;
	cout<<"6.中序遍历二叉树（非递归）"<<endl;
	cout<<"7.层序遍历二叉树"<<endl;
	cout<<"8.求二叉树的深度"<<endl;
	cout<<"0.退出"<<endl;
	cout<<"***********************"<<endl;
	cout<<"请选择"<<endl;
	int choose=0;
	BiTNode *Thre;
	cin>>choose;
	switch(choose){
		case 1:
			{
				cout<<"请输入结点的数值域(一个字符)："<<endl;
				cout<<"当输入#时表示这个结点不存在"<<endl;
				CreateBiTree(T);
				cout<<"创建成功"<<endl;
				break;
			}
		case 2: 
		{
			PreOrderTraverse(T);
			break; 
		}
		case 3:
		{
			InOrderTraverse(T);
			break;	
		} 
		case 4:{				
			PostOrderTraverse(T);
			break;
		}
		case 5:{
			PreOrderTraverse_Nonrecursion(T);
			break;
		}
		case 6:{
			InOrderTraverse_Nonrecursion(T);
			break; 
		}
		case 7:{
			LevelOrderTraverse(T);
			break;
		}
		case 8:{
			cout<<TreeDeep(T)<<endl;;
			break;
		}		
		case 0:{				 
			break;
		}
		default:{
			cout<<"请输入有效的操作！"<<endl;
			break;
		}
	}
	}return 0;	
}
 













































































































