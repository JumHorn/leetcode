#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	int findMaxLength(vector<int> &nums)
	{
		int res = 0, diff = 0; //count(1)-count(0)
		unordered_map<int, int> hash;
		hash[0] = -1;
		for (int i = 0; i < (int)nums.size(); ++i)
		{
			nums[i] ? ++diff : --diff;
			if (hash.find(diff) != hash.end())
				res = max(res, i - hash[diff]);
			else
				hash[diff] = i;
		}
		return res;
	}
};