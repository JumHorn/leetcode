#include <vector>
using namespace std;

class Solution
{
public:
	vector<bool> isArraySpecial(vector<int> &nums, vector<vector<int>> &queries)
	{
		int N = nums.size();
		vector<int> prefix(N);
		for (int i = 1; i < N; ++i)
			prefix[i] = prefix[i - 1] + (nums[i] % 2 == nums[i - 1] % 2);
		vector<bool> res;
		for (auto &q : queries)
			res.push_back(prefix[q[1]] - prefix[q[0]] == 0);
		return res;
	}
};