#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int ElemType;

typedef struct Sqlist{
	ElemType *elem;
	int lenth;
	int listsize;
}Sqlist;

int InitList(Sqlist &L){
	//L.elem=(ElemType *)malloc(50*sizeof(ElemType));
		L.elem=new ElemType[50];
	if(!L.elem)return ERROR;
	L.lenth=0;
	L.listsize=50;
	return OK;
	
}

int ListInput(Sqlist &L){
	int n;
	printf("请输入顺序表长度n\n");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		if(L.lenth>=L.listsize){
			//L.elem=(ElemType *)realloc((L.listsize+10)*sizeof(ElemType));
			L.elem=new ElemType[L.listsize+10];
			L.listsize+=10;
		}
		int data;
			printf("请输入元素\n");
	scanf("%d",&data);
	L.elem[i]=data;
	L.lenth++; 
	}
	return OK;
}

int ListInsert(Sqlist &L){
	int index,data;
	int i;
		printf("请输入插入的位置以及data\n");
		scanf("%d",&index);
		scanf("%d",&data);
		if(L.lenth>=L.listsize){
				L.elem=new ElemType[L.listsize+10];
				L.listsize+=10;
			} 
		for( i=L.lenth;i>=index;i--){
			L.elem[i]=L.elem[i-1];
		}
		L.elem[i]=data;
		L.lenth++;
		return OK;
}

int ListDelete(Sqlist &L){
	int index;
		printf("请输入删除的位置\n");
		scanf("%d",&index);
		for(int i=index-1;i<L.lenth-1;i++)
		L.elem[i]=L.elem[i+1];
		L.lenth--;
		return OK;
}
int PrintList(Sqlist &L){
	printf("顺序表元素如下\n");
	for(int i=0;i<L.lenth;i++){
				printf("%d",L.elem[i]);
	}
	return OK;
}
int main(){
	Sqlist L;
	InitList(L);
	ListInput(L);
	PrintList(L);
	ListInsert(L);
	PrintList(L);
	ListDelete(L);
	PrintList(L);
}
