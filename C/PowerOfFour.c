#include<stdio.h>
#include<stdbool.h>
int main()
{
	bool isPowerOfFour(int num);
}

bool isPowerOfFour(int num)
{
        if(num==1)
	{
		return true;
	}
	if(num<3&&num>1||num<=0)
	{
		return false;
	}
	if(num%4==0)
	{
		return isPowerOfFour(num/4);
	}
	else
	{
	    return false;
	}
}
