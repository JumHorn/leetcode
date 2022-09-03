#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	bool findSubarrays(vector<int> &nums)
	{
		unordered_set<int> s;
		int N = nums.size();
		for (int i = 0; i < N - 1; ++i)
		{
			int sum = nums[i] + nums[i + 1];
			if (s.count(sum) != 0)
				return true;
			s.insert(sum);
		}
		return false;
	}
};