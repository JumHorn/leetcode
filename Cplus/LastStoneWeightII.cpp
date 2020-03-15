#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int lastStoneWeightII(vector<int> &stones)
	{
		make_heap(stones.begin(), stones.end());
		int i = stones.size() - 1;
		while (i > 0)
		{
			pop_heap(stones.begin(), stones.begin() + i + 1);
			pop_heap(stones.begin(), stones.begin() + i);
			if (stones[i] - stones[i - 1] == 0)
				i -= 2;
			else
			{
				i -= 1;
				stones[i] = stones[i + 1] - stones[i];
				push_heap(stones.begin(), stones.begin() + i + 1);
			}
		}
		return i == -1 ? 0 : stones[0];
	}
};
