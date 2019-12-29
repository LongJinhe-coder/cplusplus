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
//判断栈是否为空 
Status StackEmpty(SqStack S){
	if(S.top==S.base)
	return OK;
	else return ERROR;
}
//建立空栈 
void InitStack(SqStack &S){
	S.base=(SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));
	if(!S.base)exit(OVERFLOW);
	S.top=S.base;
	S.stacksize=STACK_INIT_SIZE;
//		printf("输入有误\n");
}
//入栈 
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
//出栈 
void Pop(SqStack &S,Tree &p){
		if(S.top==S.base) {
		printf("输入有误/n");
		exit(OVERFLOW);
	}else 
	p=*--S.top;
}
//取栈顶元素 
Status GetTop(SqStack S,Tree &p){
	if(S.top==S.base) {
		printf("输入有误/n");
		exit(OVERFLOW);
	}else
	p=*(S.top-1);
	return OK;
}
//判断两指针是否相同 
Status Equal(Tree a,Tree b){
	if(a==NULL||b==NULL)
	return ERROR;
	if(a->data==b->data&&a->rchild==b->rchild&&a->lchild==b->lchild)
	return OK;
	else return ERROR;
}
//先序初始化二叉树 
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
//输出二叉树data 
Status PrintTree(Tree T){
	printf("%c",T->data);
	return OK;
}
//先序输出二叉树 
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
//中序输出二叉树 
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
//后续输出二叉树 
Status PostOrder(Tree p){
	SqStack S;
	InitStack(S);
//	Tree p=(TNode *)malloc(sizeof(TNode));p=T;
	Tree pre=NULL;//用来存储输出过的左右子树 
	Push(S,p);
	while(!StackEmpty(S)){
		GetTop(S,p);
		//判断当前节点的左右子树是否为空或者左右子树是否已进行输出，若是，则输出节点的data 
		if((p->lchild==NULL&&p->rchild==NULL)||(pre!=NULL&&(Equal(p->lchild,pre)||Equal(p->rchild,pre)))){
			Pop(S,p);
			PrintTree(p);
			pre=p;
		}else{
			//若不是，就遍历其左右子树 
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
	printf("先序初始化二叉树\n"); 
	CreatTree(T);
	printf("先序输出二叉树\n");
	PreOrder(T);
	printf("\n");
	printf("中序输出二叉树\n");
	InOrder(T);
	printf("\n");
	printf("后序输出二叉树\n");
	PostOrder(T);
}
