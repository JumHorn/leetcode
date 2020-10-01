#include <cctype>
#include <sstream>
#include <string>
using namespace std;

/*
generate a standard formular with x be 1x and 0x must be before every =
*/

class Solution
{
public:
	string solveEquation(string equation)
	{
		int coefficient = 0, y = 0, val = 0, sign = 1;
		stringstream ss;
		for (int i = 0; i < (int)equation.size(); ++i)
		{
			if (equation[i] == 'x' && (i == 0 || !isdigit(equation[i - 1])))
				ss << '1';
			else if (equation[i] == '=')
				ss << "+0x";
			ss << equation[i];
		}
		while (ss.peek() == '=' || ss >> val)
		{
			char c = ss.peek();
			if (c == 'x')
			{
				coefficient += val * sign;
				ss >> c;
			}
			else if (c == '=')
			{
				sign = -1;
				ss >> c;
			}
			else
				y += val * sign;
		}
		if (coefficient == 0)
			return y == 0 ? "Infinite solutions" : "No solution";
		return "x=" + to_string(-y / coefficient);
	}
};