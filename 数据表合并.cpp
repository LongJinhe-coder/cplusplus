#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//定义符号常量 
#define LIST_INIT_SIZE 50
#define LISTINCREMENT 10
#define OK 1
#define ERROR 0
#define OVERFLOW -2

//定义元素类型
typedef int ElemType;

//定义顺序表类型 
typedef struct{
ElemType *elem;
int lenth;
int listsize;
}SqList;

//构造顺序表 
int InitList(SqList *L)
{
	L->elem=(ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
	if(!L->elem) return ERROR;
	L->lenth=0;
	L->listsize=LIST_INIT_SIZE;
	return OK;
}

//初始化顺序表 
void InputList(SqList *L)
{
	int n,k,x;
	printf("请输入初始化元素的数目n\n");
	scanf("%d",&n);

	for(k=1;k<=n;k++){ 
//		if(L->lenth>=L->listsize)
//	{
//		L->elem=(ElemType *)realloc(L->elem,(L->listsize+LISTINCREMENT)*sizeof(ElemType));
//	
//		L->listsize+=LISTINCREMENT;
//	}
	printf("请输入元素\n");
	scanf("%d",&x);
	L->elem[k-1]=x;
	L->lenth++;
	}
} 
//给顺序表排序 
int PaiXULIist(SqList *L)
{
	int k,i,x;
	for( k=0;k<L->lenth;k++)
	for( i=0;i<L->lenth-k-1;i++)
	{
		if(L->elem[i]>L->elem[i+1])
		{
			x=L->elem[i];
			L->elem[i]=L->elem[i+1];
			L->elem[i+1]=x;
		}
	}
	return OK;
}

//删除顺序表第i个元素 
int DeleteList(SqList *L,int i)
{
	int k;
	if(i<1||i>L->lenth+1)
		return ERROR;
	for(k=i-1;k<L->lenth;k++)
	L->elem[k]=	L->elem[k+1];
	L->lenth--;
	return OK;
}
//顺序表输出 
void PrintList(SqList *L)
{
	int k;
	for(k=0;k<L->lenth;k++)
		printf("%d ",L->elem[k]);
} 
//在顺序表第i 位置插入元素 
int InsertList(SqList *L,int i,ElemType e)
{
	int k;
	if(i<1||i>L->lenth+1)
		return ERROR;
	if(L->lenth>=L->listsize)
	{
		L->elem=(ElemType *)realloc(L->elem,(L->listsize+LISTINCREMENT)*sizeof(ElemType));
		if(!L->elem) return ERROR;
		L->listsize+=LISTINCREMENT;
	}

	for(k=L->lenth-1;k>=i-1;k--)
	L->elem[k+1]=L->elem[k];
	L->elem[i-1]=e;
	L->lenth++;
	return OK;
}
// 合并两个顺序表
void TwoList(SqList *L1,SqList *L2,SqList *L3){
	int i,j,k;
	for(k=0;k<L1->lenth;k++)
	{
		L3->lenth++;
		L3->elem[k]=L1->elem[k];
	} 
	for(i=0;i<L2->lenth;i++)
	for(j=0;j<L3->lenth;j++)
	{
		if(L2->elem[i]==L3->elem[j])
		break;
		else if(L2->elem[i]<L3->elem[j]){
	
		InsertList(L3,j+1,L2->elem[i]);
		 
		 break;
	}
		else if(L2->elem[i]>L3->elem[L3->lenth-1]) 
			{
			InsertList(L3,L3->lenth+1,L2->elem[i]);
			break;
}
	}
	for(k=0;k<L3->lenth-1;k++){
		if(L3->elem[k]==L3->elem[k+1])
		DeleteList(L3,k+1);
	}
} 
int main()
{  
    int i, choice, position;  
    ElemType data, elem;  
    int isRunning = 1;
   
    SqList *pl = (SqList *)malloc(sizeof(SqList));      
     SqList *p2 = (SqList *)malloc(sizeof(SqList)); 
     SqList *p3 = (SqList *)malloc(sizeof(SqList)); 
   
    while(isRunning)  
    {  
        printf("======顺序表操作目录=======\n");  
        printf("1. 创建一个空的顺序表p1\n");  
        printf("2. 初始化顺序表p1\n");  
        printf("3. 给顺序表排序p1\n");  
        printf("4. 退出\n");  
        printf("5. 输出顺序表p1的全部元素\n"); 
         printf("6. 创建一个空的顺序表p2\n");  
        printf("7. 初始化顺序表p2\n");  
        printf("8. 给顺序表排序p2\n");  
        printf("9. 输出顺序表p2的全部元素\n");  
        printf("10. 创建一个空的顺序表p3\n"); 
         printf("11. 合并两顺序表\n"); 
         printf("12. 输出顺序表p3的全部元素\n"); 
          
        printf("===========================\n");  
        printf("\n输入1-12,选择操作:");  
        scanf("%d", &choice);  
        printf("\n你选择的功能号为:%d\n", choice);  
 
        switch(choice)  
        {  
            case 1:
                if (InitList(pl))
                    printf("\n创建顺序表成功!\n\n");    
                else
                    printf("\n创建顺序表失败!\n\n");
                    

                break;
            case 2:
            	
                InputList(pl);

                break;
           
            case 3:
                PaiXULIist(pl);
                printf("\n顺序表pl已经排序!\n\n");

                break;
            case 4:
                isRunning = 0;              
                break;
		   
            case 5:
                PrintList(pl);

			 printf("\n");    
                break;
             case 6:
                if (InitList(p2))
                    printf("\n创建顺序表成功!\n\n");    
                else
                    printf("\n创建顺序表失败!\n\n");
                    

                break;
                  case 7:
            	
                InputList(p2);

                break;
                
            case 8:
                PaiXULIist(p2);
                printf("\n顺序表p2已经排序!\n\n");

                break;
                 case 9:
                PrintList(p2);

 					printf("\n");   
                break;
                 case 10:
                if (InitList(p3))
                    printf("\n创建顺序表p3成功!\n\n");    
                else
                    printf("\n创建顺序表p3失败!\n\n");
                    

                break;
                 case 12:
                PrintList(p3);
					 printf("\n");   
                break;
                case 11:
                	TwoList(pl,p2,p3);
                	 printf("\n顺序表p1，p2已经合并!\n\n");
                	break;
        }
    }
   
  
   
    return 0;

} 


