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
		if(L->lenth>=L->listsize)
	{
		L->elem=(ElemType *)realloc(L->elem,(L->listsize+LISTINCREMENT)*sizeof(ElemType));
	
		L->listsize+=LISTINCREMENT;
	}
	printf("请输入元素\n");
	scanf("%d",&x);
	L->elem[k-1]=x;
	L->lenth++;
	}
} 

//获取顺序表第i个元素 
ElemType GetList(SqList *L,int i)
{ 
	if(i<0||i>L->lenth)
		return ERROR;
	else
		return L->elem[i-1];
}

//定位目标在表中的位置 
int LocateListElem(SqList *L,ElemType e)
{
	int k=1;
	ElemType *p=L->elem;
	while(*p!=e&&k<=L->lenth)
	{
	k++;
	p++;
	}
	if(k>L->lenth)
		return ERROR;
	else
		return k;
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

//查找顺序表最值 
void FindMaxMinList(SqList *L)
{
	int k,i,max,min;
	max=L->elem[0];
	min=L->elem[0];
	for( k=0;k<L->lenth-1;k++)
	{
		if(L->elem[k]<L->elem[k+1])
			max=L->elem[k+1];
	}
		for( i=0;i<L->lenth-1;i++)
	{
		if(L->elem[i]>L->elem[i+1])
			min=L->elem[i+1];
	}
			printf("最大元素为%d\n",max);
			printf("最小元素为%d\n",min);
}
 
//给顺序表逆置 
void NiZhiList(SqList *L)
{
	int k=L->lenth/2,i,x;
	for(i=0;i<k;i++)
	{
		x=L->elem[i];
		L->elem[i]=L->elem[L->lenth-1-i];
		L->elem[L->lenth-1-i]=x;
	}
}

//顺序表输出 
void PrintList(SqList *L)
{
	int k;
	for(k=0;k<L->lenth;k++)
		printf("%d ",L->elem[k]);
}

int main()
{  
    int i, choice, position;  
    ElemType data, elem;  
    int isRunning = 1;
   
    SqList *pl = (SqList *)malloc(sizeof(SqList));      
   
    while(isRunning)  
    {  
        printf("======顺序表操作目录=======\n");  
        printf("1. 创建一个空的顺序表\n");  
        printf("2. 初始化顺序表\n");  
        printf("3. 查询顺序表某个位置的元素\n");  
        printf("4. 查询元素在顺序表中的位置\n");  
        printf("5. 向顺序表指定位置插入元素\n");  
        printf("6. 删除顺序表指定位置的元素\n");  
        printf("7. 给顺序表排序\n");  
        printf("8. 退出\n");  
        printf("9. 查找顺序表最值\n");  
        printf("10. 给顺序表逆置\n");  
        printf("11. 输出顺序表的全部元素\n"); 
        printf("===========================\n");  
        printf("\n输入1-11,选择操作:");  
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
                printf("i=");
                scanf("%d", &i);
                elem = GetList(pl, i);
                if (elem)
                    printf("第%d个元素是%d\n\n", i, elem);  
                else
                    printf("输入的位置不合法!");
           
                break;
            case 4:
                printf("data=");
                scanf("%d", &data);
                position = LocateListElem(pl, data);
                if (position)
                    printf("%d is at [%d] of the list.\n\n", data, position);
                else
                   printf("%d is not in the list.\n\n", data);

                break;
            case 5:
                printf("i=");
                scanf("%d", &i);
                 printf("data=");
                scanf("%d", &data);
                if (InsertList(pl, i, data))
                    printf("\n数据插入成功!\n\n");
                else
                    printf("\n数据插入失败!\n\n");

                break;
            case 6:
                printf("i=");
                scanf("%d", &i);
                if (DeleteList(pl, i))
                    printf("\n数据删除成功!\n\n");
                else
                    printf("\n数据删除失败!\n\n");

                break;
            case 7:
                PaiXULIist(pl);
                printf("\n顺序表已经排序!\n\n");

                break;
            case 8:
                isRunning = 0;              
                break;
		    case 9:
                FindMaxMinList(pl);

                break;
			case 10:
                NiZhiList(pl);
				 printf("\n数据表已经逆置!\n\n");

                break;
            case 11:
                PrintList(pl);
                 printf("\n");
                break;
        }
    }
   
  
   
    return 0;

} 







