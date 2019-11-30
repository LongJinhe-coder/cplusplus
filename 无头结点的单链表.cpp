#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int Status;
typedef int ElemType;

typedef struct TNode{
	ElemType data;
	struct TNode *next;
}TNode,*LinkList;
//头插法 
Status CreateList(LinkList &L,int lenth){
	ElemType x;
	 L=new TNode;
		printf("请初始化data\n");
		scanf("%d",&x);
		L->data=x;
		L->next=NULL;
		LinkList head=L;
		LinkList p;
	for(int i=1;i<lenth;i++){
		if(!(p=new TNode))exit(OVERFLOW);
		printf("请初始化data\n");
		scanf("%d",&x);
		p->data=x;
		p->next=head;
		head=p;
		
	}
	L=head;
	return OK;
}
//尾插法 
Status CreateList2(LinkList &L,int lenth){
		ElemType x;
	 L=new TNode;
		printf("请初始化data\n");
		scanf("%d",&x);
		L->data=x;
		L->next=NULL;
		LinkList tail=L;
		LinkList p;
		for(int i=1;i<lenth;i++){
			p=new TNode;
			printf("请初始化data\n");
		scanf("%d",&x);
		p->data=x;
		p->next=NULL;
		tail->next=p;
		tail=p;
		}
}

Status InsertList(LinkList &L,int i,ElemType e,int &lenth){
	LinkList p=L;
	int j=1;
	if(i<1||i>lenth+1){
		printf("error");
		return ERROR;
	}
	if(i==1){
		LinkList s=new TNode;
		s->data=e;
		s->next=L;
		L=s;
		return OK;
	}else{
		while(j<i-1){
		p=p->next;
		j++;
	} 
	LinkList s=new TNode;
	s->data=e;
	s->next=p->next;
	p->next=s;
	}
	lenth++;
  return OK;
	
}

Status DeleteList(LinkList &L,int i,ElemType &e,int &lenth)
{
	int j=1;
	LinkList p=L;
	if(i<1||i>lenth)return ERROR;
	if(i==1){
		LinkList s=L;
		e=s->data;
		L=s->next;
		free(s);
		return OK;
	}else{
		while(j<i-1){
			p=p->next;
			j++;
		}
		LinkList s=p->next;
		p->next=s->next;
		e=s->data;
		free(s);
	}
	lenth--;
	return OK;
 } 
Status PrintList(LinkList L,int lenth){
		printf("链表的data如下\n");
		LinkList p=L;
	for(int i=0;i<lenth;i++){
			printf("%d",p->data);
			
			p=p->next;
		
	}
}

int main(){
	int lenth;
	int index,data,e,index2;
	LinkList L=new TNode;
	printf("请输入链表长度lenth\n");
		scanf("%d",&lenth);
//		CreateList(L,lenth) ;
		CreateList2(L,lenth) ;
		PrintList(L,lenth);
		printf("请输入插入元素的位置及data\n");
		scanf("%d",&index);
		scanf("%d",&data);
		InsertList(L,index,data,lenth);
			PrintList(L,lenth);
			printf("请输入删除元素的位置\n");
			scanf("%d",&index2);
			DeleteList(L,index2,e,lenth);
				PrintList(L,lenth);
				printf("删除的元素data=%d",e);
}
