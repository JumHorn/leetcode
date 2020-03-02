#include <map>
#include <vector>
using namespace std;

class Solution
{
public:
	bool isPossibleDivide(vector<int>& nums, int k)
	{
		int n = nums.size();
		if (n % k != 0)
			return false;
		map<int, int> m;
		for (int i = 0; i < n; i++)
			++m[nums[i]];
		while (!m.empty())
		{
			int start = m.begin()->first;
			for (int i = 0; i < k; i++)
			{
				if (m.find(start + i) == m.end())
					return false;
				if (--m[start + i] == 0)
					m.erase(start + i);
			}
		}
		return true;
	}
};
