#include <cmath>
#include <string>
using namespace std;

class Solution
{
public:
	int divisorSubstrings(int num, int k)
	{
		long base = pow(10, k), res = 0, N = to_string(num).length();
		for (int n = num, i = 0; i <= N - k; ++i, n /= 10)
		{
			int d = n % base;
			if (d != 0 && num % d == 0)
				++res;
		}
		return res;
	}
};