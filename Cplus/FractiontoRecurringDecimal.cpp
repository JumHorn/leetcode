#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	string fractionToDecimal(int numerator, int denominator)
	{
		int sign = 1;
		long num = numerator, de = denominator;
		if (numerator < 0)
		{
			sign *= -1;
			num = numerator;
			num = -num;
		}
		if (denominator < 0)
		{
			sign *= -1;
			de = denominator;
			de = -de;
		}
		long devidend = num / de;
		long q = num % de;
		string res;
		if (numerator != 0 && sign == -1)
			res = "-";
		res += to_string(devidend);
		if (q == 0)
			return res;
		res += '.';
		vector<int> decimal;
		unordered_map<int, int> m;
		while (m.find(q) == m.end())
		{
			m[q] = decimal.size();
			q *= 10;
			decimal.push_back(q / de);
			q %= de;
			if (q == 0)
			{
				for (auto n : decimal)
					res += to_string(n);
				return res;
			}
		}
		for (int i = 0; i < m[q]; ++i)
			res += to_string(decimal[i]);
		res += '(';
		for (int i = m[q]; i < (int)decimal.size(); ++i)
			res += to_string(decimal[i]);
		res += ')';
		return res;
	}
};