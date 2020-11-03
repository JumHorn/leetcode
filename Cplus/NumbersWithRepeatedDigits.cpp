#include <cmath>
#include <string>
#include <unordered_set>
using namespace std;

class Solution
{
public:
	int numDupDigitsAtMostN(int N)
	{
		string num = to_string(N + 1);
		int len = num.length(), res = 0;
		for (int i = 1; i < len; ++i)
			res += 9 * A(i - 1, 9);
		unordered_set<char> s;
		s.insert(num[0]);
		res += (num[0] - '1') * A(len - 1, 9);
		for (int i = 1; i < len; ++i)
		{
			for (char c = '0'; c < num[i]; c++)
				if (s.find(c) == s.end())
					res += A(len - i - 1, 10 - i - 1);
			if (s.find(num[i]) != s.end())
				break;
			s.insert(num[i]);
		}
		return N - res;
	}

	int A(int m, int n) //arrangment
	{
		if (m == 0)
			return 1;
		if (m == 1)
			return n;
		return (n - m + 1) * A(m - 1, n);
	}
};