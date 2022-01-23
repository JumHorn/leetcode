#include <vector>
using namespace std;

class Solution
{
public:
	int maximumGood(vector<vector<int>> &statements)
	{
		int N = statements.size(), res = 0;
		for (int i = (1 << N) - 1; i > 0; --i)
		{
			int good[20] = {0}, bad[20] = {0};
			for (int j = 0; j < N; ++j)
			{
				if (i & (1 << j))
				{
					for (int k = 0; k < statements[j].size(); ++k)
					{
						if (statements[j][k] == 1)
							good[k] = 1;
						else if (statements[j][k] == 0)
							bad[k] = 1;
					}
				}
			}
			bool flag = true;
			for (int i = 0; i < N && flag; ++i)
			{
				if (good[i] == 1 && bad[i] == 1)
					flag = false;
			}
			for (int j = 0; j < N && flag; ++j)
			{
				if (i & (1 << j))
				{
					if (bad[j] == 1)
						flag = false;
				}
				else
				{
					if (good[j] == 1)
						flag = false;
				}
			}
			if (flag)
				res = max(res, bitCount(i));
		}
		return res;
	}

	int bitCount(int n)
	{
		int res = 0;
		for (; n != 0; n &= n - 1)
			++res;
		return res;
	}
};