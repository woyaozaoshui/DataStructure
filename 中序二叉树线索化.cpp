#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

typedef enum Tag{
	Ptr,Thread
}PointerTag;
//Ptr=0:指针，Thread=1：线索 

//二叉链表的结点结构 
typedef struct ThreadTreeNode{
	char data; 						//数据域 
	struct ThreadTreeNode* lchild;  //左孩子指针域 
	struct ThreadTreeNode* rchild;  //右孩子指针域 
	PointerTag LTag;  				//左标志位 0 1 
	PointerTag RTag;				//右标志位 0 1 
}Tnode,*Ttree;

Ttree pre;  //指向刚刚访问过的结点 

void createBiTree(Ttree& T);				 //创建二叉树并添加信息 
void inOrderThreadTree(Ttree& Thrt,Ttree T); //中序遍历线索树并调用线索化函数 
void inThreading(Ttree p);		 			 //中序线索化(递归)
void inOrderTraverse(Ttree Thrt);		     //中序遍历二叉树(非递归)，此时二叉树已经线索化 

void createBiTree(Ttree& T)
{
	char ch;
	cin>>ch;
	if(ch=='#')	T=NULL;
	else
	{
		if(!(T=(Tnode*)malloc(sizeof(Tnode))))  exit(0);
		//这里注意正确输入的顺序 
		T->data=ch;
		//所有结点的左右标志初始化置为Ptr 0 
		T->LTag=Ptr;
		T->RTag=Ptr;
		createBiTree(T->lchild); //先构造左子树 
		createBiTree(T->rchild); //再构造右子树 
	}
}

void visit(char data)
{
	cout<<data;
}

//根据线索中序遍历二叉树(非递归) 
void inOrderTraverse(Ttree Thrt)
{
	Ttree p;
	//T指向头结点，p指向根结点 
	p=Thrt->lchild;
	while(p!=Thrt)   //若p==T，则遍历完成，再次回到头结点 
	{
		while(p->LTag==Ptr)
		{
			p=p->lchild;  //直到找到根结点的最左子树的最左结点 
		}
		visit(p->data);
		cout<<p->LTag<<p->RTag<<endl;
		while(p->RTag==Thread&&p->rchild!=Thrt)
		{
			p=p->rchild;
			visit(p->data);
			cout<<p->LTag<<p->RTag<<endl;
		}
		p=p->rchild;
	}
}

void inOrderThreadTree(Ttree& Thrt,Ttree T)
{
	//创建头结点Thrt 
	if(!((Thrt)=(Ttree)malloc(sizeof(Tnode))))  exit(0);
	Thrt->LTag=Ptr;				//头结点的左标志位为0，指针 
	Thrt->RTag=Thread;			//头结点的右标志位为1，线索 
	Thrt->rchild=Thrt;  		//右指针回指本身
	if(!T)  Thrt->lchild=Thrt;  //二叉树为空时，指向为无，回指本身 
	else						 
	{
		//若二叉树存在，将头结点与二叉树进行相应的链接
		Thrt->lchild=T;			
		pre=Thrt;				//头结点为前驱 
		inThreading(T);		    //中序遍历进行中序线索化
		pre->rchild=Thrt;		//右指针回指本身 
		pre->RTag=Thread;		
		Thrt->rchild=pre; 
	}
}

void inThreading(Ttree p)
{
	//同样是左根右的递归思想 
	if(p)
	{ 
		inThreading(p->lchild);
		visit(p->data);
		if(!p->lchild)   //左指针域为空则线索化 
		{
			p->LTag=Thread;
			p->lchild=pre;
		}
		if(!pre->rchild) 
		{
			pre->RTag=Thread;
			pre->rchild=p;
		}
		pre=p;
		inThreading(p->rchild); 
	}
} 

int main()
{
	Ttree Thrt;  //头结点 
	Ttree T;  	 //根结点 
	createBiTree(T);
	inOrderThreadTree(Thrt,T);
	cout<<endl;
	inOrderTraverse(Thrt);
	return 0;
} 
 













































































































