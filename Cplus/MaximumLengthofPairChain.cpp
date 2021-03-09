#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int findLongestChain(vector<vector<int>> &pairs)
	{
		sort(pairs.begin(), pairs.end(), *this);
		int res = 1;
		for (int i = 1, j = 0; i < (int)pairs.size(); ++i)
		{
			if (pairs[i][0] > pairs[j][1])
			{
				++res;
				j = i;
			}
		}
		return res;
	}

	bool operator()(vector<int> &lhs, vector<int> &rhs)
	{
		return lhs[1] < rhs[1];
	}
};