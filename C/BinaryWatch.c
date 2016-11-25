#include<stdio.h>
#include<string.h>
#include<malloc.h>
int bitcount(int num);
int main()
{
	char** readBinaryWatch(int num,int * returnSzie);
}

char** readBinaryWatch(int num,int * returnSize)
{
	char** b = malloc((sizeof(char *))*300);
	char a[300][5]={0};
	int i,j,k=0;
	for(i=0;i<12;i++)
	{
		for(j=0;j<60;j++)
		{
			if(bitcount(i)+bitcount(j)==num)
			{
				sprintf(a[k++],"%d:%02d",i,j);
			}
		}
	}
	*returnSize=k;
	for(i=0;i<k;i++)
	{
		b[i]=a[i];
	}
	return b;
}
int bitcount(int num)
{
	int result=0;
	while(num!=0)
	{
		if(num%2==1)
		{
			result++;
		}
		num=num/2;
	}
	return result;
}
