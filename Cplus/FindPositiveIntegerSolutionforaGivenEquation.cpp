#include <vector>
using namespace std;

// This is the custom function interface.
// You should not implement it, or speculate about its implementation
class CustomFunction
{
public:
	// Returns f(x, y) for any given positive integers x and y.
	// Note that f(x, y) is increasing with respect to both x and y.
	// i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
	int f(int x, int y);
};

class Solution
{
public:
	vector<vector<int>> findSolution(CustomFunction &customfunction, int z)
	{
		vector<vector<int>> res;
		for (int i = 1; i <= 1000; ++i)
		{
			int lo = customfunction.f(i, 1), hi = customfunction.f(i, 1000);
			if (lo > z)
				break;
			if (hi < z)
				continue;
			lo = 1;
			hi = 1000;
			while (lo <= hi)
			{
				int mi = (hi - lo) / 2 + lo;
				int val = customfunction.f(i, mi);
				if (val == z)
				{
					res.push_back({i, mi});
					break;
				}
				if (val < z)
					lo = mi + 1;
				else
					hi = mi - 1;
			}
		}
		return res;
	}
};