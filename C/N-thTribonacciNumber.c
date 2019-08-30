#include<stdio.h>
#include<stdlib.h>

int tribonacci(int n){
	if(n==0)
		return 0;
	if(n==1)
		return 1;
	if(n==2)
		return 1;
	int *p=(int*)malloc((n+1)*sizeof(int));
	p[0]=0;
	p[1]=1;
	p[2]=1;
	for(int i=3;i<=n;i++)
		p[i]=p[i-1]+p[i-2]+p[i-3];
	return p[n];
}
