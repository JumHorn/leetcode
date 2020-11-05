
#define min(a, b) (((a) < (b)) ? (a) : (b))

int findLengthOfShortestSubarray(int* arr, int arrSize)
{
	int left = 0, right = arrSize - 1;
	while (left + 1 < arrSize && arr[left] <= arr[left + 1])
		++left;
	if (left == arrSize - 1)
		return 0;

	while (right > left && arr[right - 1] <= arr[right])
		--right;
	//merge left,and right
	int res = min(arrSize - left - 1, right);
	for (int i = 0, j = right; i <= left && j < arrSize;)
	{
		if (arr[j] >= arr[i])
		{
			res = min(res, j - i - 1);
			++i;
		}
		else
			++j;
	}
	return res;
}
