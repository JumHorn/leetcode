#include <string>
using namespace std;

class Solution
{
public:
	string fractionAddition(string expression)
	{
		int a = 0, b = 1, c, d, i = 0, n = expression.size();
		bool symbol = true;
		while (i < n)
		{
			bool flag = true;
			if (expression[i] == '-')
			{
				i++;
				flag = false;
			}
			int j = i;
			while (expression[j] != '/')
				j++;
			c = stoi(expression.substr(i, j - i));
			i = ++j;
			while (j < n && expression[j] != '+' && expression[j] != '-')
				j++;
			d = stoi(expression.substr(i, j - i));
			i = j;
			if (flag && symbol)
			{
				int tmp0 = a * d + b * c, tmp1 = b * d, tmp2 = gcd(tmp0, tmp1);
				a = tmp0 / tmp2, b = tmp1 / tmp2;
			}
			else if (!flag && !symbol)
			{
				int tmp0 = a * d + b * c, tmp1 = b * d, tmp2 = gcd(tmp0, tmp1);
				a = tmp0 / tmp2, b = tmp1 / tmp2;
				symbol = false;
			}
			else if (flag && !symbol)
			{
				int tmp0 = -a * d + b * c, tmp1 = b * d, tmp2;
				symbol = (tmp0 >= 0);
				if (!symbol)
					tmp0 = -tmp0;
				tmp2 = gcd(tmp0, tmp1);
				a = tmp0 / tmp2, b = tmp1 / tmp2;
			}
			else
			{
				int tmp0 = a * d - b * c, tmp1 = b * d, tmp2;
				symbol = (tmp0 >= 0);
				if (!symbol)
					tmp0 = -tmp0;
				tmp2 = gcd(tmp0, tmp1);
				a = tmp0 / tmp2, b = tmp1 / tmp2;
			}
		}
		if (symbol)
			return to_string(a) + "/" + to_string(b);
		else
			return "-" + to_string(a) + "/" + to_string(b);
	}

	int gcd(int x, int y)
	{
		if (x == 0)
			return y;
		return gcd(y % x, x);
	}
};