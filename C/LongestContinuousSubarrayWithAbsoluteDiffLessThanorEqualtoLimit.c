
int longestSubarray(int *nums, int numsSize, int limit)
{
	int size = numsSize, deque1[size], front1 = 0, rear1 = 0; //max deque
	int deque2[size], front2 = 0, rear2 = 0;				  //min deque
	int j = 0, i = 0;
	for (; i < numsSize; ++i)
	{
		while (front1 != rear1 && nums[i] > deque1[(rear1 + 1) % size])
			rear1 = (rear1 + 1) % size; //pop back
		deque1[rear1] = nums[i];
		rear1 = (rear1 - 1 + size) % size; //push back

		while (front2 != rear2 && nums[i] < deque2[(rear2 + 1) % size])
			rear2 = (rear2 + 1) % size; //pop back
		deque2[rear2] = nums[i];
		rear2 = (rear2 - 1 + size) % size; //push back
		if (deque1[front1] - deque2[front2] > limit)
		{
			if (deque1[front1] == nums[j])
				front1 = (front1 - 1 + size) % size; //pop front
			if (deque2[front2] == nums[j])
				front2 = (front2 - 1 + size) % size; //pop front
			++j;
		}
	}
	return i - j;
}