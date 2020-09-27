#include <stdbool.h>

bool find132pattern(int* nums, int numsSize)
{
	if (numsSize < 3)
		return false;
	int min = nums[0];
	int stack[numsSize][2], top = -1;  //{low,up}
	for (int i = 1; i < numsSize; ++i)
	{
		if (nums[i] < min)
			min = nums[i];
		else
		{
			while (top != -1)
			{
				if (nums[i] <= stack[top][0])
					break;
				if (nums[i] < stack[top][1])
					return true;
				--top;
			}
			stack[++top][0] = min;
			stack[top][1] = nums[i];
		}
	}
	return false;
}
