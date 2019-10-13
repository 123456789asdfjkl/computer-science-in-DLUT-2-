// test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "string.h"


void main(int argc, char* argv[])
{
	int aa[5]={0,1,2,3,4};
	int *p;

	//数组指针
    p=&aa[0];
   for(int i=4;i>=0;i--)
   {
	*p=i;
	p++;
   }

	//字符串指针
	char *string="DLUT";
	char str[4];
	string=string+3;
	for(int i=4;i>=0;i--)
	{    
    str[4-i]=*string;
	string--;
	}


	//指针的指针
	char c='A';
	char *pc=&c;
	char **ppc=&pc;
	char c1=**ppc;
}

