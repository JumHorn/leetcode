#include<stdio.h>
#include<stdbool.h>
int main()
{
	bool isPowerOfThree(int n);
}
bool isPowerOfThree(int n)
{
	if(n==1||n==3)return true;
	if(n%3==1||n%3==2||n<=0)return false;
	return isPowerOfThree(n/3);
}
