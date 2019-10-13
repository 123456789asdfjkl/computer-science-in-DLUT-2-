#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 20
typedef struct{
 	char ch[MAXSIZE];
 	int i;
}SqStack; 
void isbalance()//判断是否符号匹配 
{
	SqStack S;
	char a;
	char b;
	S.i=-1;
	int flag=1;
	printf("请输入要判断的表达式（以#结尾）:\n");
	while(true)
	{
		scanf("%c",&a);
		if(a=='{'||a=='['||a=='(')
		{
			S.ch[++S.i]=a;
			continue;
		}
		if(a=='}'||a==')'||a==']')
		{
			b=S.ch[S.i--];
			if(a=='}'&&b=='{')
			{
				continue;	
			}
			if(a==')'&&b=='(')
			{
				continue;
			}
			if(a==']'&&b=='[')
			{
				continue;
			}
			flag=0;
			break;
		}
		if(a=='#')
		{
			break;
		}
	}
	if(flag&&S.i==-1)
	{
		printf("符号匹配");
	}
	else
	{
		printf("符号不匹配");
	}
} 
int main()
{
	isbalance(); 
	return 0;	
}
