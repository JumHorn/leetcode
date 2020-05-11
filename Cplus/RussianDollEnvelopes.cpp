#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
	int maxEnvelopes(vector<vector<int>> &envelopes)
	{
		vector<int> LIS;
		sort(envelopes.begin(), envelopes.end(), *this);
		for (auto envelope : envelopes)
		{
			auto iter = lower_bound(LIS.begin(), LIS.end(), envelope[1]);
			if (iter == LIS.end())
				LIS.push_back(envelope[1]);
			else
				*iter = envelope[1];
		}
		return LIS.size();
	}

	bool operator()(vector<int> &lhs, vector<int> &rhs)
	{
		if (lhs[0] != rhs[0])
			return lhs[0] < rhs[0];
		return lhs[1] >= rhs[1];
	}
};