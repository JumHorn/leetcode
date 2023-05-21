#include <string>
using namespace std;

class Solution
{
public:
	int punishmentNumber(int n)
	{
		int res = 0;
		for (int i = 1; i <= n; ++i)
		{
			if (check(i))
				res += i * i;
		}
		return res;
	}

	bool check(int n)
	{
		string val = to_string(n * n);
		return backTracking(n, val, 0);
	}

	bool backTracking(int n, string &val, int index)
	{
		int N = val.size();
		if (n < 0)
			return false;
		if (index == N)
			return n == 0;
		int num = 0;
		for (int i = index; i < N; ++i)
		{
			num = num * 10 + (val[i] - '0');
			if (backTracking(n - num, val, i + 1))
				return true;
		}
		return false;
	}
};