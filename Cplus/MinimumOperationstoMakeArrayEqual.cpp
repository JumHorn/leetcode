class Solution
{
public:
	int minOperations(int n)
	{
		int res = 0;
		for (int i = 1; i < n; i += 2)
			res += n - i;
		return res;
	}
};
