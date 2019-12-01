//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
//#define OK 1
//#define ERROR 0
//#define OVERFLOW -2
//
//typedef int Status;
//typedef char ElemType;
//
//typedef struct TNode{
//	ElemType data;
//	struct TNode *lchild,*rchild;
//}TNode,*BiTree;
//
//Status PrintTree(ElemType e){
//	
//	printf("%c",e);
//	return OK;
//}
//
//Status Count(int &n){
//	n++;
//	return OK;
//}
//Status CreatTree(BiTree &p){
//	ElemType ch;
//	ch=getchar();
//	if(ch=='#')p=NULL;
//	else{
//	if(!(p=(BiTree)malloc(sizeof(TNode))))exit(OVERFLOW);
//	p->data=ch;
//	 CreatTree(p->lchild);
//	 CreatTree(p->rchild);
//	}
//
//	 return OK;
//}
//
//Status PreOrder(BiTree &p,int &count){
//	
//	if(p){
//	//if(PrintTree(p->data))
//	if(p->lchild==NULL&&p->rchild==NULL){
//	Count(count);
//		//printf("now  count=%d\n",count);
//	}
//	
//	if(PreOrder(p->lchild,count))
//	if(PreOrder(p->rchild,count)) return OK;
//	return ERROR;
//	}else
//	return OK;
//	
//}
//int main(){
//	BiTree T=(TNode *)malloc(sizeof(TNode));
//	int count=0;
//		printf("按先序初始化二叉树！\n");
//	CreatTree(T);
//	PreOrder(T,count);
//	printf("叶子节点的个数是%d",count);
//}
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define OK 1
#define ERROR 0
#define OVERFLOW-2

typedef int Status;
typedef char ElemType;

typedef struct TNode{
	ElemType data;
	struct TNode *lchild,*rchild;
}TNode,*BiTree;

Status CreateTree(BiTree &T){
	ElemType ch;
	ch=getchar();
	if(ch=='#')T=NULL;
	else{
//		T=(BiTree)malloc(sizeof(TNode));
		T=new TNode;
		T->data=ch;
		CreateTree(T->lchild);
		CreateTree(T->rchild);
	}
	return OK;
}

Status PrintTree(ElemType e){
	printf("%c",e);
	return OK;
}

//Status PreOrder(BiTree T){
//	if(T){
//		PrintTree(T->data);
//		PreOrder(T->lchild);
//		PreOrder(T->rchild);
//		return OK;
//	}else
//	return OK;
//}
//
//Status InOrder(BiTree T){
//	if(T){
//	
//		InOrder(T->lchild);
//			PrintTree(T->data);
//		InOrder(T->rchild);
//		return OK;
//	}else
//	return OK;
//}
//
//Status PostOrder(BiTree T){
//	if(T){
//	
//		PostOrder(T->lchild);
//		PostOrder(T->rchild);
//			PrintTree(T->data);
//		return OK;
//	}else
//	return OK;
//}
Status Depth(BiTree T){
	int depthval=0;
	if(T){
	int ldepth=Depth(T->lchild);
	int rdepth=Depth(T->rchild);
		depthval= 1+(ldepth>rdepth?ldepth:rdepth);
	} 
	return depthval;
}

int main(){
	BiTree T=new TNode;
	printf("请按先序初始化二叉树！\n");
	CreateTree(T);
//	 printf("先序输出如下：");
//	 PreOrder(T);
//	 printf("\n");
//	  printf("中序输出如下：");
//	 InOrder(T);
//	 printf("\n");
//	  printf("后序输出如下：");
//	 PostOrder(T);
//	 printf("\n");
printf("二叉树深度为：");
int depth=Depth(T);
  printf("%d",depth);
}
