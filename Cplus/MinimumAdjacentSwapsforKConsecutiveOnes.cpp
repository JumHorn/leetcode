#include <climits>
#include <vector>
using namespace std;

// https://leetcode-cn.com/problems/minimum-adjacent-swaps-for-k-consecutive-ones/solution/de-dao-lian-xu-k-ge-1-de-zui-shao-xiang-lpa9i/

class Solution
{
public:
	int minMoves(vector<int> &nums, int k)
	{
		int N = nums.size();
		vector<int> prefixsum = {0}, pos; //{pos - index}
		int count = -1;
		for (int i = 0; i < N; ++i)
		{
			if (nums[i] == 1)
			{
				++count;
				pos.push_back(i - count);
				prefixsum.push_back(prefixsum.back() + pos.back());
			}
		}

		int M = pos.size(), res = INT_MAX;
		for (int i = 0; i + k <= M; ++i)
		{
			int mid = (i + i + k - 1) / 2;
			int q = pos[mid];
			res = min(res, (2 * (mid - i) - k + 1) * q + (prefixsum[i + k] - prefixsum[mid + 1]) - (prefixsum[mid] - prefixsum[i]));
		}
		return res;
	}
};