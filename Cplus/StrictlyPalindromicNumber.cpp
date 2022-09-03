#include <vector>
using namespace std;

class Solution
{
public:
	bool isStrictlyPalindromic(int n)
	{
		for (int i = 2; i <= n - 2; ++i)
		{
			if (!checkPalindrom(toBase(n, i)))
				return false;
		}
		return true;
	}

	bool checkPalindrom(const vector<int> &v)
	{
		int N = v.size();
		for (int i = 0, j = N - 1; i < j; ++i, --j)
		{
			if (v[i] != v[j])
				return false;
		}
		return true;
	}

	vector<int> toBase(int n, int base)
	{
		vector<int> res;
		for (; n > 0; n /= base)
			res.push_back(n % base);
		return res;
	}
};