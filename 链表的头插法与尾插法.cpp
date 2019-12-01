#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int Status;
typedef int ElemType;

typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LNode,*LinkList;
//带头节点头插法 
Status PreCreatList(LinkList &L,int lenth){
	L=(LinkList)malloc(sizeof(LNode));
	L->next=NULL;
	for(int i=1;i<=lenth;i++){
		LinkList p=(LinkList)malloc(sizeof(LNode));
		p->next=L->next;
		L->next=p;
		p->data=i;
	}
	return OK;	
}
//带头节点尾插法 
Status PostCreatList(LinkList &L,int lenth){
	 //L=(LinkList)malloc(sizeof(LNode));
	 L=new LNode;
	L->next=NULL;
	LinkList r=L;
	for(int i=1;i<=lenth;i++){
		//LinkList p=(LinkList)malloc(sizeof(LNode));
		LinkList p=new LNode;
		r->next=p;
		p->next=NULL;
		p->data=i;
		r=p;
	}
return OK;	
}

Status PrintList(LinkList L,int lenth){
	LinkList p=L->next;
	for(int i=1;i<=lenth;i++){
		printf("%d",p->data);
		p=p->next;
	}
}
int main(){
		LinkList L=(LinkList)malloc(sizeof(LNode));
		//PreCreatList(L,5);
		PostCreatList(L,5);
		PrintList(L,5);
}
