#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int minimumLines(vector<vector<int>> &stockPrices)
	{
		sort(stockPrices.begin(), stockPrices.end());
		int res = 0, N = stockPrices.size();
		if (N <= 2)
			return N - 1;
		for (int i = 1; i < N - 1; ++i)
		{
			if (isInALine(stockPrices[i - 1], stockPrices[i], stockPrices[i + 1])) //not in a line
				++res;
		}
		return res + 1;
	}

	bool isInALine(vector<int> &point0, vector<int> &point1, vector<int> &point2)
	{
		return (long long)(point0[0] - point1[0]) * (point0[1] - point2[1]) !=
			   (long long)(point0[0] - point2[0]) * (point0[1] - point1[1]);
	}
};