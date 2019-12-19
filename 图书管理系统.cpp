#include<iostream>
#include<string.h>
using namespace std;
 
typedef int status;

#define true 1
#define false 0
 
#define LH +1   //左高
#define EH 0     //等高
#define RH -1     //右高
#define max 30

typedef struct List
{
    char booknumbers[max];
    struct List *next;
}List,*LinkList;

typedef struct
{
    char borrowname[max];//借阅者名字
    int  borrowdate[max];//借书日期
    int returndate[max];//还书日期
    LinkList firstbook;
}borrower,borrowers[max];

typedef struct Borw{
	borrowers bs;
	int n;//借阅者人数
}Borw;
//二叉链表结点结构定义
typedef struct Bitnode
{

	char booknumber[max];//书号
   char bookname[max];//书名
   char bookauthor[max];//作者
   status acount;//现存量
   status allacount;//总库存
	int bf;    //储存结点的平衡因子
	struct Bitnode *left,*right;
}Bitnode,*Bitree;
   
 
//f指向T的双亲，当T指向根节点时，因此f的初始调用值为Null
//查找成功，指针p指向该数据元素的结点，返回TRUE
//查找失败，P指向查找路径上访问的最后一个元素，返回false
Bitree Searchavl(Bitree T,char *key)
{
	if (!T) 
		return NULL;
 
    //搜索到  
    if (!strcmp(key,T->booknumber))
        return T;
    else if (strcmp(key,T->booknumber)<0)
    {
        //在左子树中搜索  
        return Searchavl(T->left,key);
    }
    else
    {
        //在右子树中搜索  
        return  Searchavl(T->right,key);
    }
}
 
 
//对以p为根的二叉排序树做右旋处理。处理之后p指向新的树根节点
//即旋转之前的左子树的根节点
void R_rotate(Bitree *p)
{
	Bitree L;
	L=(*p)->left;
	(*p)->left=L->right;
	L->right=*p;
	*p=L;
}
 
//对以p为根的二叉排序树做左旋处理。处理之后p指向新的树根节点
//即旋转之前的左子树的根节点
void L_rotate(Bitree *p)
{
	Bitree R;
	R=(*p)->right;
	(*p)->right=R->left;
	R->left=*p;
	*p=R;
}
//对以T为根的二叉排序树做左旋平衡处理
//处理之后T指向新的树根节点
void Leftbalance(Bitree *T)
{
	Bitree L,Lr;
	L=(*T)->left;  //L指向T的左子树根结点
	switch(L->bf)
	{
		//检查T左子树的平衡度，并做相应的处理
	case LH:  //新节点插入在T的左孩子的左子树上，要做单右旋处理
		(*T)->bf=L->bf=EH;
		R_rotate(T);
		break;
    case RH:    //新节点插入在T的左孩子的右子树上，要做单右旋处理
		Lr=L->right;  //Lr指向T的左孩子的右子树根
		switch(Lr->bf)
		{
		case LH: 
			(*T)->bf=RH;
			L->bf=EH;
			break;
		case EH:
			(*T)->bf=L->bf=RH;
			break;
		case RH:
			(*T)->bf=EH;
			L->bf=LH;
			break;
		}
		Lr->bf=EH;
		L_rotate(&(*T)->left);
		R_rotate(T);
	}
}
 
 
//T 的右边高，不平衡，使其平衡，左旋转，左旋转前先检查R->bf
//如果为LH，R要先进行右旋转，使T->rchild->bf和T->bf一致
void Rightbalance(Bitree *T)
{
    Bitree R,Rl;
    R = (*T)->right;
    Rl = R->left;
    switch(R->bf)
    {
        case RH:
            R->bf = (*T)->bf = EH;
            L_rotate(T);
            break;
        case LH:
            switch(R->bf)
            {
                case LH:
                    R->bf = RH;
                    (*T)->bf = EH;
                    break;
                case EH:
                    R->bf = (*T)->bf = EH;
                    break;
                case RH:
                    R->bf = EH;
                    (*T)->bf = LH;
                    break;
            }
            Rl->bf = EH;
            R_rotate(&R);
            L_rotate(T);
            break;
    }
}
 
//若在平衡的二叉排序树T中不存在和e有相同关键字的结点，则插入一个
//数据元素为e的新节点并返回1，否则返回0
//若因插入使得二叉树失去平衡，则做平衡旋转，布尔变量taller反映T长高与否
status Insertavl(Bitree *T,char *a,char *b,char *c,status d,status e,status *taller)
{
	if(!*T)
	{
		//插入新节点，树长高，taller为true
		*T=(Bitree)malloc(sizeof(Bitnode));
		
		strcpy((*T)->booknumber,a);
		strcpy((*T)->bookname,b);
		strcpy((*T)->bookauthor,c);
		(*T)->acount=d;
		(*T)->allacount=e;
		(*T)->left=(*T)->right=NULL;
		(*T)->bf=EH;
		*taller=true;
	}
	else
	{
		if(!strcmp(a,(*T)->booknumber))
		{
			//树中存在和e有相同关键字的结点将不再插入
			*taller=false;
			return false;
		}
		if(strcmp(a,(*T)->booknumber)<0)
		{
			//应继续在t的左子树中进行搜索
			if(!Insertavl(&(*T)->left,a,b,c,d,e,taller))
				return false;
			if(*taller)
			{
				switch((*T)->bf)
				{
				case LH:
					Leftbalance(T);
					*taller=false;
					break;
				case EH:
					(*T)->bf=LH;
					*taller=true;
					break;
				case RH:
					(*T)->bf=EH;
					*taller=false;
					break;
				}
			}
		}
		else
		{
			if(!Insertavl(&(*T)->right,a,b,c,d,e,taller))
				return false;
			if(*taller)
			{
				switch((*T)->bf)
				{
				case LH:
					(*T)->bf=EH;
					*taller=false;
					break;
				case EH:
					(*T)->bf=RH;
					*taller=true;
					break;
				case RH:
					Rightbalance(T);
					*taller=false;
					break;
				}
			}
		}
	}
	return true;
}
 
void Createavl(Bitree *T)
{
	int n;
	cout<<"输入入库书的种类个数"<<endl;
	cin>>n;
	cout<<"分别输入书的书号，书名，作者，现库存，总库存"<<endl;
	status taller;
	char booknumber[max];//书号
   char bookname[max];//书名
   char bookauthor[max];//作者
   status acount;//现存量
   status allacount;//总库存
	for(int i=0;i<n;i++)
	{
		cin>>booknumber;
		cin>>bookname;
		cin>>bookauthor;
		cin>>acount;
		cin>>allacount;
		Insertavl(T,booknumber,bookname,bookauthor,acount,allacount,&taller);
	}
}
 
 
void Showbst(Bitree T)
{
	if(T)
	{
		Showbst(T->left);
		// cout<<T->data<<" ";
				cout<<"书号："<<T->booknumber<<" ";
				cout<<"书名："<<T->bookname<<" ";
				cout<<"作者："<<T->bookauthor<<" ";
				cout<<"现库存："<<T->acount<<" ";
				cout<<"总库存："<<T->allacount<<" ";
				cout<<endl;
		Showbst(T->right);
	}
}
 

void BorrowBook(Borw &bw,Bitree *T){
	LinkList r,q=NULL;
	char a[max];
	int x;//借书的数量
	cout<<"输入借阅者的人数";
	cin>>bw.n;
	for (int i = 0; i < bw.n; i++)
	{
		
		cout<<"请输入借阅者"<<i+1<<"的名字，以及他所借书的数量，编号与借书日期"<<endl;
		cin>>bw.bs[i].borrowname;//借阅信息登记借阅者的姓名
		//cout<<"测试"<<bw.bs[i].borrowname;
		cin>>x;
		//bw.bs[i].firstbook->next=NULL;
		for (int j = 0; j < x; j++)//分别借阅每一本书
		{
			cin>>a;
			Bitree p=Searchavl((*T),a);//找到图书馆中对应的书籍
			if (p->acount)//如果有库存，则借阅成功，否则失败
			{
				p->acount--;
			bw.bs[i].firstbook=new List;
			bw.bs[i].firstbook->next=q;//头插法建立借阅信息的链表
			strcpy(bw.bs[i].firstbook->booknumbers,a);//借阅信息记录所借书籍
			q=bw.bs[i].firstbook;
			}
			
		}
		q=NULL;
		// cin>>bw.bs[i].borrowdate;
		// bw.bs[i].returndate=bw.bs[i].borrowdate+30;
	}
	
}
void ReturnBook(Borw &bw,Bitree *T){
LinkList r,q;
    int k;
	char a[max],b[max];
	int x;//还书的数量
	cout<<"输入还书者的人数";
	cin>>k;
	if(k>bw.n){
		cout<<"输入有误";
		exit(0);
	}
	for (int i = 0; i < k; i++)
	{
		//bw.bs[i]=new borrower;
		cout<<"请输入还书者"<<i+1<<"的名字，以及他所还书的数量，编号"<<endl;
		cin>>b;//输入还书者的名字
		for (int t = 0; t < bw.n; t++)
		{
			if (!strcmp(b,bw.bs[t].borrowname))//找到还书者的登记信息
			{
				cin>>x;
		//bw.bs[i].firstbook->next=NULL;
		for (int j = 0; j < x; j++)
		{
			cin>>a;//输入要还的书名
			Bitree p=Searchavl((*T),a);//找到图书馆中相同书籍
			if (true)
			{
				p->acount++;//库存加1
				r=q=bw.bs[t].firstbook;
				while (q)//遍历整个链表搜索书籍
		{
			//cout<<q->booknumbers<<" , ";
			if (!strcmp(a,q->booknumbers))
			{
				if (q==bw.bs[t].firstbook)//如果还的书为头结点，则直接free
				{
					bw.bs[t].firstbook=q->next;
					free(q);
					break;
				}else{//如果还的书不是头结点
					while (r)
					{
						if (r->next==q)//寻找指向当前节点的节点
						{
							r->next=q->next;
							free(q);
							break;
						}
						
					}
					

				}
				
				

			}
			
			q=q->next;
		}
			}
			
		}
		q=NULL;
			}
			
		}
		
	}
}

void ShowBorrowers(Borw &bw){
	LinkList p;
	cout<<"借阅信息："<<endl;
	for (int i = 0; i < bw.n; i++)
	{
		cout<<bw.bs[i].borrowname<<" ";
		p=bw.bs[i].firstbook;
		cout<<"借的书籍有：";
		//cout<<"循环里的大小为"<<strcmp(p->booknumbers,"");
		while (p)
		{
			cout<<p->booknumbers<<"  ";
			p=p->next;
		}
		free(p);
		cout<<endl;
		
	}
	
}
// }
int main()
{
	//int a[]={62,88,58,47,35,73,51,99,37,93};
 
	Bitree T=NULL;
	status taller=0;
	// Book B;
	Borw BW;
	//创建二叉排序树
	Createavl(&T);
	//SaveBooks(&T,B);
	cout<<"中序遍历的结果为："<<endl;
	Showbst(T);
	cout<<endl;
	
	BorrowBook(BW,&T);
	cout<<"中序遍历的结果为："<<endl;
	Showbst(T);
	cout<<endl;
	
	ShowBorrowers(BW);
	ReturnBook(BW,&T);
	cout<<"中序遍历的结果为："<<endl;
	Showbst(T);
	cout<<endl;
	ShowBorrowers(BW);
	//在二叉排序树中插入56
	// Insertavl(&T,56,&taller);
	// cout<<"中序遍历的结果为："<<endl;
	// Showbst(T);
	// cout<<endl;
 
 
	// int b=58;  //需要查找的值
	// Bitree p=NULL;
	// T=Searchavl(T,b);
	// cout<<"查找结果为:\n"<<"指针："<<T<<endl
	// 	<<"指针的值为："<<T->data<<endl;
 
 
	//system("pause");
	return 0;
}
