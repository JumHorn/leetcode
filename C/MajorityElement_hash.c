#include<stdio.h>
int main()
{
	int majorityElement(int *nums,int numsSize);
}

int majorityElement(int *nums,int numsSize)
{
	int a[2147483647]={0},i;
	for(i=0;i<numsSize;i++)
	{
		a[nums[i]%2147483647]++;
		if(a[nums[i]%2147483647]>numsSize/2)
		{
			return nums[i];
		}
	}
	return 0;
}
