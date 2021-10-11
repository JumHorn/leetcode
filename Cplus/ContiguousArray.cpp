#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	int findMaxLength(vector<int> &nums)
	{
		int N = nums.size(), res = 0, diff = 0; //count(1)-count(0)
		unordered_map<int, int> hash;			//{diff,index}
		hash[0] = -1;
		for (int i = 0; i < N; ++i)
		{
			nums[i] ? ++diff : --diff;
			auto it = hash.find(diff);
			if (it != hash.end())
				res = max(res, i - it->second);
			else
				hash[diff] = i;
		}
		return res;
	}
};