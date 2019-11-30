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
//ͷ�巨 
Status CreateList(LinkList &L,int lenth){
	ElemType x;
	 L=new TNode;
		printf("���ʼ��data\n");
		scanf("%d",&x);
		L->data=x;
		L->next=NULL;
		LinkList head=L;
		LinkList p;
	for(int i=1;i<lenth;i++){
		if(!(p=new TNode))exit(OVERFLOW);
		printf("���ʼ��data\n");
		scanf("%d",&x);
		p->data=x;
		p->next=head;
		head=p;
		
	}
	L=head;
	return OK;
}
//β�巨 
Status CreateList2(LinkList &L,int lenth){
		ElemType x;
	 L=new TNode;
		printf("���ʼ��data\n");
		scanf("%d",&x);
		L->data=x;
		L->next=NULL;
		LinkList tail=L;
		LinkList p;
		for(int i=1;i<lenth;i++){
			p=new TNode;
			printf("���ʼ��data\n");
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
		printf("�����data����\n");
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
	printf("������������lenth\n");
		scanf("%d",&lenth);
//		CreateList(L,lenth) ;
		CreateList2(L,lenth) ;
		PrintList(L,lenth);
		printf("���������Ԫ�ص�λ�ü�data\n");
		scanf("%d",&index);
		scanf("%d",&data);
		InsertList(L,index,data,lenth);
			PrintList(L,lenth);
			printf("������ɾ��Ԫ�ص�λ��\n");
			scanf("%d",&index2);
			DeleteList(L,index2,e,lenth);
				PrintList(L,lenth);
				printf("ɾ����Ԫ��data=%d",e);
}
