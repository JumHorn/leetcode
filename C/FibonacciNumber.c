#include<stdio.h>
#include<stdlib.h>

int fib(int N){
	if(N==0)
		return 0;
	if(N==1)
		return 1;
	int *p=(int*)malloc((N+1)*sizeof(int));
	p[0]=0;
	p[1]=1;
	for(int i=2;i<=N;i++)
		p[i]=p[i-1]+p[i-2];
	return p[N];
}

