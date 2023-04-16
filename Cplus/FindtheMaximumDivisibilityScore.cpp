#include <vector>
using namespace std;

class Solution
{
public:
	int maxDivScore(vector<int> &nums, vector<int> &divisors)
	{
		vector<int> r;
		for (auto d : divisors)
		{
			int count = 0;
			for (auto n : nums)
			{
				if (n % d == 0)
					++count;
			}
			r.push_back(count);
		}
		int d = 0;
		for (int i = 1; i < r.size(); ++i)
		{
			if ((r[i] > r[d]) || (r[i] == r[d] && divisors[i] < divisors[d]))
				d = i;
		}
		return divisors[d];
	}
};