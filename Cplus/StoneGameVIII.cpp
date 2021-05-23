#include <numeric>
#include <vector>
using namespace std;

class Solution
{
public:
	int stoneGameVIII(vector<int> &stones)
	{
		partial_sum(stones.begin(), stones.end(), stones.begin());
		int res = stones.back();
		for (int i = (int)stones.size() - 2; i > 0; --i)
			res = max(res, stones[i] - res);
		return res;
	}
};