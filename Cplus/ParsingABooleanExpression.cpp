#include <string>
using namespace std;

class Solution
{
public:
	bool parseBoolExpr(string expression)
	{
		return parseBoolExpr(expression, 0, expression.length());
	}

	bool parseBoolExpr(const string &expression, int left, int right)
	{
		bool res = true;
		if (expression[left] == '!')
			res = !parseBoolExpr(expression, left + 2, right - 1);
		else if (expression[left] == '&')
		{
			int i = left + 2, j = left + 2;
			while (j < right)
			{
				j = skipParenthsis(expression, i, right);
				res = parseBoolExpr(expression, i, j);
				if (!res)
					break;
				i = ++j;
			}
		}
		else if (expression[left] == '|')
		{
			int i = left + 2, j = left + 2;
			while (j < right)
			{
				j = skipParenthsis(expression, i, right);
				res = parseBoolExpr(expression, i, j);
				if (res)
					break;
				i = ++j;
			}
		}
		else
			res = expression[left] == 't';
		return res;
	}

	int skipParenthsis(const string &expression, int left, int right)
	{
		int parenthsis = 0, j = left;
		while (j < right)
		{
			if (expression[j] == '(')
				parenthsis++;
			else if (expression[j] == ')')
				parenthsis--;
			else if (expression[j] == ',' && parenthsis == 0)
				break;
			j++;
		}
		return j;
	}
};