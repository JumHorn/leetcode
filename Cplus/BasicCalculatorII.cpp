#include <sstream>
#include <string>
using namespace std;

class Solution
{
public:
	int calculate(string s)
	{
		stringstream ss(s);
		int res, pre, val;
		char op;
		ss >> res;
		pre = res;
		while (ss >> op)
		{
			ss >> val;
			if (op == '+')
				pre = val;
			else if (op == '-')
				pre = -val;
			else if (op == '*')
			{
				res -= pre;
				pre *= val;
			}
			else // '/'
			{
				res -= pre;
				pre /= val;
			}
			res += pre;
		}
		return res;
	}
};