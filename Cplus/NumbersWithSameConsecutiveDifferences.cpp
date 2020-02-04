#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> numsSameConsecDiff(int N, int K)
	{
		vector<int> res;
		int i = 1;
		if (N == 1)
			i = 0;
		for (; i <= 9; i++)
			recursive(res, i, N - 1, K);
		return res;
	}

	void recursive(vector<int>& res, int num, int N, int K)
	{
		if (N == 0)
		{
			res.push_back(num);
			return;
		}
		if (K == 0)
			recursive(res, num * 10 + num % 10, N - 1, K);
		else
		{
			if (num % 10 + K <= 9)
				recursive(res, num * 10 + num % 10 + K, N - 1, K);
			if (num % 10 - K >= 0)
				recursive(res, num * 10 + num % 10 - K, N - 1, K);
		}
	}
};
