#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	int evaluate(string expression)
	{
		if (expression.empty())
			return 0;
		vector<unordered_map<string, int>> variables;
		return recursion(expression, variables);
	}

	int recursion(const string expression, vector<unordered_map<string, int>> &variables)
	{
		variables.emplace_back();
		int res = 0, N = expression.length();
		for (int i = 0, j = 0; i < N; i = j)
		{
			if (expression[i] == '(')
			{
				j = matchParethesis(expression, i);
				res = recursion(expression.substr(i + 1, j - i - 1), variables);
				break;
			}
			j = jumpToSpace(expression, j);
			string exp = expression.substr(i, j - i);
			i = j = skipSpace(expression, j + 1);
			if (exp == "let")
			{
				while (j < N)
				{
					if (expression[i] == '(')
					{
						j = matchParethesis(expression, i);
						res = recursion(expression.substr(i + 1, j - i - 1), variables);
						i = j = skipSpace(expression, j + 1);
					}
					else
					{
						j = jumpToSpace(expression, j);
						string valname = expression.substr(i, j - i);
						if (j >= N - 1)
						{
							res = getVariableValue(valname, variables);
							i = j = skipSpace(expression, j + 1);
							break;
						}
						i = j = skipSpace(expression, j + 1);
						if (expression[i] == '(')
						{
							j = matchParethesis(expression, i);
							variables.back()[valname] = recursion(expression.substr(i + 1, j - i - 1), variables);
						}
						else
						{
							j = jumpToSpace(expression, j);
							variables.back()[valname] = getVariableValue(expression.substr(i, j - i), variables);
						}
						i = j = skipSpace(expression, j + 1);
					}
				}
			}
			else
			{
				int lhs, rhs;
				if (expression[i] == '(')
				{
					j = matchParethesis(expression, i);
					lhs = recursion(expression.substr(i + 1, j - i - 1), variables);
				}
				else
				{
					j = jumpToSpace(expression, j);
					lhs = getVariableValue(expression.substr(i, j - i), variables);
				}

				i = j = skipSpace(expression, j + 1);
				if (expression[i] == '(')
				{
					j = matchParethesis(expression, i);
					rhs = recursion(expression.substr(i + 1, j - i - 1), variables);
				}
				else
				{
					j = jumpToSpace(expression, j);
					rhs = getVariableValue(expression.substr(i, j - i), variables);
				}

				if (exp == "add")
					res = lhs + rhs;
				else if (exp == "mult")
					res = lhs * rhs;
				i = j = skipSpace(expression, j + 1);
			}
		}
		variables.pop_back();
		return res;
	}

	int getVariableValue(const string &variable, vector<unordered_map<string, int>> &variables)
	{
		int res = 0;
		if (isdigit(variable[0]) || variable[0] == '-')
			res = stoi(variable);
		else
		{
			for (int i = variables.size() - 1; i >= 0; --i)
			{
				if (variables[i].find(variable) != variables[i].end())
				{
					res = variables[i][variable];
					break;
				}
			}
		}
		return res;
	}

	int jumpToSpace(const string &str, int index)
	{
		index = str.find(' ', index);
		return index == -1 ? str.length() : index;
	}

	int skipSpace(const string &str, int index)
	{
		index = str.find_first_not_of(' ', index); //skip space
		return index == -1 ? str.length() : index;
	}

	int matchParethesis(const string &str, int index)
	{
		int parenthesis = 1;
		for (++index; parenthesis != 0; ++index)
		{
			if (str[index] == '(')
				++parenthesis;
			else if (str[index] == ')')
				--parenthesis;
		}
		return index - 1;
	}
};