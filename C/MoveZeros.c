#include<stdio.h>
int main()
{
	void moveZeroes(int * nums,int numsSize);
        int a[2]={2,1},i;
        moveZeroes(a,2);
        for(i=0;i<2;i++)
        {
            printf("%d\t",a[i]);
        }
        printf("\n");
}

void moveZeroes(int * nums,int numsSize)
{
	int i,j,k=numsSize-1,temp;
	for(i=0;i<=k;i++)
	{
		while(1)
		{
			if(nums[i]==0)
			{
				if(nums[k]!=0)
				{
					nums[i]=nums[k];
					nums[k]=0;
					k--;
					break;
				}
				else
				{
					if(k==i)
					{
					    k--;
					    break;
					}
					else
					{
					    k--;
					    continue;
					}
				}
			}
			else
			{
			      break;
			}
		}
	}
	for(i=0;i<k;i++)
	{
		for(j=k;j>i;j--)
		{
			if(nums[j-1]>nums[j])
			{
				temp=nums[j-1];
				nums[j-1]=nums[j];
				nums[j]=temp;
			}
		}
	}
}


