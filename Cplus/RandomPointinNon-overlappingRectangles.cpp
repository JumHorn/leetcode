#include <cmath>
#include <vector>
using namespace std;

class Solution
{
public:
	Solution(vector<vector<int>> &rects) : prefixsum(rects.size() + 1), m_rects(rects)
	{
		for (int i = 0; i < (int)rects.size(); ++i)
			prefixsum[i + 1] = prefixsum[i] + (rects[i][3] - rects[i][1] + 1) * (rects[i][2] - rects[i][0] + 1);
		maxpoint = prefixsum.back();
	}

	vector<int> pick()
	{
		int r = rand() % maxpoint, lo = 0, hi = prefixsum.size();
		while (lo < hi)
		{
			int mi = (hi - lo) / 2 + lo;
			if (prefixsum[mi] <= r)
				lo = mi + 1;
			else
				hi = mi;
		}
		r -= prefixsum[lo - 1];
		int side = m_rects[lo - 1][2] - m_rects[lo - 1][0] + 1;
		return {m_rects[lo - 1][0] + r % side, m_rects[lo - 1][1] + r / side};
	}

private:
	vector<int> prefixsum;
	vector<vector<int>> m_rects;
	int maxpoint;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */