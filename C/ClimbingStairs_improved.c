#include<stdio.h>
int main()
{
	int climbStairs(int n);
}
int climbStairs(int n)
{
	if(n<3)
	{
		return n;
	}
	int a[100];
	a[1]=1;
	a[2]=2;
	for(int i=3;i<=n;i++)
	{
		a[i]=a[i-1]+a[i-2];
	}
	return a[n];
}
