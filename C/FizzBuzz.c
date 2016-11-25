#include<stdio.h>
#include<malloc.h>
int main()
{
	char ** fizzBuzz(int n,int *returnSize);
}

char ** fizzBuzz(int n,int *returnSize)
{
	char **p = (char**)malloc(sizeof("FizzBuzz")*n);//申请行数
	int i;
	for(i=0;i<n;i++)
	{
		p[i]=(char *)malloc(sizeof("FizzBuzz"));//为每行申请空间
	}
	*returnSize=n;
	for(i=1;i<=n;i++)
	{
		if(i%3==0&&i%5==0)
		{
			p[i-1]="FizzBuzz";
		}
		else if(i%3==0)
		{
			p[i-1]="Fizz";
		}
		else if(i%5==0)
		{
			p[i-1]="Buzz";
		}
		else
		{
			sprintf(p[i-1],"%d",i);
		}
	}
	return p;
}
