#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<string> simplifiedFractions(int n)
	{
		vector<string> res;
		for (int i = 2; i <= n; ++i)
		{
			for (int j = 1; j < i; ++j)
			{
				if (gcd(j, i) == 1)
					res.push_back(to_string(j) + "/" + to_string(i));
			}
		}
		return res;
	}

	int gcd(int x, int y)
	{
		return x == 0 ? y : gcd(y % x, x);
	}
};
