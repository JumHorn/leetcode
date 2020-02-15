
int checkEvenNumber(int n)
{
	if (n == 0)
		return 0;
	int res = 0;
	while (n != 0)
	{
		res++;
		n /= 10;
	}
	return res % 2 == 0 ? 1 : 0;
}

int findNumbers(int* nums, int numsSize)
{
	int res = 0;
	for (int i = 0; i < numsSize; i++)
		res += checkEvenNumber(nums[i]);
	return res;
}

