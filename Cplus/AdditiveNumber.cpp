#include <algorithm>
#include <string>
using namespace std;

class Solution
{
public:
	bool isAdditiveNumber(string num)
	{
		int N = num.size();
		for (int i = 1; i <= (N - 1) / 2; ++i)
		{
			if (i > 1 && num[0] == '0')
				break;
			for (int j = i + 1; j <= (N + i) / 2; ++j)
			{
				if (num[i] == '0' && j - i > 1)
					break;
				if (check(num, j, num.substr(0, i), num.substr(i, j - i)))
					return true;
			}
		}
		return false;
	}

	bool check(const string &num, int index, const string &num1, const string &num2)
	{
		if (index >= (int)num.size())
			return true;
		string res = add(num1, num2);
		if (num.compare(index, res.size(), res) != 0)
			return false;
		return check(num, index + res.size(), num2, res);
	}

	string add(const string &num1, const string &num2)
	{
		string res;
		int i = num1.size(), j = num2.size(), carry = 0;
		for (--i, --j; i >= 0 || j >= 0 || carry != 0; --i, --j)
		{
			int a = 0, b = 0;
			if (i >= 0)
				a = num1[i] - '0';
			if (j >= 0)
				b = num2[j] - '0';
			a += b + carry;
			res.push_back(a % 10 + '0');
			carry = a / 10;
		}
		reverse(res.begin(), res.end());
		return res;
	}
};