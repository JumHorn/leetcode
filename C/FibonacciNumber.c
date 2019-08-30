#include<stdio.h>
#include<stdlib.h>

int fib(int N){
	if(N==0)
		return 0;
	if(N==1)
		return 1;
	if(N==2)
		return 1;
	int p0=0,p1=1,p2=1,tmp;
	for(int i=3;i<=N;i++)
	{
		tmp=p1+p2;
		p0=p1;
		p1=p2;
		p2=tmp;
	}
	return p2;
}
