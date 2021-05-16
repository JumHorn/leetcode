#include <cmath>
#include <string>
using namespace std;

class Solution
{
public:
	int minSwaps(string s)
	{
		int N = s.length(), one = 0, zero = 0;
		for (auto c : s)
			one += c - '0';
		zero = N - one;
		if (abs(zero - one) > 1)
			return -1;
		int start0 = 0, start1 = 0;
		for (int i = 0; i < N; i += 2)
		{
			if (s[i] == '0')
				++start1;
			else
				++start0;
		}
		if (one == zero)
			return min(start0, start1);
		if (one > zero)
			return start1;
		return start0;
	}
};