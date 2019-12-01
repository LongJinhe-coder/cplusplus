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
//		if(L->lenth>=L->listsize)
//	{
//		L->elem=(ElemType *)realloc(L->elem,(L->listsize+LISTINCREMENT)*sizeof(ElemType));
//	
//		L->listsize+=LISTINCREMENT;
//	}
	printf("������Ԫ��\n");
	scanf("%d",&x);
	L->elem[k-1]=x;
	L->lenth++;
	}
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
//˳������ 
void PrintList(SqList *L)
{
	int k;
	for(k=0;k<L->lenth;k++)
		printf("%d ",L->elem[k]);
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
// �ϲ�����˳���
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
        printf("======˳������Ŀ¼=======\n");  
        printf("1. ����һ���յ�˳���p1\n");  
        printf("2. ��ʼ��˳���p1\n");  
        printf("3. ��˳�������p1\n");  
        printf("4. �˳�\n");  
        printf("5. ���˳���p1��ȫ��Ԫ��\n"); 
         printf("6. ����һ���յ�˳���p2\n");  
        printf("7. ��ʼ��˳���p2\n");  
        printf("8. ��˳�������p2\n");  
        printf("9. ���˳���p2��ȫ��Ԫ��\n");  
        printf("10. ����һ���յ�˳���p3\n"); 
         printf("11. �ϲ���˳���\n"); 
         printf("12. ���˳���p3��ȫ��Ԫ��\n"); 
          
        printf("===========================\n");  
        printf("\n����1-12,ѡ�����:");  
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
                PaiXULIist(pl);
                printf("\n˳���pl�Ѿ�����!\n\n");

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
                    printf("\n����˳���ɹ�!\n\n");    
                else
                    printf("\n����˳���ʧ��!\n\n");
                    

                break;
                  case 7:
            	
                InputList(p2);

                break;
                
            case 8:
                PaiXULIist(p2);
                printf("\n˳���p2�Ѿ�����!\n\n");

                break;
                 case 9:
                PrintList(p2);

 					printf("\n");   
                break;
                 case 10:
                if (InitList(p3))
                    printf("\n����˳���p3�ɹ�!\n\n");    
                else
                    printf("\n����˳���p3ʧ��!\n\n");
                    

                break;
                 case 12:
                PrintList(p3);
					 printf("\n");   
                break;
                case 11:
                	TwoList(pl,p2,p3);
                	 printf("\n˳���p1��p2�Ѿ��ϲ�!\n\n");
                	break;
        }
    }
   
  
   
    return 0;

} 


