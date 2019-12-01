#include<stdio.h> 
#include<stdlib.h>
#include<string.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

typedef int Status;
typedef char TElemType;


typedef struct TNode{
	Status data;
	struct TNode *lchild,*rchild;
}TNode,*Tree;

typedef Tree SElemType;

typedef struct{
	SElemType *base;
	SElemType *top;
	int stacksize;
}SqStack;
//�ж�ջ�Ƿ�Ϊ�� 
Status StackEmpty(SqStack S){
	if(S.top==S.base)
	return OK;
	else return ERROR;
}
//������ջ 
void InitStack(SqStack &S){
	S.base=(SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));
	if(!S.base)exit(OVERFLOW);
	S.top=S.base;
	S.stacksize=STACK_INIT_SIZE;
//		printf("��������\n");
}
//��ջ 
void Push(SqStack &S,Tree &p){
	if(S.top-S.base>=S.stacksize){
		S.base=(SElemType *)realloc(S.base,
		(S.stacksize+STACKINCREMENT)*sizeof(SElemType));
		if(!S.base)exit(OVERFLOW);
		S.top=S.base+S.stacksize;
		S.stacksize+=STACKINCREMENT;
	}
*S.top++=p;	
}
//��ջ 
void Pop(SqStack &S,Tree &p){
		if(S.top==S.base) {
		printf("��������/n");
		exit(OVERFLOW);
	}else 
	p=*--S.top;
}
//ȡջ��Ԫ�� 
Status GetTop(SqStack S,Tree &p){
	if(S.top==S.base) {
		printf("��������/n");
		exit(OVERFLOW);
	}else
	p=*(S.top-1);
	return OK;
}
//�ж���ָ���Ƿ���ͬ 
Status Equal(Tree a,Tree b){
	if(a==NULL||b==NULL)
	return ERROR;
	if(a->data==b->data&&a->rchild==b->rchild&&a->lchild==b->lchild)
	return OK;
	else return ERROR;
}
//�����ʼ�������� 
Status CreatTree(Tree &T){
	TElemType ch;
	scanf("%c",&ch);

	if(ch=='#') T=NULL;
	else{
		if(!(T=(TNode *)malloc(sizeof(TNode)))) exit(OVERFLOW);
		T->data=ch;
		CreatTree(T->lchild);
		CreatTree(T->rchild);
	}
	return OK;
}
//���������data 
Status PrintTree(Tree T){
	printf("%c",T->data);
	return OK;
}
//������������� 
Status PreOrder(Tree p){
	SqStack S;
	InitStack(S);
//	Tree p=(TNode *)malloc(sizeof(TNode));p=T;
		while(p||!StackEmpty(S)){
		if(p){
	if(!PrintTree(p))return ERROR;	Push(S,p);p=p->lchild;
		}else{
			Pop(S,p); 
			p=p->rchild; 
		}
	}
	return OK;
}
//������������� 
Status InOrder(Tree p){
	SqStack S;
	InitStack(S);
//	Tree p=(TNode *)malloc(sizeof(TNode));p=T;
	while(p||!StackEmpty(S)){
		if(p){
			Push(S,p);p=p->lchild;
		}else{
			Pop(S,p); if(!PrintTree(p))return ERROR;
			p=p->rchild; 
		}
	}
	return OK;
}
//������������� 
Status PostOrder(Tree p){
	SqStack S;
	InitStack(S);
//	Tree p=(TNode *)malloc(sizeof(TNode));p=T;
	Tree pre=NULL;//�����洢��������������� 
	Push(S,p);
	while(!StackEmpty(S)){
		GetTop(S,p);
		//�жϵ�ǰ�ڵ�����������Ƿ�Ϊ�ջ������������Ƿ��ѽ�����������ǣ�������ڵ��data 
		if((p->lchild==NULL&&p->rchild==NULL)||(pre!=NULL&&(Equal(p->lchild,pre)||Equal(p->rchild,pre)))){
			Pop(S,p);
			PrintTree(p);
			pre=p;
		}else{
			//�����ǣ��ͱ������������� 
			if(p->rchild!=NULL)
			Push(S,p->rchild);
			if(p->lchild!=NULL)
			Push(S,p->lchild);
		}
	}
	return OK;
}
  
int main(){
	Tree T;
	printf("�����ʼ��������\n"); 
	CreatTree(T);
	printf("�������������\n");
	PreOrder(T);
	printf("\n");
	printf("�������������\n");
	InOrder(T);
	printf("\n");
	printf("�������������\n");
	PostOrder(T);
}
