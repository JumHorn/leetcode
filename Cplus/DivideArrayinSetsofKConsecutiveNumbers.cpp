#include <map>
#include <vector>
using namespace std;

class Solution
{
public:
	bool isPossibleDivide(vector<int> &nums, int k)
	{
		int N = nums.size();
		if (N % k != 0)
			return false;
		map<int, int> m;
		for (auto n : nums)
			++m[n];
		while (!m.empty())
		{
			int start = m.begin()->first, count = m.begin()->second;
			for (int i = 0; i < k; ++i)
			{
				m[start + i] -= count;
				if (m[start + i] < 0)
					return false;
				if (m[start + i] == 0)
					m.erase(start + i);
			}
		}
		return true;
	}
};