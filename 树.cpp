#include<stdio.h>
#include<stdlib.h>
typedef struct Node          //二叉树结构定义
{
	char data;
	struct Node *lchild;
	struct Node *rchild;
}Bitree;




void CreateBiTree(Bitree *&t)    //先序遍历创建二叉树
{
	char s;
	scanf("%c",&s);
	if(s=='#')
		t=NULL;
	else
	{
		t=(Bitree *)malloc(sizeof(Node));
		t->data=s;
		CreateBiTree(t->lchild);
		CreateBiTree(t->rchild);
	}
}




void Output(Bitree *t)                 //先序遍历输出二叉树
{
	if(t!=NULL)
	{
		printf("%c ",t->data);
		Output(t->lchild);
		Output(t->rchild);
	}
}




int main()
{
	Bitree *root;
	printf("请以先序遍历依次为二叉树赋值:");
	CreateBiTree(root);
	printf("以先序遍历输出二叉树:");
	Output(root);
	printf("\n");
	return 0;
}
