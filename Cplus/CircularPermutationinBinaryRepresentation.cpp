#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> circularPermutation(int n, int start)
	{
		int len = pow(2, n);
		vector<int> res(len);
		for (int i = 0; i < len; i++)
			res[i] = i;
		res[start] = res[0];
		res[0] = start;
		backTracking(res, 1);
		return res;
	}

	bool backTracking(vector<int>& v, int index)
	{
		int n = v.size();
		if (index >= n)
			return bitDiffCount(v[0], v[n - 1]);
		for (int i = index; i < n; i++)
		{
			if (bitDiffCount(v[index - 1], v[i]))
			{
				swap(v[index], v[i]);
				if (backTracking(v, index + 1))
					return true;
				swap(v[index], v[i]);
			}
		}
		return false;
	}

	bool bitDiffCount(int a, int b)
	{
		return bitCount(a ^ b) == 1;
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
