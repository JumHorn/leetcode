#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	int countSubarrays(vector<int> &nums, int k)
	{
		int N = nums.size(), pivot = 0;
		for (int i = 0; i < N; ++i)
		{
			if (nums[i] == k)
			{
				pivot = i;
				break;
			}
		}
		unordered_map<int, int> m; //{diff,count}
		m[0] = 1;
		int diff = 0;
		for (int i = pivot - 1; i >= 0; --i)
		{
			if (nums[i] > k)
				++diff;
			else
				--diff;
			++m[diff];
		}
		int res = m[0] + m[1];
		diff = 0;
		for (int i = pivot + 1; i < N; ++i)
		{
			if (nums[i] > k)
				++diff;
			else
				--diff;
			auto it = m.find(-diff);
			if (it != m.end())
				res += it->second;
			it = m.find(-diff + 1);
			if (it != m.end())
				res += it->second;
		}
		return res;
	}
};