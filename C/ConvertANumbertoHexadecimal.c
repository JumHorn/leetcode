#include<stdio.h>
void convert(unsigned int num,char * p);
 char s[9]={'t','t','t','t','t','t','t','t','\0'};
int main()
{
	char * toHex(int num);
        char * p;
        p=toHex(16);
	printf("%s\n",p);
}

char * toHex(int num)
{
        //static char s[9]={'t','t','t','t','t','t','t','t','\0'};
	char *p;
	unsigned int n=num;
        if(num==0)
        {
            return "0";
        }
	p=&s[7];
	convert(n,p);
	p=s;
	while(*p=='t')
	{
		p++;
	}  
	return p;
}
void convert(unsigned int num,char * p)
{
	if(num==0)
	{
		return;
	}
	if(num%16<=9&&num%16>=0)
	{
	      *p=num%16+48;
	}
	else
	{
		switch(num%16)
		{
			case 10:*p='a';break;
			case 11:*p='b';break;
			case 12:*p='c';break;
			case 13:*p='d';break;
			case 14:*p='e';break;
			case 15:*p='f';break;
		}
	}
	convert(num/16,--p);
}
