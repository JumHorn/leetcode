#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int distinctPrimeFactors(vector<int> &nums)
	{
		int res = 0;
		sort(nums.begin(), nums.end());
		vector<int> p(1000);
		for (int i = 2; i < 1000; ++i)
		{
			if (p[i] == 0)
			{
				for (int j = i; j < 1000; j += i)
					p[j] = 1;
				if (check(nums, i))
					++res;
			}
		}
		return res;
	}

	bool check(vector<int> &nums, int p)
	{
		for (auto n : nums)
		{
			if (n % p == 0)
				return true;
		}
		return false;
	}
};