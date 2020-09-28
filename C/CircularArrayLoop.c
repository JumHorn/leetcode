#include <stdbool.h>

/*
tag each num with given tag
each turn find the taged num means there is a circle
so the base means the minimum tag in this turn
*/

bool circularArrayLoop(int *nums, int numsSize)
{
	int tag = 1000;
	for (int i = 0; i < numsSize; i++)
	{
		if (nums[i] <= 1000)
		{
			int index = i, base = ++tag, head = nums[index];
			while (nums[index] <= 1000)
			{
				int val = nums[index];
				nums[index] = ++tag;
				index = ((index + val) % numsSize + numsSize) % numsSize;
				if (nums[index] >= base && nums[index] < tag) //current turn
					return true;
				if (nums[index] > 1000 || (head ^ nums[index]) < 0)
					break;
			}
		}
	}
	return false;
}