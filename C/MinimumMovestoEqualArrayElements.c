#include <limits.h>

/*
let x be the final equal array value
sum is of the original nums
x*N == moves*(N-1)+sum
and key point is that because minval must be add moves times
x=minval+moves
*/

int minMoves(int *nums, int numsSize)
{
	long min = INT_MAX, sum = 0;
	for (int i = 0; i < numsSize; ++i)
	{
		sum += nums[i];
		if (min > nums[i])
			min = nums[i];
	}
	return sum - numsSize * min;
}