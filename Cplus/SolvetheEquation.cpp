#include <cctype>
#include <string>
using namespace std;

class Solution
{
public:
	string solveEquation(string equation)
	{
		int coefficient = 0, val = 0, flag = 1, i = 0, n = equation.length();
		while (i < n)
		{
			if (equation[i] == '=')
			{
				flag = -1;
				i++;
			}
			else if (equation[i] == '+')
			{
				i++;
			}
			else if (equation[i] == '-')
			{
				int j = ++i;
				while (j < n && isdigit(equation[j]))
					j++;
				if (j < n && equation[j] == 'x')
				{
					if (j == i)
						coefficient -= flag;
					else
						coefficient -= flag * stoi(equation.substr(i, j - i));
					i = j + 1;
				}
				else
				{
					val -= flag * stoi(equation.substr(i, j - i));
					i = j;
				}
			}
			else
			{
				int j = i;
				while (j < n && isdigit(equation[j]))
					j++;
				if (j < n && equation[j] == 'x')
				{
					if (j == i)
						coefficient += flag;
					else
						coefficient += flag * stoi(equation.substr(i, j - i));
					i = j + 1;
				}
				else
				{
					val += flag * stoi(equation.substr(i, j - i));
					i = j;
				}
			}
		}
		if (coefficient == 0)
			return val == 0 ? "Infinite solutions" : "No solution";
		return "x=" + to_string(-val / coefficient);
	}
};