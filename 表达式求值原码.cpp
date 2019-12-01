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
		printf("%d","��������/n");
		exit(OVERFLOW);
	}else
	return*(S.top-1);

}

Status GetTop_OPND(SqStack_OPND S){
if(S.top==S.base) {
		printf("%d","��������/n");
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
		printf("��������/n");
		exit(OVERFLOW);
	}else 
		--S.top;
	
}
void Pop_OPND(SqStack_OPND &S){
		if(S.top==S.base) {
		printf("��������/n");
		exit(OVERFLOW);
	}else 
		--S.top;
	
}

bool In(char c){ //�ж�c�Ƿ�Ϊ�����룬���򷵻�true�����򷵻�false
    if(c == '+' || c == '-' || c == '*' || c == '/' || c == '#' || c == '(' || c == ')'){
        return true;
    }else{
        return false;
    }
}

char Precede(char a,char b){ //�Ƚϲ�����a��b�����ȼ�
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

Status Operate(Status a,char op,Status b){ //������ʽ a op b
    switch(op){
    case('+'):
        return Status(a+b);
    case('-'):
        return Status(a-b);
    case('*'):
        return Status(a*b);
    case('/'):
    	if(b==0){
    			printf("��������Ϊ0\n");
    				exit(OVERFLOW);
		}
    
        return Status(a/b);
    }
 }
int main(){
    char c;SqStack_OPTR OPTR;SqStack_OPND OPND;
   InitStack_OPTR(OPTR); Push_OPTR(OPTR,'#'); //����������ͽ����ջ
   InitStack_OPND(OPND); c=getchar();//����������ջ
   

    while(c != '#' || GetTop_OPTR(OPTR) != '#'){ //����û�������߲������ջ��Ϊ��
        if(!In(c)){ //c�ǲ�����
        char a;Status b,d=0.0,n=10,x,y;
		a=getchar();
		x=c-'0';//��cת��Ϊ���� 
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
           Push_OPND(OPND,x); //������ѹ��ջ
            printf("��������ջ��Ϊ%0.3f\n",x);
            c = a;
           
        }else{ //cΪ������
            switch(Precede(GetTop_OPTR(OPTR),c)){ //�ж�ջ���������c�����ȼ�
            case('<'): //�����ַ�c�����ȼ��ϴ�
                Push_OPTR(OPTR,c);//c��ջ
                c = getchar();
                break;
            case('>'):{ //�����ַ�c�����ȼ���С
                char theta = GetTop_OPTR(OPTR); //�õ�ջ��������
                Pop_OPTR(OPTR); //ջ���������ջ
                Status b = GetTop_OPND(OPND); //ȡ��OPNDջ������������a��b
                Pop_OPND(OPND);
                Status a = GetTop_OPND(OPND);
                Pop_OPND(OPND);
                Push_OPND(OPND,Operate(a,theta,b)); //��a theta b��������ջOPND
                break;
            }
            case('='):  //���õ�����
//               Pop_OPTR(OPTR,GetTop_OPTR(OPTR));
			   Pop_OPTR(OPTR)  ;//���õ����ų�ջ
                c = getchar();
                break;
            default:
                break;
            }
        }
    }
    printf("�����%0.3f",GetTop_OPND(OPND));
   //OPNDջ�����������յļ�����
    return 0;
}



