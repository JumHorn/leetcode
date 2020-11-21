#include <cmath>
#include <string>
using namespace std;

class Solution
{
public:
	bool isRationalEqual(string S, string T)
	{
		pair<int, int> s = rationalTofraction(S);
		pair<int, int> t = rationalTofraction(T);
		return s == t;
	}

	pair<int, int> rationalTofraction(const string &s)
	{
		int integer, nonrepeat, repeat, base = 0, i = 0, j = 0, N = s.length();
		j = s.find('.', j);
		if (j == string::npos)
			j = N;
		integer = stoi(s.substr(i, j - i));
		if (j >= N)
			return {integer, 1};

		i = ++j;
		j = s.find('(', j);
		if (j == string::npos)
			j = N;
		if (i == j)
			nonrepeat = 0;
		else
			nonrepeat = stoi(s.substr(i, j - i));
		base += j - i;
		long dividend = nonrepeat + integer * pow(10, j - i);

		int divider;
		if (j + 1 >= N)
		{
			divider = pow(10, base);
			int g = gcd(dividend, divider);
			return {dividend / g, divider / g};
		}

		i = ++j;
		j = s.find(')', j);
		if (j == string::npos)
			j = N;
		repeat = stoi(s.substr(i, j - i));
		dividend = dividend * pow(10, j - i) + repeat - dividend;
		divider = pow(10, base + j - i) - pow(10, base);
		int g = gcd(dividend, divider);
		return {dividend / g, divider / g};
	}

	int gcd(long x, long y)
	{
		return x == 0 ? y : gcd(y % x, x);
	}
};