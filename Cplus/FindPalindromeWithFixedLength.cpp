#include <vector>
using namespace std;

class Solution
{
public:
	vector<long long> kthPalindrome(vector<int> &queries, int intLength)
	{
		vector<long long> res;
		long long base = pow(10, (intLength + 1) / 2 - 1);
		long long maxval = pow(10, (intLength + 1) / 2);
		for (auto n : queries)
		{
			if (n - 1 + base >= maxval)
				res.push_back(-1);
			else
				res.push_back(getPalindrom(base + n - 1, intLength % 2));
		}
		return res;
	}

	long long getPalindrom(long long half, bool odd = false)
	{
		long long res = half;
		if (odd)
			half /= 10;
		for (; half > 0; half /= 10)
			res = res * 10 + half % 10;
		return res;
	}
};