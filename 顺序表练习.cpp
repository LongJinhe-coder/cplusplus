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
	printf("������˳�����n\n");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		if(L.lenth>=L.listsize){
			//L.elem=(ElemType *)realloc((L.listsize+10)*sizeof(ElemType));
			L.elem=new ElemType[L.listsize+10];
			L.listsize+=10;
		}
		int data;
			printf("������Ԫ��\n");
	scanf("%d",&data);
	L.elem[i]=data;
	L.lenth++; 
	}
	return OK;
}

int ListInsert(Sqlist &L){
	int index,data;
	int i;
		printf("����������λ���Լ�data\n");
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
		printf("������ɾ����λ��\n");
		scanf("%d",&index);
		for(int i=index-1;i<L.lenth-1;i++)
		L.elem[i]=L.elem[i+1];
		L.lenth--;
		return OK;
}
int PrintList(Sqlist &L){
	printf("˳���Ԫ������\n");
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
