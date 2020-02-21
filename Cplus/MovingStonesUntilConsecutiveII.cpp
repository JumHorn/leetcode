#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> numMovesStonesII(vector<int> &stones)
	{
		vector<int> res(2);
		sort(stones.begin(), stones.end());
		int n = stones.size();
		for (int i = 2; i < n - 1; i++)
			res[1] += stones[i] - stones[i - 1] - 1;
		res[1] += max(stones[1] - stones[0], stones[n - 1] - stones[n - 2]) - 1;
		int i = 0, j = n - 1, move = 0, gap = 0;
		while (i < j)
		{
			if (stones[j] - stones[i] == n - 1)
				break;
			if (stones[j] - stones[i] < n - 1)
			{
				move += (gap >= 2 ? 1 : 0);
				break;
			}
			if (stones[j] - stones[j - 1] > stones[i + 1] - stones[i])
			{
				gap = stones[j] - stones[j - 1] - 1;
				j--;
			}
			else
			{
				gap = stones[i + 1] - stones[i] - 1;
				i++;
			}
			move++;
		}
		res[0] = move;
		return res;
	}
};