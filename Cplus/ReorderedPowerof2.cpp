#include <vector>
using namespace std;

class Solution
{
public:
	bool reorderedPowerOf2(int N)
	{
		if (N == 1)
			return true;
		vector<int> num;
		while (N != 0)
		{
			num.push_back(N % 10);
			N /= 10;
		}
		for (auto &n : num)
		{
			if (n != 0)
			{
				n = -n; //negetive means visited
				if (backTracking(num, -n, num.size() - 1))
					return true;
				n = -n;
			}
		}
		return false;
	}

	bool backTracking(vector<int> &num, int val, int count)
	{
		if (count <= 0)
			return bitCount(val) == 1;
		for (auto &n : num)
		{
			if (n >= 0)
			{
				int old = n;
				n = -1;
				if (backTracking(num, val * 10 + old, count - 1))
					return true;
				n = old;
			}
		}
		return false;
	}

	int bitCount(int n)
	{
		int res = 0;
		while (n != 0)
		{
			n &= n - 1;
			res++;
		}
		return res;
	}
};