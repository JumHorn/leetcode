
void duplicateZeros(int *arr, int arrSize)
{
	int i = 0, j = 0;
	for (; j < arrSize; ++i, ++j)
	{
		if (arr[i] == 0)
			++j;
	}
	if (j > arrSize)
	{
		--i;
		j = arrSize - 1;
		arr[j] = 0;
	}
	for (--i, --j; i >= 0; --i, --j)
	{
		if (arr[i] == 0)
			arr[j--] = 0;
		arr[j] = arr[i];
	}
}