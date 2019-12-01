#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -2
  
typedef  int Status;
typedef char TElemType;

typedef struct BiTNode{
TElemType data;
struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

//��������������нڵ��ֵ 
Status CreatBiTree(BiTree &T){
	TElemType ch;
//	printf("�������ʼ����������\n");
//	scanf("%c",&ch);
	ch=getchar(); 
	if(ch=='#') T=NULL;
	else{
		if(!(T=(BiTNode *)malloc(sizeof(BiTNode)))) exit(OVERFLOW);
		T->data=ch;
		CreatBiTree(T->lchild);
		CreatBiTree(T->rchild);
	}
	return OK;
}

Status PrintElement(TElemType e){
	printf("%c",e);
	return OK;
}
//������������� 
Status PreOrder(BiTree T){
	if(T){
		if(PrintElement(T->data))
		if(PreOrder(T->lchild))
		if(PreOrder(T->rchild))  return OK;
		return ERROR;
	}else return OK; 
	}

//������������� 
Status InOrder(BiTree T){
	if(T){
		if(InOrder(T->lchild))
	    if(PrintElement(T->data))
		if(InOrder(T->rchild))  return OK;
		return ERROR;
	}else return OK; 
	}
	
	//������������� 
Status PostOrder(BiTree T){
	if(T){
		if(PostOrder(T->lchild))
		if(PostOrder(T->rchild))
		 if(PrintElement(T->data)) 
		  return OK;
		return ERROR;
	}else return OK; 
	}
	
	int main(){
		BiTNode *T=(BiTNode *)malloc(sizeof(BiTNode));
		printf("�������ʼ����������\n");
		CreatBiTree(T);
		printf("�������������:\n");
		PreOrder(T);
		printf("\n");
		printf("�������������:\n");
		InOrder(T);
	    printf("\n");
		printf("�������������:\n");
		PostOrder(T);
	}
