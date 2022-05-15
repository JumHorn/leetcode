#include <vector>
using namespace std;

class Solution
{
public:
	int largestCombination(vector<int> &candidates)
	{
		int res = 0;
		for (int i = 0; i < 30; ++i)
		{
			int count = 0;
			for (auto n : candidates)
			{
				if ((n >> i) & 1)
					++count;
			}
			res = max(res, count);
		}
		return res;
	}
};