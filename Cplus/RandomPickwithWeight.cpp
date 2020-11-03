#include <cmath>
#include <vector>
using namespace std;

class Solution
{
public:
	Solution(vector<int> &w) : prefixsum(w.size() + 1)
	{
		for (int i = 0; i < (int)w.size(); ++i)
			prefixsum[i + 1] = prefixsum[i] + w[i];
		count = prefixsum.back();
		prefixsum.push_back(INT_MAX);
	}

	int pickIndex()
	{
		int pick = rand() % count + 1;
		int lo = 0, hi = prefixsum.size() - 1;
		while (lo < hi)
		{
			int mi = (hi - lo) / 2 + lo;
			if (pick > prefixsum[mi])
				lo = mi + 1;
			else
				hi = mi;
		}
		return lo - 1;
	}

private:
	vector<int> prefixsum;
	int count;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */