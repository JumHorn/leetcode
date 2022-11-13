#include <algorithm>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	int distinctAverages(vector<int> &nums)
	{
		sort(nums.begin(), nums.end());
		unordered_set<double> s;
		int N = nums.size();
		for (int i = 0, j = N - 1; i < j; ++i, --j)
			s.insert((nums[i] + nums[j]) / 2.0);
		return s.size();
	}
};