#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *maxSlidingWindow(int *nums, int numsSize, int k, int *returnSize)
{
	*returnSize = numsSize - k + 1;
	int *res = (int *)malloc(*returnSize * sizeof(int));
	int deque[k], front = 0, rear = 0;
	for (int i = 0, j = 0; i < numsSize; i++)
	{
		while (front != rear && nums[deque[(rear + 1) % k]] <= nums[i])
			rear = (rear + 1) % k;
		while (front != rear && i - k >= deque[front])
			front = (front + k - 1) % k;
		deque[rear] = i;
		rear = (rear + k - 1) % k;
		if (i + 1 >= k)
			res[j++] = nums[deque[front]];
	}
	return res;
}