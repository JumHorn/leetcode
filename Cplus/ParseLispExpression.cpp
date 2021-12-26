#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	int evaluate(string expression)
	{
		variables.clear();
		vector<string> tokens = {""};
		stack<vector<string>> stk;
		for (auto c : expression)
		{
			if (c == '(')
			{
				variables.emplace_back();
				if (tokens[0] == "let")
					calculate(tokens);
				stk.push(tokens);
				tokens = {""};
			}
			else if (c == ')')
			{
				string val = calculate(tokens);
				variables.pop_back();
				tokens = stk.top();
				stk.pop();
				tokens.back() += val;
			}
			else if (c == ' ')
				tokens.push_back("");
			else
				tokens.back().push_back(c);
		}
		return stoi(getVariable(tokens[0]));
	}

	string calculate(vector<string> &tokens)
	{
		auto &db = variables.back(); //variable database
		if (tokens[0] == "let")
		{
			for (int i = 1; i < (int)tokens.size() - 1; i += 2)
			{
				if (!tokens[i + 1].empty())
					db[tokens[i]] = getVariable(tokens[i + 1]);
			}
			return getVariable(tokens.back());
		}

		// add/mult
		int a = stoi(getVariable(tokens[1])), b = stoi(getVariable(tokens[2]));
		return (tokens[0] == "add") ? to_string(a + b) : to_string(a * b);
	}

	string getVariable(const string &var)
	{
		if (isdigit(var[0]) || var[0] == '-')
			return var;
		for (int i = (int)variables.size() - 1; i >= 0; --i)
		{
			auto it = variables[i].find(var);
			if (it != variables[i].end())
				return it->second;
		}
		return var;
	}

private:
	vector<unordered_map<string, string>> variables;
};