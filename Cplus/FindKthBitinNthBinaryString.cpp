
class Solution
{
public:
	char findKthBit(int n, int k)
	{
		int len[21] = {0};
		len[1] = 1;
		for (int i = 2; i < 21; ++i)
			len[i] = 2 * len[i - 1] + 1;
		int flag = 0;
		while (len[n] / 2 + 1 != k)
		{
			int val = len[n] / 2 + 1;
			if (k > val)
			{
				k = val * 2 - k;
				flag = 1 - flag;
			}
			--n;
		}
		if (flag == 0)
			return n == 1 ? '0' : '1';
		return n == 1 ? '1' : '0';
	}
};