#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> sortByBits(vector<int>& arr)
	{
		sort(arr.begin(), arr.end(), *this);
		return arr;
	}

	bool operator()(int lhs, int rhs)
	{
		int a = bitCount(lhs), b = bitCount(rhs);
		if (a == b)
			return lhs < rhs;
		return a < b;
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
