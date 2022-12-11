#include <vector>
using namespace std;

class Solution
{
public:
	int maxJump(vector<int> &stones)
	{
		int res = 0, N = stones.size();
		if (N <= 3)
			return stones[N - 1] - stones[0];
		res = max(res, stones[1] - stones[0]);
		res = max(res, stones[2] - stones[0]);
		for (int i = 3; i < N - 1; i += 2)
		{
			res = max(res, stones[i] - stones[i - 2]);
			res = max(res, stones[i + 1] - stones[i - 1]);
		}
		res = max(res, stones[N - 1] - stones[N - 2]);
		res = max(res, stones[N - 1] - stones[N - 3]);
		return res;
	}
};