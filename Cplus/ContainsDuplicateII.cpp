#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	bool containsNearbyDuplicate(vector<int> &nums, int k)
	{
		int N = nums.size();
		if (++k > N)
			k = N;
		unordered_set<int> s(nums.begin(), nums.begin() + k);
		if (s.size() != k)
			return true;
		for (int i = k; i < N; ++i)
		{
			s.erase(nums[i - k]);
			s.insert(nums[i]);
			if (s.size() != k)
				return true;
		}
		return false;
	}
};