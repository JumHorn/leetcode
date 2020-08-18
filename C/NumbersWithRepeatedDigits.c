
int arrangment(int n, int m)
{
	if (m <= 0 || n <= 0)
		return 0;
	int res = 1;
	while (--m >= 0)
		res *= n--;
	return res;
}

int countDifferentNumber(int *num, int size, int index, int *seen)
{
	if (index < 0)
		return 0;
	int count = 0;
	for (int i = 0; i < 10 && i < num[index]; ++i)
	{
		if (seen[i] != 1)
			++count;
	}
	if (index == 0)
		return count + 1 - seen[num[0]];
	int extra = count * arrangment(10 - (size - index), index);
	if (seen[num[index]] == 1)
		return extra;
	seen[num[index]] = 1;
	return countDifferentNumber(num, size, index - 1, seen) + extra;
}

int numDupDigitsAtMostN(int N)
{
	int num[10], size = 0, n = N;
	while (n != 0)
	{
		num[size++] = n % 10;
		n /= 10;
	}
	if (size == 1)
		return 0;
	int extra = (num[size - 1] - 1) * arrangment(9, size - 1);
	for (int i = 1, j = 9, k = 81; i < size - 1; ++i, k *= --j)
		extra += k;
	if (size > 1)
		extra += 9;
	int seen[10] = {0};
	seen[num[size - 1]] = 1;
	return N - (countDifferentNumber(num, size, size - 2, seen) + extra);
}