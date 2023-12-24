#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> numberGame(vector<int> &nums)
	{
		sort(nums.begin(), nums.end());
		int N = nums.size();
		vector<int> res;
		for (int i = 0; i < N; i += 2)
		{
			res.push_back(nums[i + 1]);
			res.push_back(nums[i]);
		}
		return res;
	}
};