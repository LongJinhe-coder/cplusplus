#include <iostream>
#include <string.h>
using namespace std;

typedef int status;

#define true 1
#define false 0

#define LH +1 //左高
#define EH 0  //等高
#define RH -1 //右高
#define max 30

//int count;//记录借书的总人数
typedef struct List
{
	char booknumbers[max];
	int borrowdate; //借书日期
	int returndate; //还书日期
	struct List *next;
} List, *LinkList;

typedef struct
{
	char borrowname[max]; //借阅者名字
	LinkList firstbook;
} borrower, borrowers[max];

typedef struct Borw
{
	borrowers bs;
	int n; //借阅者人数
} Borw;
//二叉链表结点结构定义
typedef struct Bitnode
{

	char booknumber[max]; //书号
	char bookname[max];   //书名
	char bookauthor[max]; //作者
	status acount;		  //现存量
	status allacount;	 //总库存
	int bf;				  //储存结点的平衡因子
	struct Bitnode *left, *right;
} Bitnode, *Bitree;

//f指向T的双亲，当T指向根节点时，因此f的初始调用值为Null
//查找成功，指针p指向该数据元素的结点，返回TRUE
//查找失败，P指向查找路径上访问的最后一个元素，返回false
Bitree Searchavl(Bitree T, char *key)
{
	if (!T)
		return NULL;

	//搜索到
	if (!strcmp(key, T->booknumber))
		return T;
	else if (strcmp(key, T->booknumber) < 0)
	{
		//在左子树中搜索
		return Searchavl(T->left, key);
	}
	else
	{
		//在右子树中搜索
		return Searchavl(T->right, key);
	}
}

//对以p为根的二叉排序树做右旋处理。处理之后p指向新的树根节点
//即旋转之前的左子树的根节点
void R_rotate(Bitree *p)
{
	Bitree L;
	L = (*p)->left;
	(*p)->left = L->right;
	L->right = *p;
	*p = L;
}

//对以p为根的二叉排序树做左旋处理。处理之后p指向新的树根节点
//即旋转之前的左子树的根节点
void L_rotate(Bitree *p)
{
	Bitree R;
	R = (*p)->right;
	(*p)->right = R->left;
	R->left = *p;
	*p = R;
}
//对以T为根的二叉排序树做左旋平衡处理
//处理之后T指向新的树根节点
void Leftbalance(Bitree *T)
{
	Bitree L, Lr;
	L = (*T)->left; //L指向T的左子树根结点
	switch (L->bf)
	{
		//检查T左子树的平衡度，并做相应的处理
	case LH: //新节点插入在T的左孩子的左子树上，要做单右旋处理
		(*T)->bf = L->bf = EH;
		R_rotate(T);
		break;
	case RH:		   //新节点插入在T的左孩子的右子树上，要做单右旋处理
		Lr = L->right; //Lr指向T的左孩子的右子树根
		switch (Lr->bf)
		{
		case LH:
			(*T)->bf = RH;
			L->bf = EH;
			break;
		case EH:
			(*T)->bf = L->bf = RH;
			break;
		case RH:
			(*T)->bf = EH;
			L->bf = LH;
			break;
		}
		Lr->bf = EH;
		L_rotate(&(*T)->left);
		R_rotate(T);
	}
}

//T 的右边高，不平衡，使其平衡，左旋转，左旋转前先检查R->bf
//如果为LH，R要先进行右旋转，使T->rchild->bf和T->bf一致
void Rightbalance(Bitree *T)
{
	Bitree R, Rl;
	R = (*T)->right;
	Rl = R->left;
	switch (R->bf)
	{
	case RH:
		R->bf = (*T)->bf = EH;
		L_rotate(T);
		break;
	case LH:
		switch (R->bf)
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
status Insertavl(Bitree *T, char *a, char *b, char *c, status d, status e, status *taller)
{
	if (!*T)
	{
		//插入新节点，树长高，taller为true
		//*T=(Bitree)malloc(sizeof(Bitnode));
		*T = new Bitnode;

		strcpy((*T)->booknumber, a);
		strcpy((*T)->bookname, b);
		strcpy((*T)->bookauthor, c);
		(*T)->acount = d;
		(*T)->allacount = e;
		(*T)->left = (*T)->right = NULL;
		(*T)->bf = EH;
		*taller = true;
	}
	else
	{
		if (!strcmp(a, (*T)->booknumber))
		{
			//树中存在和e有相同关键字的结点将不再插入
			*taller = false;
			(*T)->acount += d; //现库存与总库存增加
			(*T)->allacount += e;
			return false;
		}
		if (strcmp(a, (*T)->booknumber) < 0)
		{
			//应继续在t的左子树中进行搜索
			if (!Insertavl(&(*T)->left, a, b, c, d, e, taller))
				return false;
			if (*taller)
			{
				switch ((*T)->bf)
				{
				case LH:
					Leftbalance(T);
					*taller = false;
					break;
				case EH:
					(*T)->bf = LH;
					*taller = true;
					break;
				case RH:
					(*T)->bf = EH;
					*taller = false;
					break;
				}
			}
		}
		else
		{
			if (!Insertavl(&(*T)->right, a, b, c, d, e, taller))
				return false;
			if (*taller)
			{
				switch ((*T)->bf)
				{
				case LH:
					(*T)->bf = EH;
					*taller = false;
					break;
				case EH:
					(*T)->bf = RH;
					*taller = true;
					break;
				case RH:
					Rightbalance(T);
					*taller = false;
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
	cout << "请输入入库书的种类个数：";
	cin >> n;
	cout << "分别输入书的书号，书名，作者，现库存，总库存" << endl;
	status taller;
	char booknumber[max]; //书号
	char bookname[max];   //书名
	char bookauthor[max]; //作者
	status acount;		  //现存量
	status allacount;	 //总库存
	for (int i = 0; i < n; i++)
	{
		cin >> booknumber;
		cin >> bookname;
		cin >> bookauthor;
		cin >> acount;
		cin >> allacount;
		Insertavl(T, booknumber, bookname, bookauthor, acount, allacount, &taller);
	}
}

void Showbst(Bitree T)
{

	if (T)
	{
		Showbst(T->left);
		// cout<<T->data<<" ";
		cout << "书号：" << T->booknumber << ", ";
		cout << "书名：" << T->bookname << ", ";
		cout << "作者：" << T->bookauthor << ", ";
		cout << "现库存：" << T->acount << ", ";
		cout << "总库存：" << T->allacount << " ";
		cout << endl;
		Showbst(T->right);
	}
}
void InitBorrowers(Borw &bw)
{
	bw.n = 0; //初始化借阅者的个数
}

status BorrowBook(Borw &bw, Bitree *T)
{
	LinkList r, q = NULL;
	int data; //借书日期
	//int n;//当前借书人数
	char a[max];
	char name[max];

	int hasborrowed = false; //判断是否有借阅记录
	int x;					 //借书的数量
							 // cout<<"输入借阅者的人数";
							 // cin>>n;
							 //cin>>bw.n;
	cout << "请输入借阅者的名字和借书日期，以及他所借书的数量，编号" << endl;
	cin >> name;
	for (int i = 0; i < bw.n + 1; i++) //查看所有借阅信息，看此人是否有过借阅记录
	{
		if (!strcmp(name, bw.bs[i].borrowname)) //如果此人之前有借阅记录
		{
			cin >> data; //输入借书日期
			r = bw.bs[i].firstbook;
			while (r) //查看所有已借书的归还日期
			{
				if (data > r->returndate)
				{
					int z; //用来吸收未cin的字符
					cin >> z;
					char y[max];
					for (int k = 0; k < z; k++)
					{
						cin >> y;
					}

					cout << "你有未按时归还的书籍，本次借书失败" << endl;
					return true;
					break;
				}

				//cout<<r->booknumbers<<"  ";
				r = r->next;
			}
			cin >> x; //输入本次借书的数量
			//bw.bs[i].firstbook->next=NULL;
			for (int j = 0; j < x; j++) //分别借阅每一本书
			{
				int index = true; //用来判断他是否借过相同的书
				cin >> a;
				if (!Searchavl((*T), a)) //搜索图书馆有没有此书
				{
					cout << "图书馆管没有您想借的编号为：" << a << "的书，非常抱歉！" << endl;
				}
				else
				{
					r = bw.bs[i].firstbook;
					while (r) //查看所有已借书
					{
						if (!strcmp(a, r->booknumbers))
						{
							cout << "你已近借过编号为：" << a << "的书且还未归还，本次借书失败" << endl;
							index = false;
							break;
						}
						//cout<<r->booknumbers<<"  ";
						r = r->next;
					}
					if (index) //如果他没有借阅过这本书
					{
						Bitree p = Searchavl((*T), a); //找到图书馆中对应的书籍
						if (p->acount)				   //如果有库存，则借阅成功，否则失败
						{
							p->acount--;
							q = bw.bs[i].firstbook;
							bw.bs[i].firstbook = new List;
							bw.bs[i].firstbook->next = q;				//头插法建立借阅信息的链表
							strcpy(bw.bs[i].firstbook->booknumbers, a); //借阅信息记录所借书籍
							//q=bw.bs[i].firstbook;
							bw.bs[i].firstbook->borrowdate = data;
							bw.bs[i].firstbook->returndate = data + 100; //默认借书时长30天
						}
						else
						{
							cout << "书号为" << a << "的书库存不足" << endl;
						}
					}
				}
			}
			return true;
		}
	}

	//本人第一次借书，借书总人数+1
	bw.n++;
	strcpy(bw.bs[bw.n - 1].borrowname, name); //登记新人借阅者的名字
	cin >> data;							  //借阅日期
	int ifborrowed = false;					  //判断是否成功借到至少一本书
	cin >> x;								  //借阅数
	//bw.bs[i].firstbook->next=NULL;
	for (int j = 0; j < x; j++) //分别借阅每一本书
	{
		cin >> a;				 //书籍号
		if (!Searchavl((*T), a)) //搜索图书馆有没有此书
		{
			cout << "图书馆管没有您想借的编号为：" << a << "的书，非常抱歉！" << endl;
		}
		else
		{

			Bitree p = Searchavl((*T), a); //找到图书馆中对应的书籍
			if (p->acount)				   //如果有库存，则借阅成功，否则失败
			{
				p->acount--; //现有库存-1
				bw.bs[bw.n - 1].firstbook = new List;
				bw.bs[bw.n - 1].firstbook->next = q;			   //头插法建立借阅信息的链表
				strcpy(bw.bs[bw.n - 1].firstbook->booknumbers, a); //借阅信息记录所借书籍
				q = bw.bs[bw.n - 1].firstbook;
				ifborrowed = true;
				bw.bs[bw.n - 1].firstbook->borrowdate = data;
				bw.bs[bw.n - 1].firstbook->returndate = data + 100; //默认借书时长30天
			}
			else
			{
				cout << "书号为" << a << "的书已无库存" << endl;
			}
		}
	}
	//cout<<"测试1"<<bw.bs[bw.n-1].firstbook->booknumbers<<endl;
	if (!ifborrowed) //如果他本次一本书都没有借成功
	{
		cout << bw.bs[bw.n - 1].borrowname << "由于您本次没有成功借到书，您将不会有任何借阅记录" << endl;

		bw.n--; //借书总人数-1
	}

	return true;
}

status ReturnBook(Borw &bw, Bitree *T)
{
	LinkList r, q;
	int k;
	char a[max], b[max];

	cout << "请输入还书者的人数：";
	cin >> k;
	if (k > bw.n)
	{
		cout << "您输入的信息有误，还书人数超过当前借阅人数" << endl;
		return true;
	}
	for (int i = 0; i < k; i++)
	{
		int x;			  //还书的数量
		int index = true; //判断还书者信息

		//bw.bs[i]=new borrower;
		cout << "请输入还书者" << i + 1 << "的名字，以及他所还书的数量，编号" << endl;
		cin >> b; //输入还书者的名字
		for (int t = 0; t < bw.n; t++)
		{
			if (!strcmp(b, bw.bs[t].borrowname)) //找到还书者的登记信息
			{
				index = false; //已找到还书者的相关信息
				cin >> x;
				//bw.bs[i].firstbook->next=NULL;
				for (int j = 0; j < x; j++)
				{
					int hasborrowed = false; //判断当前还的书是否借阅过，避免还错书
					cin >> a;				 //输入要还的书名
					q = bw.bs[t].firstbook;
					while (q)
					{
						if (!strcmp(a, q->booknumbers)) //通过查看借阅记录，确定借过当前要还的书
						{
							hasborrowed = true; //确定借了此书
							break;
						}
						q = q->next;
					}
					if (hasborrowed)
					{

						Bitree p = Searchavl((*T), a); //找到图书馆中相同书籍
						if (true)
						{
							//cout<<"测试";
							p->acount++; //库存加1
							r = q = bw.bs[t].firstbook;
							while (q) //遍历整个链表搜索书籍
							{
								//cout<<q->booknumbers<<" , ";
								if (!strcmp(a, q->booknumbers))
								{
									if (q == bw.bs[t].firstbook) //如果还的书为头结点，则直接free
									{
										bw.bs[t].firstbook = q->next;
										free(q);
										break;
									}
									else
									{ //如果还的书不是头结点
										while (r)
										{
											if (r->next == q) //寻找指向当前节点的节点
											{
												r->next = q->next;
												free(q);
												break;
											}
											r = r->next;
										}
									}
								}

								q = q->next;
							}
						}
					}
					else
					{
						cout << "您没有书号为：“<<a<<”的书的借阅记录，您还错书了，哈哈";
					}
				}
				if (!bw.bs[t].firstbook) //如果还书者将他所有借的书归还完毕，则注销他的借阅记录
				{
					cout << bw.bs[t].borrowname << "您的书已经全部归还完毕，现将注销您的借阅记录" << endl;
					for (int i = t; i < bw.n - 1; i++)
					{
						bw.bs[t] = bw.bs[t + 1];
					}
					bw.n--; //借书总人数-1
				}

				q = NULL;
				break;
			}
		}
		if (index)
		{
			int z; //用来吸收未cin的字符
			cin >> z;
			char y[max];
			for (int k = 0; k < z; k++)
			{
				cin >> y;
			}
			cout << "未找到当前还书者的借阅记录" << endl;
		}
	}
	return true;
}

void ShowBorrowers(Borw &bw)
{
	LinkList p;
	if (bw.n > 0)
	{
		cout << "借阅信息：" << endl;
		for (int i = 0; i < bw.n; i++)
		{
			cout << bw.bs[i].borrowname << " ";
			p = bw.bs[i].firstbook;
			cout << "借的书籍有：" << endl;
			//cout<<"循环里的大小为"<<strcmp(p->booknumbers,"");
			while (p)
			{
				cout << p->booknumbers << "  "
					 << "归还日期：" << p->returndate << endl;
				p = p->next;
			}
			free(p);
			cout << endl;
		}
	}
	else
	{
		cout << "暂无任何借阅记录" << endl;
	}
}

void PrintTree(Bitree T, int count)
{
	if (T)
	{
		//count++;
		int c = count;
		while (c)
		{
			cout << "* ";
			c--;
		}
		cout << "书号：" << T->booknumber << ", ";
		cout << "书名：" << T->bookname << ", ";
		cout << "作者：" << T->bookauthor << ", ";
		cout << "现库存：" << T->acount << ", ";
		cout << "总库存：" << T->allacount << " " << endl;
		count++;
		int index = count;
		PrintTree(T->left, index);
		PrintTree(T->right, index);
	}
}

int main()
{

	int Go = true;
	Bitree T = NULL;
	status taller = 0;
	// Book B;
	Borw BW;
	cout << "现在进行的是图书馆书籍入库操作,请配合下列提示完成入库。" << endl;
	Createavl(&T);
	InitBorrowers(BW);
	cout << "相关操作提示如下：" << endl;
	cout << "0:  图书馆书籍入库" << endl;
	cout << "1:  凹入表查看图书馆所有书籍信息" << endl;
	cout << "2:  查看借阅登记信息" << endl;
	cout << "3:  借书" << endl;
	cout << "4:  还书" << endl;
	cout << "5:  退出" << endl;

	while (Go)
	{
		int select;
		cout << "请选择你的操作:" << endl;
		cin >> select;
		int count = 1;
		switch (select)
		{

		case 0:
			Createavl(&T);
			break;
		case 1:
			cout << "图书馆书籍信息：" << endl;
			PrintTree(T, count);
			break;
		case 2:
			ShowBorrowers(BW);
			break;
		case 3:
			BorrowBook(BW, &T);
			break;
		case 4:
			ReturnBook(BW, &T);
			break;
		case 5:
			Go = false;
			break;

		default:
			break;
		}
	}

	return 0;
}
