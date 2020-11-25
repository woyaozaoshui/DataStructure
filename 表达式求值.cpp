#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
 
typedef  int ElemType;
#define STACK_INIT_SIZE 100
#define  STACKINCREMENT 10
#define OK 1
 
typedef struct{
        ElemType *base;//null
        ElemType *top;
        int  stacksize;
}sqStack;
 
void InitStack(sqStack  *s)
{
    s->base=(ElemType*)malloc(STACK_INIT_SIZE* sizeof(ElemType));
    if(!s->base)
    {
        exit(1);
    }
    s->top=s->base;
    s->stacksize=STACK_INIT_SIZE;
}
void Push(sqStack *s,ElemType e)//把e的值赋给top    e没用
{
    if(s->top-s->base>=s->stacksize) //栈满追加储存空间
    {
        s->base=(ElemType*)realloc(s->base,(s->stacksize+STACKINCREMENT)*sizeof(ElemType));
       if(!s->base)
       {
        exit(1);
        }
        s->top=s->base+s->stacksize;
        s->stacksize+=STACKINCREMENT;
    }
    *(s->top)=e;
     s->top++;
    //*s->top++=e     *((s->op)++)=e
 
}
void  Pop(sqStack *s,char *e)//用e的地址去得到值，e有意义了 后续可用
{
        if(s->top==s->base)
             exit(1);
        *e=*(--(s->top));//先运算再赋值
 
}
char GetTop(sqStack *s)
{
    if(s->top==s->base)
	{
		return -1;
    }
		return  *(s->top-1);
 
}
 
int In(char e)//判断读入字符是否为运算符 
{
	if(e=='+'||e=='-'||e=='*'||e=='/'||e=='('||e==')'||e=='#')
	    return 1;//是 
	else 
	    return 0; //不是 
}
char Precede(char a,char b)//比较运算符的优先级 
{
	char f;
	if(a=='+'||a=='-')
	{
		if(b=='+'||b=='-'||b==')'||b=='#')
		    f='>';
		else if(b=='*'||b=='/'||b=='(')
		    f='<';
	}
	else if(a=='*'||a=='/')
	{
		if(b=='+'||b=='-'||b=='*'||b=='/'||b==')'||b=='#')
		   f='>';
		else if(b=='(')
		   f='<';
	}
	else if(a=='(')
	{
		if(b=='+'||b=='-'||b=='*'||b=='/'||b=='(')
		   f='<';
		else if(b==')')
		   f='=';
	}
	else if(a==')')
	{
		if(b=='+'||b=='-'||b=='*'||b=='/'||b==')'||b=='#')
		   f='>';
	}
	else if(a=='#')
	{
		if(b=='+'||b=='-'||b=='*'||b=='/'||b=='(')
		   f='<';
		else if(b=='#')
		   f='=';
	}
	return f;
}
char Operate(char a,char theta,char b)//运算 
{
	char c;
	a=a-'0';
	b=b-'0';
	if(theta=='+')
	  c=a+b+'0';
	else if(theta=='-')
	  c=a-b+'0';
	else if(theta=='*')
	  c=a*b+'0';
	else if(theta=='/')
	  c=a/b+'0';	  
	return c; 
}
int EvaluateExpression()
{
	sqStack OPND,OPTR;
	char ch,a,b,theta,x;
	InitStack(&OPND);//寄存操作数和运算结果 
	InitStack(&OPTR);//寄存运算符 
	Push(&OPTR,'#');
	ch=getchar();
	while(ch!='#'||GetTop(&OPTR)!='#')
	{
		if(!In(ch))
		{
			Push(&OPND,ch);
			ch=getchar();
		}
		else
		{
			switch(Precede(GetTop(&OPTR),ch))
			{
				case '<':
					Push(&OPTR,ch);
				    ch=getchar();
					break;
				case '>':
					Pop(&OPTR,&theta);
					Pop(&OPND,&b);
					Pop(&OPND,&a);
					Push(&OPND,Operate(a,theta,b));
					break;
				case '=':
					Pop(&OPTR,&x);
				    ch=getchar();
					break;
			}
		} 
	}
	return GetTop(&OPND)-'0';
}
int main()
{
	printf("请输入算术表达式,以#结束\n");
	printf("例如\t  1*(2-1)# \t\n");
	printf("结果是: %d\n",EvaluateExpression());
	return OK;
} 
	

