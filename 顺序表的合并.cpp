#include<iostream>
#include <cstdlib>
using namespace std;

typedef struct											//定义顺序表
{
	int *elem;
	int length;
}SqList;

void InitList_Sq(SqList &L,int n)						//创建顺序表
{
	L.elem= new int [n];
	if(!L.elem)
		exit(0);
	L.length=0;
}

void input(SqList &L,int n)						//依次往顺序表L里输入数据
{
	int i;
	cout<<"请非递减的输入该表的元素";
	for(i=0;i<n;i++){
		cin>>L.elem[i];
		L.length++;
	} 
}

void output(SqList L)									//依次输出顺序表里的每个元素
{
	int i;
	for(i=0;i<L.length;i++){
		if(i)
		cout<<",";
		cout<<L.elem[i];
	}
}

void MergeList_Sq(SqList LA,SqList LB,SqList &LC)		//算法 顺序有序表的合并
{
	//已知顺序有序表LA和LB的元素按值非递减排列
	//归并LA和LB得到新的顺序有序表LC，LC的元素也按值非递减排列
	int *pa,*pb,*pc,*pa_last,*pb_last;
	pa=LA.elem;pb=LB.elem;								//指针pa和pb的初值分别指向两个表的第一次元素
	LC.length=LA.length+LB.length;						//新表长度为待合并两表的长度之和
	LC.elem=new int [LC.length];							//为合并后的新表分配一个数组空间
	pc=LC.elem;											//指针pc指向新表的第一个元素
	pa_last=LA.elem+LA.length-1;						//指针pa_last指向LA表的最后一个元素
	pb_last=LB.elem+LB.length-1;						//指针pb_last指向LB表的最后一个元素
	while(pa<=pa_last && pb<=pb_last)					//两个表都非空
	{
		if(*pa<=*pb)
				*pc++=*pa++;
		else
				*pc++=*pb++;
	}
	while(pa<=pa_last)
			*pc++=*pa++;
	while(pb<=pb_last)
			*pc++=*pb++;								//依次“摘取”两表中值较小的结点插入到LC表的最后																//LB已到达表尾，依次将LA的剩余元素插入LC表的最后											//LA已到达表尾，依次将LB的剩余元素插入LC表的最后		
}														//MergeList_List

int main()
{
	SqList La,Lb,Lc;
	int num_a,num_b;

	cout<<"请输入非递减线性表a的个数n：";	
	cin>>num_a;
	InitList_Sq(La,num_a);								//La表的创建
	input(La,num_a)	;								//依次往顺序表La里输入数据
	
	cout<<"请输入非递减线性表b的个数n：";	
	
	cin>>num_b;							//Lb表的创建	
	InitList_Sq(Lb,num_b);									//依次往顺序表La里输入数据
	input(Lb,num_b);
	MergeList_Sq(La,Lb,Lc);								//将顺序表La和Lb进行合并
	
	cout<<"非递减线性表a，b合并后的非递减线性表c为：\n";			//输出合并后的有序顺序表Lc
	
	cout<<endl;
	output(Lc);
	cout<<endl;
	return 0;
}
