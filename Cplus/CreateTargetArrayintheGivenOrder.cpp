#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> createTargetArray(vector<int> &nums, vector<int> &index)
	{
		vector<int> res;
		for (int i = 0; i < (int)nums.size(); ++i)
			res.insert(res.begin() + index[i], nums[i]);
		return res;
	}
};