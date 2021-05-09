#include <vector>
using namespace std;

class Solution
{
public:
	int maximumPopulation(vector<vector<int>> &logs)
	{
		int res = 0, p = 0;
		for (int i = 1950; i <= 2050; ++i)
		{
			int count = 0;
			for (auto &log : logs)
			{
				if (log[0] <= i && log[1] > i)
					++count;
			}
			if (count > p)
			{
				p = count;
				res = i;
			}
		}
		return res;
	}
};