#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> goodIndices(vector<int> &nums, int k)
	{
		int N = nums.size();
		vector<int> pre(N, 1); //length of non-increasing ending at i
		vector<int> suf(N, 1); //length of non-decreasing start at i
		for (int i = 1; i < N; ++i)
		{
			if (nums[i] <= nums[i - 1])
				pre[i] = pre[i - 1] + 1;
		}

		for (int i = N - 2; i >= 0; --i)
		{
			if (nums[i] <= nums[i + 1])
				suf[i] = suf[i + 1] + 1;
		}

		vector<int> res;
		for (int i = 1; i < N - 1; ++i)
		{
			if (pre[i - 1] >= k && suf[i + 1] >= k)
				res.push_back(i);
		}
		return res;
	}
};