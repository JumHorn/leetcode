#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> numsSameConsecDiff(int n, int k)
	{
		vector<int> res;
		if (n < 2)
			return {};
		for (int i = 1; i <= 9; ++i)
			recursive(i, n - 1, k, res);
		return res;
	}

	void recursive(int num, int N, int K, vector<int> &res)
	{
		if (N == 0)
		{
			res.push_back(num);
			return;
		}
		if (K == 0)
			recursive(num * 10 + num % 10, N - 1, K, res);
		else
		{
			if (num % 10 + K <= 9)
				recursive(num * 10 + num % 10 + K, N - 1, K, res);
			if (num % 10 - K >= 0)
				recursive(num * 10 + num % 10 - K, N - 1, K, res);
		}
	}
};