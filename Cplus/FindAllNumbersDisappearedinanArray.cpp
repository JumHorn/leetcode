#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> findDisappearedNumbers(vector<int> &nums)
	{
		int N = nums.size();
		for (int i = 0; i < N;)
		{
			if (i + 1 == nums[i] || nums[nums[i] - 1] == nums[i])
				++i;
			else
				swap(nums[nums[i] - 1], nums[i]);
		}
		vector<int> res;
		for (int i = 0; i < N; ++i)
		{
			if (i + 1 != nums[i])
				res.push_back(i + 1);
		}
		return res;
	}
};