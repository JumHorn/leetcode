#include <vector>
using namespace std;

class Solution
{
public:
	int maxFrequencyElements(vector<int> &nums)
	{
		vector<int> count(101);
		for (auto n : nums)
			++count[n];
		int f = 0, res = 0;
		for (auto n : count)
		{
			if (n > f)
			{
				f = n;
				res = n;
			}
			else if (f == n)
				res += n;
		}
		return res;
	}
};