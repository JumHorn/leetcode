#include <numeric>
#include <vector>
using namespace std;

class Solution
{
public:
	int numberOfPoints(vector<vector<int>> &nums)
	{
		vector<int> p(101);
		for (auto &v : nums)
		{
			for (int i = v[0]; i <= v[1]; ++i)
				p[i] = 1;
		}
		return accumulate(p.begin(), p.end(), 0);
	}
};