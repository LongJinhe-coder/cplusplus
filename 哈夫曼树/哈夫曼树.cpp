#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#include <fstream>
//#include <iostream>
//using namespace std;

#define OK 1
#define ERROR 0
#define OVERFLOW -2
 
typedef int Status;

typedef struct{
	char ch;
	int weight;
	int parent,left,right;
}HTNode,*HuffmanTree;

typedef char ** HuffmanCode;
//查找权值最小的两位结点 
void Select(HuffmanTree T,int n,int &s1,int &s2){
	int min1,min2;
	int i=1;
	while(T[i].parent!=0&&i<=n){
		i++;
	}
	min1=T[i].weight;
	s1=i;
	i++;
	while(T[i].parent!=0&&i<=n){
		i++;
	}
	if(T[i].weight<min1){
				min2=min1;
				min1=T[i].weight;
				s2=s1;
				s1=i;
			}else
			{
				min2=T[i].weight;
				s2=i;
			}
			i++;
	//循环遍历，比较出最小两个节点 
	for(int j=i;j<=n;j++){
		if(T[j].parent!=0){
			continue;
		}
			if(T[j].weight<min1){
			min2=min1;
				min1=T[j].weight;
				s2=s1;
				s1=j;
			}else if(T[j].weight>=min1&&T[j].weight<min2){
				min2=T[j].weight;
				s2=j;
			}
	}
		//printf("%d  %d\n",min1,min2);

//cout<<min1<<" "<<min2<<endl;
}
 //构建哈夫曼树 
void CreateHuffmanTree(HuffmanTree &T,int *w,char *z,int n){
	if(n<=1)return;
	int m=2*n-1;
	//存结点的数组T 
	T=(HuffmanTree)malloc((m+1)*sizeof(HTNode));
	//T=new HTNode[m+1];
	//初始化叶子结点 
	for(int i=1;i<=n;i++){
		T[i].weight=w[i-1];
		T[i].ch=z[i-1];
		//	printf("%d\n",T[i].weight);
			//cout<<T[i].weight<<endl;
		T[i].parent=0;
		T[i].left=0;
		T[i].right=0;
	}
	//初始化其他结点 
	for(int i=n+1;i<=m;i++){
		T[i].ch='#';
		T[i].weight=0;
		T[i].parent=0;
		T[i].left=0;
		T[i].right=0;
	}
	//从最底层叶子结点依次向上构造哈夫曼树 
	for(int i=n+1;i<=m;i++){
		int s1,s2;
		Select(T,i-1,s1,s2);
		T[s1].parent=T[s2].parent=i;
		T[i].left=s1;
		T[i].right=s2;
		T[i].weight=T[s1].weight+T[s2].weight;
	//printf("父亲节点%d-------",T[i].weight);
	}

struct Node{
        char name ;
        int weight;
        int parent;
        int lchild;
        int rchild;
    } node [m+1];
     
    FILE * output  = fopen("C://Users/Administrator/Desktop/数据结构实验/cplusplus/哈夫曼树/hufftree.dat","w");
    if(output == NULL){
        printf("无法打开文件");
        exit(0);
    }
  //将哈夫曼树的每一个节点信息存放至二进制文件 
    for(int i=1;i<=m;++i){
        node[i].name=T[i].ch;
        node[i].weight=T[i].weight;
       //printf("权值%d\n",T[i].weight);
        node[i].parent=T[i].parent;
        node[i].lchild=T[i].left;
        node[i].rchild=T[i].right;
        fwrite(&node[i],sizeof(struct Node),1,output);
//         printf("imhere\n");
    }
    fclose(output);
}
//叶子结点编码 
void HuffmanCoding(HuffmanTree &T,HuffmanCode &C,int n){

//	C=(HuffmanCode)malloc((n+1)*sizeof(char *));
	C=new char *[n+1];
	//char *cd=(char *)malloc(n*sizeof(char));
	char *cd=new char[n];
	cd[n-1]='\0';
	
	//从叶子结点循环到根结点 
	for(int i=1;i<=n;i++){
		int start=n-1;
		int c=i;
		int j=T[i].parent;
		while(j!=0){
			if(T[j].left==c)
			cd[start--]='0';
			else
			cd[start--]='1';
			c=j;
			j=T[c].parent;
		}
		C[i]=(char *)malloc((n-start)*sizeof(char));
		strcpy(C[i],&cd[start+1]);
	}
	free(cd);
	
}

void PrintHuffmanCode(HuffmanCode C,int *w,char *z,int n) {
	 printf("Huffmancode : \n");

    for(int i = 1; i <= n; i++)
      printf("%c %d code = %s\n",z[i-1],w[i-1], C[i]);
        
}
//将文件中的字符串编译成huffmancode存到另一个文件中 
void Encoding(HuffmanCode C,char *z,int n){
	 char buff[255];
	FILE *fp = NULL;
 fp = fopen("C://Users/Administrator/Desktop/数据结构实验/cplusplus/哈夫曼树/ToBeTran.txt", "r");
		 fgets(buff,255, (FILE*)fp);
		 fclose(fp);
		printf("ToBeTran:%s\n",buff);
		//把字符串取出来存放到字符数组buff中 
	//	printf("%c",buff[0]);
		FILE *fp2 = NULL;
		 fp2 = fopen("C://Users/Administrator/Desktop/数据结构实验/cplusplus/哈夫曼树/CodeFile.txt", "w+");
		 int i=0;
		 while(buff[i]!=0){
//		 	printf("进循环了\n");
 
		 	for(int j=0;j<n;j++){// buff中每一个字符依次和哈夫曼树中的结点名字作比较 
		 		
		 		if(buff[i]==z[j]){//若相等，就把对应字符的huffmancode存到文件 CodeFile.txt中 
		 		//	printf("%s\n",C[j+1]);
		 			fputs(C[j+1],fp2);
//		 			printf("相等\n");
		 			break;
				 }
		 		
			 }
			 i++; 
		 }
		 fclose(fp2);
		
} 
//把CodeFile.txt中的huffmancode译码成字符串 
void Decoding(int n,HuffmanCode C,char *z){

HuffmanCode D=new char *[1024];
	 char buff[255];
		 FILE *fp = NULL;
		 fp = fopen("C://Users/Administrator/Desktop/数据结构实验/cplusplus/哈夫曼树/CodeFile.txt", "r");
		 fgets(buff, 255, (FILE*)fp);
		 //先把CodeFile.txt中的huffmancode取出来存到buff数组中 
		  fclose(fp);
		  fp = fopen("C://Users/Administrator/Desktop/数据结构实验/cplusplus/哈夫曼树/TextFile.txt", "w");
		  printf("CodeFile:%s\n",buff);
		  int i=0,j=0,index=0;
		  
		  while(buff[j]!=0){
		  	//char ch[i+1];
		  	//这里用二维数组来存储分割的buff数组中的整个huffmancode字符串，也是译码的关键所在 
		  char *ch=new char[i+2];
	ch[i+1]='\0';
		  	for(int b=0;b<=i;b++){
		  		ch[b]=buff[b+index];
			  }
		//把buff数组中指定位置以及指定长度的huffmancode 复制到二维数组ch中来 
		  //D[j]=(char *)malloc(i*sizeof(char));
		  D[j]=new char[i];
		strcpy(D[j],&ch[0]);
		  	for(int k=1;k<=n;k++){//二维数组中的huffmancode和二叉树中的huffmancode这个比较 
//		  		printf("进循环了\n");
//		  		printf("%s",D[j]);
//		  		printf("和%s\n",C[k]);
		  		if(strcmp(D[j],C[k]) == 0){//若相等，则把此huffmancode对应的字符名字存到文件TextFile.txt 
//		  			printf("相等\n");
		  			fputc(z[k-1],fp);
		  				free(ch);
		  				index=j+1;//相等，index标记当前在buff数组中的位置 
		  				i=-1;
		  				break;
				  }
			  }
			  j++;
			  i++;
		  }
 
	fclose(fp);
}
// 把之前存二进制文件的哈夫曼树打印出来 
//void PrintHuffmanTree(HuffmanCode C,int n){
//	int m=2*n-1;
//	
//	struct Node{
//        char name ;
//        int weight;
//        int parent;
//        int lchild;
//        int rchild;
//    } node [m+1];
//     
//    FILE * input  = fopen("C://Users/Administrator/Desktop/数据结构实验/哈夫曼树/hufftree.dat","r");
//    if(input == NULL){
//        printf("无法打开文件");
//        exit(0);
//    }
//    printf("---------------------------------\n");
//  printf("name  weight  parent  lchild  rchild\n");
//    for(int i=1;i<=m;++i){
//        fread(&node[i],sizeof(struct Node),1,input);
////         printf("imhere\n");
//	printf("  %c      %d      %d       %d       %d\n",node[i].name,node[i].weight,node[i].parent,
//	node[i].lchild,node[i].rchild);
//    }
//    
//    fclose(input);
//
//}
void HuffPrint(HuffmanTree T,int i,int &count){
		count++;//到孩子结点，计数加1; 
	int counting=count;

	 FILE *fp = NULL;
		 fp = fopen("C://Users/Administrator/Desktop/数据结构实验/cplusplus/哈夫曼树/HuffPrint.txt", "a");
		 fprintf(fp,"\n");
	if(i){
			while(counting){
				 fputc('.', fp);
				  fputc(' ', fp);
				   
				   counting--;
			}
				fputs("weight: ",fp);
				int lenth=1;
				int weight=T[i].weight;
			//	printf("此时的weight=%d",weight);
				//算出权值为几位数 
				while(weight/10>=1){
					lenth++;
					weight=weight/10;
				}
				weight=T[i].weight;
			//	printf("此时的lenth=%d\n",lenth);
				char buff[lenth];
				int index=lenth;
				//把int类型的权值转化为字符串存到数组buff中 
				for(int j=lenth;j>0;j--){
					if(lenth==1){
							buff[j-1]=weight+'0';
					}
					else{
						buff[j-1]=weight%((lenth-1)*10)+'0';
					}
					
					weight/=10;
					lenth-=1;
				}
				for(int k=0;k<index;k++){
						fputc(buff[k],fp);
				}
//				printf("权值数组是%s",buff);
//					fputs(buff,fp);
					//如果不是叶子结点，则把他的字符存入文件 
					if(T[i].ch!='#'){
						fputs(" char: ",fp);
						fputc(T[i].ch,fp);
					}
						fclose(fp);
	
	//printf("T[i].left=%d\n",T[i].left);
	int count2=count;
	HuffPrint(T,T[i].left, count);
	//printf("wowowowowowowowowowowowowowowo");
	HuffPrint(T,T[i].right, count2);
	}
	
}
int main(void){

	 char buff[255];
	FILE *fp = NULL;
 fp = fopen("C://Users/Administrator/Desktop/数据结构实验/cplusplus/哈夫曼树/ToBeTran.txt", "r");
		 fgets(buff,255, (FILE*)fp);
		 fclose(fp);

		 int k=0;
		 //统计ToBeTran.txt中字符串长度 
		 while(buff[k]){
	
		 	k++;
		 }
		 int lenth=k;
		 int t=0;
		 printf("数组长度是%d\n",lenth);
		 //printf("第二个是%c",buff[1]); 
		 for(int i=0;i<lenth;i++){
		 	for(int j=i+1;j<lenth;j++){
		 		if(buff[i]==buff[j]&&buff[i]!='^'){
		 			buff[j]='^';
		 			t++;//计数文件ToBeTran.txt中相同字符的个数，并把重复的字符改为^
				 }
			 }
		 }
		 
		 int n=lenth-t;//得到文件ToBeTran.txt中不同字符个数 
		 char z[n];//定义一个长度为ToBeTran.txt中不同字符个数大小的字符数组 
		 int f=0;
		 //把不同字符依次放入数组z中 
   for(int i=0;i<n;i++){
   	while(buff[f]=='^'){
   		f++;
	   }
   	if(buff[f]!='^')
   	z[i]=buff[f];
   	//printf("检验%c",z[i]);
   	f++;
   }
    
//    printf("输入字符个数n: \n");
//    scanf("%d",&n);
    int w[n];
	printf("分别输入%d个字符权值: \n",n);
    for(int i=0;i<n;i++){
    	printf("字符%c的权值: \n",z[i]);
    	scanf("%d",&w[i]);
   
//    scanf(" %c",&z[i]); 
    //scanf("%d",&w[i]);
    //scanf("%c",&z[i]);
    //	z[i]=getchar();
    
	}
    HuffmanTree p=new HTNode;
    HuffmanCode code;
    CreateHuffmanTree(p,w,z,n);
    HuffmanCoding(p,code,n);
    PrintHuffmanCode(code,w,z,n);
    Encoding(code,z,n);
    Decoding(n,code,z);
    int count=-1;
    HuffPrint(p,2*n-1,count);
    //PrintHuffmanTree(code, n);
    return 0;
}
