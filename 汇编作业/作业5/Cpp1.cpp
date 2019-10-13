#include<stdio.h>
int main()
{
	int b[5];
	int i;
	int *p=b;
	for(i=0;i<5;p++,i++)
		*p=0;
 	return 0;
}