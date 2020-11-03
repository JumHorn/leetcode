#include <cmath>
#include <string>
using namespace std;

class Solution
{
public:
	string smallestGoodBase(string n)
	{
		unsigned long long S = stoll(n);
		int max_m = log2(S);
		for (int m = max_m; m >= 2; m--)
		{
			int k = pow(S, 1.0 / m);
			unsigned long long sum = 1, prod = 1;
			for (int i = 0; i < m; ++i)
				sum += (prod *= k);
			if (sum == S)
				return to_string(k);
		}
		return to_string(S - 1);
	}
};