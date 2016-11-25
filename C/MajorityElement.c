#include<stdio.h>
int main()
{
	int majorityElement(int *nums,int numsSize);
}

int majorityElement(int *nums,int numsSize)
{
	int a[200][2]={0},i,j,k=0;
	for(i=0;i<numsSize;i++)
	{
		for(j=0;j<k;j++)
		{
			if(a[j][0]==nums[i])
			{
				a[j][1]++;
				if(a[j][1]>numsSize/2)
				{
					return a[j][0];
				}
				else
				{
					break;
				}
			}
		}
		if(j==k)
		{
			a[k][0]=nums[i];
			a[k][1]=1;
			if(a[k][1]>numsSize/2)
			{
				return a[k][0];
			}
			k++;
		}
	}
	return 0;
}
