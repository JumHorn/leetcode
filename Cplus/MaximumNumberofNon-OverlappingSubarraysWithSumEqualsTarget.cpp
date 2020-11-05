#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	int maxNonOverlapping(vector<int> &nums, int target)
	{
		unordered_set<int> m;
		int N = nums.size(), prefixsum = 0, res = 0;
		m.insert(0);
		for (int i = 0; i < N; ++i)
		{
			prefixsum += nums[i];
			if (m.find(prefixsum - target) != m.end())
			{
				++res;
				m.clear();
				m.insert(0);
				prefixsum = 0;
			}
			else
				m.insert(prefixsum);
		}
		return res;
	}
};