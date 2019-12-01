#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//������ų��� 
#define LIST_INIT_SIZE 50
#define LISTINCREMENT 10
#define OK 1
#define ERROR 0
#define OVERFLOW -2

//����Ԫ������
typedef int ElemType;

//����˳������� 
typedef struct{
ElemType *elem;
int lenth;
int listsize;
}SqList;

//����˳��� 
int InitList(SqList *L)
{
	L->elem=(ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
	if(!L->elem) return ERROR;
	L->lenth=0;
	L->listsize=LIST_INIT_SIZE;
	return OK;
}

//��ʼ��˳��� 
void InputList(SqList *L)
{
	int n,k,x;
	printf("�������ʼ��Ԫ�ص���Ŀn\n");
	scanf("%d",&n);

	for(k=1;k<=n;k++){ 
		if(L->lenth>=L->listsize)
	{
		L->elem=(ElemType *)realloc(L->elem,(L->listsize+LISTINCREMENT)*sizeof(ElemType));
	
		L->listsize+=LISTINCREMENT;
	}
	printf("������Ԫ��\n");
	scanf("%d",&x);
	L->elem[k-1]=x;
	L->lenth++;
	}
} 

//��ȡ˳����i��Ԫ�� 
ElemType GetList(SqList *L,int i)
{ 
	if(i<0||i>L->lenth)
		return ERROR;
	else
		return L->elem[i-1];
}

//��λĿ���ڱ��е�λ�� 
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

//��˳����i λ�ò���Ԫ�� 
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

//ɾ��˳����i��Ԫ�� 
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

//��˳������� 
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

//����˳�����ֵ 
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
			printf("���Ԫ��Ϊ%d\n",max);
			printf("��СԪ��Ϊ%d\n",min);
}
 
//��˳������� 
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

//˳������ 
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
        printf("======˳������Ŀ¼=======\n");  
        printf("1. ����һ���յ�˳���\n");  
        printf("2. ��ʼ��˳���\n");  
        printf("3. ��ѯ˳���ĳ��λ�õ�Ԫ��\n");  
        printf("4. ��ѯԪ����˳����е�λ��\n");  
        printf("5. ��˳���ָ��λ�ò���Ԫ��\n");  
        printf("6. ɾ��˳���ָ��λ�õ�Ԫ��\n");  
        printf("7. ��˳�������\n");  
        printf("8. �˳�\n");  
        printf("9. ����˳�����ֵ\n");  
        printf("10. ��˳�������\n");  
        printf("11. ���˳����ȫ��Ԫ��\n"); 
        printf("===========================\n");  
        printf("\n����1-11,ѡ�����:");  
        scanf("%d", &choice);  
        printf("\n��ѡ��Ĺ��ܺ�Ϊ:%d\n", choice);  
 
        switch(choice)  
        {  
            case 1:
                if (InitList(pl))
                    printf("\n����˳���ɹ�!\n\n");    
                else
                    printf("\n����˳���ʧ��!\n\n");

                break;
            case 2:
            	
                InputList(pl);

                break;
            case 3:
                printf("i=");
                scanf("%d", &i);
                elem = GetList(pl, i);
                if (elem)
                    printf("��%d��Ԫ����%d\n\n", i, elem);  
                else
                    printf("�����λ�ò��Ϸ�!");
           
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
                    printf("\n���ݲ���ɹ�!\n\n");
                else
                    printf("\n���ݲ���ʧ��!\n\n");

                break;
            case 6:
                printf("i=");
                scanf("%d", &i);
                if (DeleteList(pl, i))
                    printf("\n����ɾ���ɹ�!\n\n");
                else
                    printf("\n����ɾ��ʧ��!\n\n");

                break;
            case 7:
                PaiXULIist(pl);
                printf("\n˳����Ѿ�����!\n\n");

                break;
            case 8:
                isRunning = 0;              
                break;
		    case 9:
                FindMaxMinList(pl);

                break;
			case 10:
                NiZhiList(pl);
				 printf("\n���ݱ��Ѿ�����!\n\n");

                break;
            case 11:
                PrintList(pl);
                 printf("\n");
                break;
        }
    }
   
  
   
    return 0;

} 







