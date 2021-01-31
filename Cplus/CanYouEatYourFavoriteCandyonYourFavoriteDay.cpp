#include <vector>
using namespace std;

class Solution
{
public:
	vector<bool> canEat(vector<int> &candiesCount, vector<vector<int>> &queries)
	{
		vector<bool> res;
		int N = candiesCount.size();
		vector<int> prefixsum(N + 1);
		for (int i = 0; i < N; ++i)
			prefixsum[i + 1] += prefixsum[i] + candiesCount[i];
		for (auto &q : queries)
		{
			res.push_back(false);
			if (prefixsum[q[0] + 1] < q[1] + 1) //false
				continue;
			if ((long)q[2] * (q[1] + 1) > prefixsum[q[0]])
				res.back() = true;
		}
		return res;
	}
};