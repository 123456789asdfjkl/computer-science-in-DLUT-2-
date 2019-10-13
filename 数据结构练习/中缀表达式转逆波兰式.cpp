#include<stdio.h>
#define MAXSIZE 20
typedef struct SeqStack
{
 int data[MAXSIZE];
 int top;
}SeqStack;
SeqStack s;
void ReversePolishNotation()
{
 	char input[MAXSIZE], result[MAXSIZE];
     int i = 0, j = 0;
     int k=0;
     s.top = -1;
     int n=1;
    while(n)
	 {
	 	scanf("%c",&input[k]);
	 	if(input[k]=='#')
	 	{
	 		n=0;
		 }
		 k++;
	  } 
     while (input[i] != '#')
     {
          if (input[i] == '(' || input[i] == ')')
          {
               if (input[i] == '(')
                    s.data[++s.top] = input[i];
               else if (input[i] == ')')
               {
                    while (s.data[s.top] != '(')
                         result[j++] = s.data[s.top--];
                    s.top--;
               }
          }
         else if (input[i] <= 'z' && input[i] >= 'a')
              result[j++] = input[i];
         else if ((input[i] == '+') || (input[i] == '-'))
         {
              while (s.top != -1 && s.data[s.top] != '(')
                  result[j++] = s.data[s.top--];
              s.data[++s.top] = input[i];
         }
         else if (input[i] == '*' || input[i] == '/')
         {
              if ((s.top != -1) && s.data[s.top] != '(' && ((s.data[s.top] == '*') || (s.data[s.top] == '/')))
                  result[j++] = s.data[s.top--];
              s.data[++s.top] = input[i];
         }
         i++;
     }
     while (s.top != -1)
         result[j++] = s.data[s.top--];
     result[j] = '\0';
     for (j = 0; result[j]!='\0'; j++)
         printf("%c", result[j]);
     printf("\n");
}
int main()
{
     ReversePolishNotation();
     return 0;
}
