#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	int maxEqualFreq(vector<int> &nums)
	{
		int res = 0;
		unordered_map<int, int> count, freq;
		for (int i = 0; i < (int)nums.size(); ++i)
		{
			auto it = count.find(nums[i]);
			if (it != count.end())
			{
				int old = it->second;
				if (--freq[old] == 0)
					freq.erase(old);
			}
			++count[nums[i]];
			++freq[count[nums[i]]];
			if (freq.size() == 1)
			{
				if (count.size() == 1 || count.begin()->second == 1)
					res = i + 1;
			}
			else if (freq.size() == 2)
			{
				int a = freq.begin()->first, b = (++freq.begin())->first;
				if (((a == 1 || a - b == 1) && freq[a] == 1) ||
					((b == 1 || b - a == 1) && freq[b] == 1))
					res = i + 1;
			}
		}
		return res;
	}
};