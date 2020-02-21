#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> numMovesStonesII(vector<int> &stones)
	{
		int n = stones.size();
		int minimum_moves = n, maximum_moves = 0;
		sort(stones.begin(), stones.end());
		for (int i = 2; i < n - 1; i++)
			maximum_moves += stones[i] - stones[i - 1] - 1;
		maximum_moves += max(stones[1] - stones[0], stones[n - 1] - stones[n - 2]) - 1;
		int end = stones[0] + n;
		for (int i = 0, j = 0; i < n;)
		{
			if (stones[i] < end)
			{
				if (stones[i] - stones[j] + 1 == n - 1 && i - j + 1 == n - 1)
					minimum_moves = min(minimum_moves, 2);
				else
					minimum_moves = min(minimum_moves, n - (i - j + 1));
				i++;
			}
			else
				end = stones[++j] + n;
		}
		return {minimum_moves, maximum_moves};
	}
};