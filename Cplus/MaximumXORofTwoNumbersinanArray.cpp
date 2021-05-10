#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	int findMaximumXOR(vector<int> &nums)
	{
		int res = 0, mask = 0;
		for (int i = 31; i >= 0; --i)
		{
			mask |= 1 << i;
			unordered_set<int> s;
			for (auto n : nums)
				s.insert(n & mask);
			int maxval = (res | 1 << i);
			for (auto n : s)
			{
				int another = n ^ maxval;
				if (s.find(another) != s.end())
				{
					res = maxval;
					break;
				}
			}
		}
		return res;
	}
};