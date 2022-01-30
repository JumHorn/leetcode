#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> maxScoreIndices(vector<int> &nums)
	{
		int zero = 0, one = 0;
		for (auto n : nums)
		{
			if (n == 1)
				++one;
		}
		int sum = one, minsum = one;
		vector<int> res = {0};
		for (int i = 0; i < (int)nums.size(); ++i)
		{
			if (nums[i] == 0)
				++zero;
			else
				--one;
			if (sum == one + zero)
				res.push_back(i + 1);
			else if (sum < one + zero)
			{
				sum = one + zero;
				res = {i + 1};
			}
		}
		return res;
	}
};