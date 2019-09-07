#include<limits.h>


int dominantIndex(int* nums, int numsSize){
    if(numsSize<2)
        return 0;
	int first=INT_MIN,second=INT_MIN,res;
	for(int i=0;i<numsSize;i++)
	{
		if(nums[i]>first)
		{
			second=first;
			first=nums[i];
			res=i;
		}
		else if(nums[i]>second)
			second=nums[i];
	}
	if(first>=2*second)
		return res;
	return -1;
}

