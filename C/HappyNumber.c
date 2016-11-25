#include<stdio.h>
#include<stdbool.h>
int main()
{
	bool isHappy(int n);
}
bool check(int n,int *a,int *i)
{
	int t=0;
	if(n==1)
	{
		return true;
	}
	else
	{
		while(n!=0)
		{
			t+=(n%10)*(n%10);
			n=n/10;
		}
		for(int j=0;j<*i;j++)
		{
			if(a[j]==t)
			{
				return false;
			}
		}
		a[(*i)++]=t;
		return check(t,a,i);
	}
}
bool isHappy(int n)
{
	int a[100],i=0;
	return check(n,a,&i);
}
