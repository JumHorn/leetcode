#include<stdio.h>
#include<malloc.h>

int main()
{
	int * plusOne(int *digits,int digitsSize,int *returnSize);
}

int * plusOne(int *digits,int digitsSize,int *returnSize)
{
	int i,carry=1;
	int *p;
	//p = (int *)malloc(sizeof(int)*digitsSize);
	//*returnSize=digitsSize;
	for(i=digitsSize-1;i>=0;i--)
	{
		if(digits[i]+carry>9)
		{
			digits[i]=0;
			carry=1;
		}
		else
		{
			digits[i]=digits[i]+carry;
			carry=0;
		}
	}
	if(carry==1)
	{
		p=(int *)malloc(sizeof(int)*digitsSize);
		p[0]=1;
		*returnSize=digitsSize+1;
		for(i=0;i<digitsSize;i++)
		{
			p[i+1]=digits[i];
		}
	}
	else
	{
		p=digits;
		*returnSize=digitsSize;
	}
	return p;
}

