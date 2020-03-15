#include <algorithm>
#include <set>
#include <vector>
using namespace std;

class Solution
{
public:
	int lastStoneWeightII(vector<int> &stones)
	{
		set<int> dp = {stones[0], -stones[0]};
		for (int i = 1; i < (int)stones.size(); i++)
		{
			set<int> tmp;
			for (auto n : dp)
			{
				tmp.insert(abs(n - stones[i]));
				tmp.insert(n + stones[i]);
			}
			dp = tmp;
		}
		return *dp.begin();
	}
};
