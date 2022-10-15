#include <numeric>
#include <vector>
using namespace std;

class Solution
{
public:
	int componentValue(vector<int> &nums, vector<vector<int>> &edges)
	{
		int N = nums.size(), sum = accumulate(nums.begin(), nums.end(), 0);
		vector<vector<int>> tree(N);
		for (auto &edge : edges)
		{
			tree[edge[0]].push_back(edge[1]);
			tree[edge[1]].push_back(edge[0]);
		}

		for (int val = 1; val <= sum; ++val)
		{
			if (sum % val == 0 && postorder(tree, nums, -1, 0, val) != -1)
				return sum / val - 1;
		}
		return 0;
	}

	int postorder(vector<vector<int>> &tree, vector<int> &nums, int from, int at, int x)
	{
		int sum = nums[at];
		for (auto &to : tree[at])
		{
			if (to != from)
			{
				int res = postorder(tree, nums, at, to, x);
				if (res == -1)
					return -1;
				sum += res;
			}
		}
		if (sum > x)
			return -1;
		return sum % x;
	}
};