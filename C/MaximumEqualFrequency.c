
int maxEqualFreq(int* nums, int numsSize)
{
	int count[100001] = {0}, freq[100001] = {0}, res = 0;
	for (int i = 0; i < numsSize; ++i)
	{
		--freq[count[nums[i]]];
		int c = ++count[nums[i]];
		++freq[c];
		//already the same freq, the following number shoud be removed
		if (freq[c] * c == i + 1 && i + 1 < numsSize)
			res = i + 2;
		//the other numbers have the same freq d
		int d = i + 1 - freq[c] * c;
		if (freq[d] == 1 && (d == 1 || d == c + 1))
			res = i + 1;
	}
	return res;
}
