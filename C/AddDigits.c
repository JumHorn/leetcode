#include<stdio.h>
void main()
{
	int addDigits(int num);
	printf("%d\n",addDigits(19));
}
int addDigits(int num)
{
	int temp=0;
	if(num/10==0)
	{
		num=num%10;
	}
	else
	{
		while(num!=0)
		{
			temp=temp+num%10;
			num=num/10;
		}
		return addDigits(temp);
	}
        return num;
}
