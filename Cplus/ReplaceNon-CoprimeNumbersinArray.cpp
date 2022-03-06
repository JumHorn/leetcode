#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> replaceNonCoprimes(vector<int> &nums)
	{
		vector<long long> res;
		long long pre = 1;
		for (auto n : nums)
		{
			long long g = gcd(n, pre);
			long long val = n / g * pre;
			if (g == 1)
				res.push_back(n);
			else
			{
				res.pop_back();
				while (!res.empty())
				{
					int last = res.back();
					int g1 = gcd(val, last);
					if (g1 == 1)
					{
						res.push_back(val);
						break;
					}
					res.pop_back();
					val = val * last / g1;
				}
				if (res.empty())
					res.push_back(val);
			}
			pre = res.back();
		}
		return vector<int>(res.begin(), res.end());
	}

	long long gcd(long long x, long long y)
	{
		return x == 0 ? y : gcd(y % x, x);
	}
};