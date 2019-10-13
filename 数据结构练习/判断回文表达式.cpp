#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 20
/**
	回文表达式样例：a+bb+a；表达式输入以@为结束标志 
**/
typedef struct{
	char data[MAXSIZE];
	int top;
}SeqStack; //创建栈 
void judge()
{
	SeqStack s;
	s.top=-1;
	char ch;
	printf("请输入要判断的表达式：\n");
	while(1)
	{
		scanf("%c",&ch);
		if(ch=='@')
		{
			break;
		}
		else
		{
			if(s.top==-1)
			{
				s.data[++s.top]=ch;
			}
			else
			{
				if(ch==s.data[s.top])
				{
					s.top--;
				}
				else
				{
					s.data[++s.top]=ch; 
				}
			}
		}
	}
	if(s.top==-1)
	{
		printf("该表达式为回文表达式\n"); 
	}
	else
	{
		printf("该表达式不是回文表达式\n"); 
	}
}
int main()
{
	judge();
}
