#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> mostCompetitive(vector<int> &nums, int k)
	{
		int N = nums.size();
		vector<int> res;
		for (int i = 0; i < N; ++i)
		{
			while (!res.empty() && (res.size() + N - i > k) && nums[i] < res.back())
				res.pop_back();
			if (res.size() < k)
				res.push_back(nums[i]);
		}
		return res;
	}
};