#include <string>
#include <cmath>
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
		while (j < N && s[j] != '.')
			++j;
		integer = stoi(s.substr(i, j - i));
		i = ++j;
		if (i >= N)
			return {integer, 1};
		while (j < N && s[j] != '(')
			++j;
		if (j - i == 0)
			nonrepeat = 0;
		else
			nonrepeat = stoi(s.substr(i, j - i));
		base += j - i;
		long dividend = nonrepeat + integer * pow(10, j - i);
		int divider, tmp;
		if (j + 1 >= N)
		{
			divider = pow(10, base);
			tmp = gcd(dividend, divider);
			return {dividend / tmp, divider / tmp};
		}
		i = ++j;
		while (s[j] != ')')
			j++;
		repeat = stoi(s.substr(i, j - i));
		dividend = dividend * pow(10, j - i) + repeat - dividend;
		divider = pow(10, base + j - i) - pow(10, base);
		tmp = gcd(dividend, divider);
		return {dividend / tmp, divider / tmp};
	}

	int gcd(long x, long y)
	{
		if (x == 0)
			return y;
		return gcd(y % x, x);
	}
};