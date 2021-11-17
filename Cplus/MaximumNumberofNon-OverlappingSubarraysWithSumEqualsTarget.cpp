#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	int maxNonOverlapping(vector<int> &nums, int target)
	{
		unordered_set<int> s;
		int N = nums.size(), prefixsum = 0, res = 0;
		s.insert(0);
		for (int i = 0; i < N; ++i)
		{
			prefixsum += nums[i];
			if (s.find(prefixsum - target) != s.end())
			{
				++res;
				s.clear();
				s.insert(0);
				prefixsum = 0;
			}
			else
				s.insert(prefixsum);
		}
		return res;
	}
};