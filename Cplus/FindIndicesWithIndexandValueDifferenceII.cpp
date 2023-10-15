#include <map>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> findIndices(vector<int> &nums, int indexDifference, int valueDifference)
	{
		int N = nums.size();
		map<int, int> m; //{val,index}
		for (int i = N - 1 - indexDifference; i >= 0; --i)
		{
			m[nums[i + indexDifference]] = i + indexDifference;
			if (abs(nums[i] - m.begin()->first) >= valueDifference)
				return {i, m.begin()->second};
			auto it = --m.end();
			if (abs(nums[i] - it->first) >= valueDifference)
				return {i, it->second};
		}
		return {-1, -1};
	}
};