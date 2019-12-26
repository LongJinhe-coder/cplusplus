#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#include <stack.h>
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef double Status;
typedef char SElemType;

typedef struct{
	SElemType *base;
	SElemType *top;
	int stacksize;
}SqStack_OPTR;

typedef struct{
	Status *base;
	Status *top;
	int stacksize;
}SqStack_OPND;

void InitStack_OPTR(SqStack_OPTR &S){
	S.base=(SElemType*)malloc(STACK_INIT_SIZE*sizeof(SElemType));
	if(!S.base)exit(OVERFLOW);
	S.top=S.base;
	S.stacksize=STACK_INIT_SIZE;

}

void InitStack_OPND(SqStack_OPND &S){
	S.base=(Status*)malloc(STACK_INIT_SIZE*sizeof(Status));
	if(!S.base)exit(OVERFLOW);
	S.top=S.base;
	S.stacksize=STACK_INIT_SIZE;
	
}

SElemType GetTop_OPTR(SqStack_OPTR S){
	if(S.top==S.base) {
		printf("%d","输入有误/n");
		exit(OVERFLOW);
	}else
	return*(S.top-1);

}

Status GetTop_OPND(SqStack_OPND S){
if(S.top==S.base) {
		printf("%d","输入有误/n");
		exit(OVERFLOW);
	}else
	return*(S.top-1);

}

void Push_OPTR(SqStack_OPTR &S,SElemType e){
	if(S.top-S.base>=S.stacksize){
		S.base=(SElemType *)realloc(S.base,
		(S.stacksize+STACKINCREMENT)*sizeof(SElemType));
		if(!S.base)exit(OVERFLOW);
		S.top=S.base+S.stacksize;
		S.stacksize+=STACKINCREMENT;
	}
	*S.top++=e;
	
}

void Push_OPND(SqStack_OPND &S,Status e){
	if(S.top-S.base>=S.stacksize){
		S.base=(Status *)realloc(S.base,
		(S.stacksize+STACKINCREMENT)*sizeof(Status));
		if(!S.base)exit(OVERFLOW);
		S.top=S.base+S.stacksize;
		S.stacksize+=STACKINCREMENT;
	}
	*S.top++=e;
	
}


void Pop_OPTR(SqStack_OPTR &S){
		if(S.top==S.base) {
		printf("输入有误/n");
		exit(OVERFLOW);
	}else 
		--S.top;
	
}
void Pop_OPND(SqStack_OPND &S){
		if(S.top==S.base) {
		printf("输入有误/n");
		exit(OVERFLOW);
	}else 
		--S.top;
	
}

bool In(char c){ //判断c是否为操作码，是则返回true，否则返回false
    if(c == '+' || c == '-' || c == '*' || c == '/' || c == '#' || c == '(' || c == ')'){
        return true;
    }else{
        return false;
    }
}

char Precede(char a,char b){ //比较操作码a和b的优先级
    switch(a){
    case('+'):case('-'):
        switch(b){
        case('+'):case('-'):case(')'):case('#'): return '>';
        case('*'):case('/'):case('('): return '<';
        }
        break;
    case('*'):case('/'):
        switch(b){
        case('+'):case('-'):case(')'):case('#'):case('*'):case('/'): return '>';
        case('('): return '<';
        }
        break;
    case('('):
        switch(b){
        case('+'):case('-'):case('('):case('*'):case('/'): return '<';
        case(')'): return '=';
        }
        break;
    case(')'):
        switch(b){
        case('+'):case('-'):case('*'):case('/'):case(')'):case('#'): return '>';
        }
        break;
    case('#'):
        switch(b){
        case('+'):case('-'):case('*'):case('/'):case('('): return '<';
        case('#'): return '=';
        }
        break;
    }
}

Status Operate(Status a,char op,Status b){ //计算表达式 a op b
    switch(op){
    case('+'):
        return Status(a+b);
    case('-'):
        return Status(a-b);
    case('*'):
        return Status(a*b);
    case('/'):
    	if(b==0){
    			printf("除数不能为0\n");
    				exit(OVERFLOW);
		}
    
        return Status(a/b);
    }
 }
int main(){
    char c;SqStack_OPTR OPTR;SqStack_OPND OPND;
   InitStack_OPTR(OPTR); Push_OPTR(OPTR,'#'); //保存操作数和结果的栈
   InitStack_OPND(OPND); c=getchar();//保存操作码的栈
   

    while(c != '#' || GetTop_OPTR(OPTR) != '#'){ //输入没结束或者操作码的栈不为空
        if(!In(c)){ //c是操作数
        char a;Status b,d=0.0,n=10,x,y;
		a=getchar();
		x=c-'0';//把c转化为数字 
        while(!In(a)){
        	if(a=='.'){
        		a=getchar();
        		while(!In(a)){
        			y=a-'0';
        			y=y/n;
        			n=n*10;
        			d=d+y;
        			a=getchar();
				}
				break;
			}
		else{
		y=a-'0';
        b=x*10+y;
		x=b;
		a=getchar();	
			}
       	
		}
		x=x+d;
           Push_OPND(OPND,x); //将数字压入栈
            printf("读入数字栈的为%0.3f\n",x);
            c = a;
           
        }else{ //c为操作码
            switch(Precede(GetTop_OPTR(OPTR),c)){ //判断栈顶操作码和c的优先级
            case('<'): //输入字符c的优先级较大
                Push_OPTR(OPTR,c);//c入栈
                c = getchar();
                break;
            case('>'):{ //输入字符c的优先级较小
                char theta = GetTop_OPTR(OPTR); //得到栈顶操作码
                Pop_OPTR(OPTR); //栈顶操作码出栈
                Status b = GetTop_OPND(OPND); //取出OPND栈的两个操作数a和b
                Pop_OPND(OPND);
                Status a = GetTop_OPND(OPND);
                Pop_OPND(OPND);
                Push_OPND(OPND,Operate(a,theta,b)); //将a theta b运算结果入栈OPND
                break;
            }
            case('='):  //无用的括号
//               Pop_OPTR(OPTR,GetTop_OPTR(OPTR));
			   Pop_OPTR(OPTR)  ;//无用的括号出栈
                c = getchar();
                break;
            default:
                break;
            }
        }
    }
    printf("结果是%0.3f",GetTop_OPND(OPND));
   //OPND栈顶的数即最终的计算结果
    return 0;
}



