

bool circularArrayLoop(int* nums, int numsSize)
{
	int label = 1000;
	for (int i = 0; i < numsSize; i++)
	{
		if (nums[i] <= 1000)
		{
			int index = i, count = ++label;
			bool forward = (nums[index] > 0);
			while (nums[index] <= 1000)
			{
				int tmp = nums[index];
				nums[index] = ++label;
				index = ((index + tmp) % numsSize + numsSize) % numsSize;
				if (nums[index] <= 1000)
					if ((forward && nums[index] < 0) || (!forward && nums[index] > 0))
						break;
				if (nums[index] < count && nums[index] > 1000)
					break;
				if (nums[index] >= count && nums[index] <= label)
				{
					if (nums[index] != label)
						return true;
					break;
				}
			}
		}
	}
	return false;
}

