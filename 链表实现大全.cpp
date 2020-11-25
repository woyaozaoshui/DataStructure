#include<stdio.h>
#include<iostream>
#include<algorithm>

#define OK 1
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define NULL 0
#define OVERFLOW -1

using namespace std;

typedef int ElemType;
typedef int Status;

typedef struct LNode{
    ElemType data;
    struct LNode * next;
}*Link,*Position;
 
typedef struct {
	Link head,tail;
	int len;
}Linklist;

Status MakeNode(Link &p,ElemType e){
	p = (LNode*)malloc(sizeof(LNode));
	if(!p){return ERROR;}
	else{
		p->data = e;
		p->next = NULL;
		return OK;
	}
}

void FreeNode(Link &p){
	free(p);
	p=NULL;
}

Status InitList(LinkList &L){
	ElemType e;
	e = -1;
	if(!MakeNode(L->head,e)){return ERROR;
	}else{
		L->head = L->tail;
		len = 0;
		return OK;
	}
}

Status DestoryList(LinkList &L){
	LNode *p = L->head->next;
	while(p){
		L->head = p->next;
		FreeNode(p);                                                                                                                                                                                                            
		p = L->head->next;
	}
	FreeNode(L.head);
	L->head = NULL;
	L->tail = NULL;
	L.len = 0;
	return OK;
}

Status clearList(LinkList &L){
	LNode *p = L->head->next;
	while(p){
		L->head = p->next;
		FreeNode(p);                                                                                                                                                                                                            
		p = L->head->next;
	}
	FreeNode(L.head);
	L->head = L->tail;
	L.len = 0;
	return OK;
}

Status InsFirst(LinkList &L,Link s){
	s->next = L->head->next;
	L->head->next = s;
	if(!len)
	L->tail = s;
	L.len++;
	return OK;
}

Status DelFirst(LinkList &L,Link &q){
	if(!len){
		q=NULL;
		return ERROR;
	}
	if(len == 1){
		L->head = L->tail;
		return OK;
	}
	q = L->head->next;
	L->head->next = q->next;
	q->next = NULL;
	len--;
	return OK;
	}
}

Status Append(LinkList &L,Link s){
}

Status Remove(LinkList &L,Link &q){
}

Status InsBefore(LinkList &L,Link &p,Link s){
}

Status InsAfter(LinkList &L,Link &p,Link s){
}

Status SetCurElem(Link &p,ElemType e){
}

ElemType GetCurElem(Link p){
}

Stauts ListEmpty(LinkList L){
}

int ListLength(LinkList L){
}

Position GetHead(LinkList L){
}

Position GetLast(LinkList L){
}

Position PriorPos(LinkList L,Link p){
}

Position NextPos(LinkList L,Link p){
}

Status LocateElem(LinkList L,ElemType e,Status(*compare)(ElemType,ElemType)){
}

Status ListTraverse(LinkList L,Status(*visit)()){
}

Status MergeList_L(LinkList &La,LinkList &Lb,Link &Lc){
}

Status Listinsert_L(LinkList &L,int i,ElemType e){
}
































































