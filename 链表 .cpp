#include<iostream>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1  //不可实行的
#define OVERFLOW -2   //溢出  
using namespace std;

typedef int Status;

typedef struct LinkNode{
	int data;
	struct LinkNode *next;
}LinkNode,*LinkList;

void createNode(LinkList &head);
void destroyNode(LinkList &head);
Status numberNode(LinkList head);
Status locateElem(LinkList head,int l,int &s1);
Status location(LinkNode &N,int l,int &s2);
Status former(LinkList head,int e,int &s3);
Status later(LinkList head,int e,int &s4);
Status insert(LinkList &head,int l,int e); 
Status remove(LinkList &head,int l);
Status coutelem(LinkList &head);
Status cinelem(LinkList &head,int n);
void clear(LinkList &head);

int success=0;
int num666;

int main()
{
	int choose=0;
	LinkList head;
	head=(LinkList)malloc(sizeof(LinkNode));
	head->data=0;
	head->next=NULL;
	while(1)
	{
		cout<<"1----初始化(创建)或重置链表"<<endl;
		cout<<"2----销毁链表"<<endl;
		cout<<"3----链表中数据的元素个数"<<endl;
		cout<<"4----所指位序的元素值"<<endl;
		cout<<"5----链表已存在元素的位序"<<endl;
		cout<<"6----请输入元素，求直接前驱"<<endl;
		cout<<"7----请输入元素，求直接后继"<<endl;
		cout<<"8----在第i个位置插入元素"<<endl;
		cout<<"9----删除第i个元素"<<endl;
		cout<<"10----输出所有的链表元素"<<endl;
		cout<<"11----初始化并输入链表元素"<<endl;
		cout<<"12----清空链表"<<endl;
		cout<<"0----退出"<<endl;
		cout<<"请选择"<<endl;
		cin>>choose;
		switch(choose)
		{
			case 1:
				{
					createNode(head);
					cout<<"初始化成功"<<endl;
				}
				break;
			case 2:
				{
					if(success==1)
					{
						destroyNode(head);
						cout<<"摧毁成功"<<endl;
					}
					else
					{
						cout<<"尚未初始化"<<endl; 
					}
				}
				break;
			case 3:
				{
					int i;
					if(success==1)
					{
						numberNode(head);
						cout<<"元素个数为"<<num666<<endl;
					}
					else
					{
						cout<<"尚未初始化"<<endl; 
					}
					
				}
				break;
			case 4:
				{
					int i,j;
					if(success==1)
					{
						int s1;
						cout<<"请输入位序"<<endl;
						cin>>i;
						locateElem(head,i,s1);
						if(i<1||i>num666)
						{
							cout<<"输入错误"<<endl;
						}
						else{
						cout<<"该位置的元素为:"<<s1<<endl; 
						}
						
					}
					else
					{
						cout<<"尚未初始化"<<endl; 
					}
				}
				break;
			case 5:
				{
					int i,j,s2;
					if(success==1)
					{
						cout<<"请输入元素"<<endl;
						cin>>j;
						i=location(*head,j,s2);
						if(i==0)
						{
							cout<<"未查找到"<<endl;
						}
						else
						{
							cout<<"位序为:"<<s2<<endl; 
						} 
					}
					else{
						cout<<"尚未初始化"<<endl;
					}
				}
				break;
			case 6:
				{
					if(success==1)
					{
						LinkList p;
						p=head;
						int i,j,s3;
						bool yes;
						cout<<"请输入元素"<<endl;
						cin>>j; 
						while(p->next!=NULL)
						{
							p=p->next;
							if(p->data==j)
							{
								yes=true;
								break;
							} 
						}
						if(yes)
						{
							if(head->next->data==j)
							{
								cout<<"无前驱"<<endl; 
							}
							else
							{
								former(head,j,s3);
								cout<<"前驱为"<<s3<<endl;
							}
						}
						else
						{
							cout<<"没有该元素"<<endl;
						}
			
					}
					else
					{
						cout<<"尚未初始化"<<endl;
					}
				}
				break;
			case 7:
				{
					if(success==1)
					{
						LinkList p,q;
						p=head;
						bool yes;
						int i,j,s4,asd;
						cout<<"请输入元素"<<endl;
						cin>>j; 
						asd=later(head,j,s4);
						if(asd==0)
						{
							cout<<"出错"<<endl; 
						}
						else
						{
							cout<<"后继为："<<s4<<endl;
						}	
				}
				else{
					cout<<"尚未初始化"<<endl;
				}
			}
				break;
			case 8:
				{
					if(success==1)
					{
						int i,j,k;
						cout<<"请依次输入要插入的位置和元素"<<endl;
						cin>>j;
						cin>>k; 
						i=insert(head,j,k);
						if(i==-1)
						{
							cout<<"输入位置有误"<<endl;
						}
						if(i==1)
						{
							cout<<"插入成功"<<endl;
						} 
					} 
					
					else
					{
						cout<<"尚未初始化"<<endl;
					}
				} 
				break;
			case 9:
				{
					if(success==1)
					{
						int i,j,k;
						cout<<"请输入要删除的位序"<<endl;
						cin>>j;
						i=remove(head,j);
						if(i==-1)
						{
							cout<<"删除位置有误"<<endl;
						}
						else if(i==1)
						{
							cout<<"删除成功"<<endl;
						}
					} 
					else
					{
						cout<<"尚未初始化"<<endl;
					}
				
				}
				break;
			case 10:
			{
				if(success==1)
				{
					int ak=coutelem(head);
					if(ak==0)
					{
						cout<<"空表"<<endl;
					}
				}
				else
				{
					system("CLS");
					cout<<"尚未初始化"<<endl;
					
				}
			 } 
			 break;
			case 11:
				{
					int i,j,k;
					cout<<"输入元素个数"<<endl;
					cin>>j;
					system("CLS");
					cout<<"请输入"<<endl;
					int akk=cinelem(head,j);
					if(akk==1)
					{
						cout<<"输入成功"<<endl;
					}
					success=1;
				}
				break;
			case 12:
				{
					if(success==1)
					{
						clear(head);
						cout<<"清空成功"<<endl;
					}
					else
					{
						cout<<"尚未初始化"<<endl;
					} 
				}
				break;
			case 0:
				{
					return 0;
				}
			default:
				{
					cout<<"输入错误"<<endl;
					break;
				}
		}
	}
}

//1初始化(创建)或重置链表
void createNode(LinkList &head)
{
	LinkList p;
	p=new LinkNode;
	p->data=0;
	p->next=NULL;
	head=p;
	success=1;
	system("CLS");
}
//2销毁链表
void destroyNode(LinkList &head)
{ 
	LinkList p=head->next;
	while(p!=NULL){
		head->next=p->next;
		free(p);
		p=head->next;
	}
	free(head);
	head=NULL;
		success=0;
		system("CLS");
}
//3链表中数据的元素个数
Status numberNode(LinkList head)
{
		system("CLS");
		return OK;
}
//4所指位序的元素值
Status locateElem(LinkList head,int l,int &s1)
{
		LinkList p;
		p=head;
		if(l<1&&l>num666)
		{
			return ERROR;
		}
		else
		{
			int num=0;
			while(p->next!=NULL)
			{
				p=p->next;
				num++;
				if(num==l)
				{
					s1=p->data;
					system("CLS");
					return OK;
				}
			}
		}
}
//5链表已存在元素的位序
Status location(LinkNode &N,int l,int &s2)
{
		LinkList p;
		p=&N;
		int num=0;
		while(p->next!=NULL)
		{
			p=p->next;
			num++;
			if(p->data==l)
			{
				s2=num;
				system("CLS");
				return TRUE;
			}
		}
		system("CLS");
		return FALSE;
}
//6请输入元素，求直接前驱
Status former(LinkList head,int e,int &s3)
{
	
		LinkList p,q;
		p=head;
		while(p->next!=NULL)
		{
			q=p;
			p=p->next;
			if(p->data==e)
			{
				s3=q->data;
				system("CLS");
				return OK;
			}
		}
		system("CLS");
		return ERROR;
} 
//7请输入元素，求直接后继
Status later(LinkList head,int e,int &s4)
{
		LinkList p,q;
		p=head;
		while(p->next->next!=NULL)
		{
			p=p->next;
			q=p->next;
			if(p->data==e)
			{
				s4=q->data;
				return OK;
			}
		}
		return ERROR;
}
//8在第i个位置插入元素
Status insert(LinkList &head,int l,int e)
{
		LinkList p,q;
		int location=0;
		p=head;
		q=new LinkNode;
		q->data=e;
		if(l<1||l>num666+1)
		{
			system("CLS");
			return INFEASIBLE;
		}
		else
		{
			while(p->next!=NULL)
			{
				location++;
				if(location==l)
				{
					break;
				}
				p=p->next;
			}
			q->next=p->next;
			p->next=q;
			num666++;
			system("CLS");
			return OK;
		}
}
//9删除第i个元素
Status remove(LinkList &head,int l)
{
		LinkList p,q;
		q=head;
		p=q->next; 
		int location=1;
		if(l<1||l>num666)
		{
			return INFEASIBLE;
		}
		else
		{
			while(p!=NULL)
			{
				if(l==location)
				{
					break;
				}
				
				q=p;
				p=p->next;
				location++;
			}	
			q->next=p->next;
			free(p);
			num666--; 
			system("CLS");
			return OK;
		}
}
//10输出所有的链表元素
Status coutelem(LinkList &head)
{
		LinkList p;
		p=head;
		int num555=0;
		if(p->next==NULL)
		{
			system("CLS");
			return FALSE;
		}
		else
		{
		system("CLS");
		for(int num555=0;num555<num666;num555++)
		{
			p=p->next;
			cout<<p->data<<"  ";
		}
		}
		cout<<endl;
		return OK;
}
//11初始化并输入链表元素
Status cinelem(LinkList &head,int n)
{/*代码逻辑错误 
	success=1;
	LinkList p,q;
	p=(LinkList)malloc(sizeof(LinkNode));
	p->data=0;
	p->next=NULL;
	head=p;
	num666=0;
	while(num666!=n)
	{
		q=(LinkList)malloc(sizeof(LinkNode));
		cin>>q->data;
		p->next=q;
		p=q;
		num666++;
	}
	return OK;*/
	success=1;
	LinkList p,q;
	q=head;
	num666=0;
	for(num666=0;num666<n;num666++){
		p=(LinkList)malloc(sizeof(LinkNode));
		if(p==NULL){
			return ERROR;
		}
		cin>>p->data;
		p->next=q->next;
		q->next=p;
		q=p;
	}
	return OK;
}
//12清空链表
void clear(LinkList &head)
{
	LinkList p=head->next;
	while(p!=NULL){
		head->next=p->next;
		free(p);
		p=head->next;
	}
	system("CLS");
}

