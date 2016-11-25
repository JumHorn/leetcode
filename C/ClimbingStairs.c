//递归重复计算太多，采取动态规划
#include<stdio.h>
int main()
{
	int climbstairs(int n);
}

int climbstairs(int n)
{
	if(n==1)return 1;
	if(n==2)return 2;
	return climbstairs(n-1)+climbstairs(n-2);
}
