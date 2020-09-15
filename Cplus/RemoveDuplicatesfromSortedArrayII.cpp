#include <climits>
#include <vector>
using namespace std;

class Solution
{
public:
	int removeDuplicates(vector<int> &nums)
	{
		int continuous = 0, res = 0;
		for (int i = 0, pre = INT_MIN; i < (int)nums.size(); pre = nums[i++])
		{
			nums[i] == pre ? ++continuous : (continuous = 1);
			if (continuous <= 2)
				nums[res++] = nums[i];
		}
		return res;
	}
};