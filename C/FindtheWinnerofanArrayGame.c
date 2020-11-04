
#define max(a, b) (((a) > (b)) ? (a) : (b))

int getWinner(int* arr, int arrSize, int k)
{
	int maxwin = arr[0];
	for (int i = 1; i < arrSize; ++i)
		maxwin = max(maxwin, arr[i]);
	int count = k - 1, res = max(arr[0], arr[1]);
	for (int i = 2; i < arrSize && count > 0; ++i)
	{
		if (res == maxwin)
			return res;
		if (res < arr[i])
		{
			count = k - 1;
			res = arr[i];
		}
		else
			--count;
	}
	return res;
}
