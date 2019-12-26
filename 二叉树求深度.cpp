#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int Status;
typedef char ElemType;

typedef struct BTNode{
	ElemType data;
	struct BTNode *rchild,*lchild;
}BTNode,*BiTree;

Status CreatTree(BiTree &T){
	ElemType ch;
	ch=getchar();
	if(ch=='#')T=NULL;
	else{
		if(!(T=(BiTree)malloc(sizeof(BTNode)))) exit(OVERFLOW);
		T->data=ch;
		CreatTree(T->lchild);
		CreatTree(T->rchild);
	}
	return OK;
}

Status InCreatTree(BiTree &T){
	ElemType ch;
	ch=getchar();
	if(ch=='#')T=NULL;
	else{
		InCreatTree(T->lchild);
		if(!(T=(BiTree)malloc(sizeof(BTNode)))) exit(OVERFLOW);
		T->data=ch;
		InCreatTree(T->rchild);
	}
	return OK;
}

//Status PreOrder(BiTree T){
//	if(T){
//		if(PrintTree(T))
//		if(PreOrder(T->lchild))
//		if(PreOrder(T->rchild))
//		return OK;
//		return ERROR;
//	}else 
//	return OK;
//}
Status Depth(BiTree T){
	int depth;
	
	if(!T) depth=0;
	else{
	int LeftDepth=Depth(T->lchild);
    int	RightDepth=Depth(T->rchild);
    if(LeftDepth>=RightDepth)
     depth=1+LeftDepth;
    else
    depth=1+RightDepth;

	}
	return depth;
}
int main(){
	BiTree p=(BiTree)malloc(sizeof(BTNode));
	CreatTree(p);
	int depth=Depth(p);
	printf("鏍戠殑娣卞害涓�%d",depth);
}
