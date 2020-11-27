
int constrainedSubsetSum(int *nums, int numsSize, int k)
{
	int size = k + 1;
	int deque[size], front = 0, rear = 0, dp[numsSize], res;
	res = dp[0] = nums[0];
	deque[front] = 0;
	front = (front + 1) % size; //push front
	for (int i = 1; i < numsSize; ++i)
	{
		while (i - deque[front] > k)
			front = (front - 1 + size) % size; //pop front
		dp[i] = nums[i] + (dp[deque[front]] < 0 ? 0 : dp[deque[front]]);
		while (front != rear && dp[i] > dp[deque[(rear + 1) % size]])
			rear = (rear + 1) % size; //pop back
		deque[rear] = i;
		rear = (rear - 1 + size) % size; //push back
		if (dp[i] > res)
			res = dp[i];
	}
	return res;
}