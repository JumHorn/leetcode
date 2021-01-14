#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> numMovesStonesII(vector<int> &stones)
	{
		sort(stones.begin(), stones.end());
		int N = stones.size(), low = N;
		int high = max(stones[N - 1] - N + 2 - stones[1], stones[N - 2] - stones[0] - N + 2);
		for (int i = 0, j = 0; j < N; ++j)
		{
			while (stones[j] - stones[i] >= N)
				++i;
			if (j - i + 1 == N - 1 && stones[j] - stones[i] == N - 2)
				low = min(low, 2);
			else
				low = min(low, N - (j - i + 1));
		}
		return {low, high};
	}
};