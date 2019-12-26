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

Status CreateList(LinkList &L,int n){

	if(!(L=new LNode))exit(OVERFLOW);
	L->next=NULL;
	LinkList p;
	 for(int i=0;i<n;i++){
	 	p=new LNode;
	 	ElemType x;
	 	printf("输入链表的data\n");
	 	scanf("%d",&x);
	 	p->data=x;
	 	p->next=L->next;
	 	L->next=p;
	 }
	 return OK;
}

Status PostCreateList(LinkList &L,int n){

	if(!(L=new LNode))exit(OVERFLOW);
	L->next=NULL;
	LinkList p;
	LinkList r=L;
	 for(int i=0;i<n;i++){
	 	p=new LNode;
	 	ElemType x;
	 	printf("输入链表的data\n");
	 	scanf("%d",&x);
	 	p->data=x;
	 	p->next=NULL;
	 	r->next=p;
	 	r=p;
	 }
	 return OK;
}
Status PrintList(LinkList L){
	printf("链表data如下\n");
	LinkList p=L->next;
	while(p){
		printf("%d",p->data);
		p=p->next;
	}
		printf("打印完成\n");
	printf("\n");
	return OK;
}

Status Insert(LinkList &L,int i,ElemType e){
	int j=1;
	LinkList p=L;
	while(p&&j<i){
		p=p->next;
		j++;
	}
	if(!p||j>i)return ERROR;
	LinkList s=new LNode;
	s->data=e;
	s->next=p->next;
	p->next=s;
	return OK;
}

Status Delete(LinkList &L,int i,ElemType &e){
	LinkList p=L;
	int j=1;
	while(p->next&&j<i){
		p=p->next;
		j++;
	}
	if(!p||j>i)return ERROR;
	LinkList s=p->next;
	p->next=s->next;
	e=s->data;
	free(s);
	return OK;
}
int main(){
	LinkList L=new LNode;
	int lenth,index,x,index2,data;
	printf("请输入链表长度lenth=\n");
	scanf("%d",&lenth);
	//CreateList(L,lenth);
	PostCreateList(L,lenth);
	 PrintList(L); 
	 printf("请输入插入元素位置以及data\n");
	 scanf("%d",&index);
	 scanf("%d",&x);
Insert(L,index,x);
PrintList(L); 
printf("请输入删除元素位置\n");
scanf("%d",&index2);
Delete(L,index2,data);
//  PrintList(L,lenth);
 printf("删除元素的data=%d",data);
}
