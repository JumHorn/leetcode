#include <algorithm>
#include <cctype>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
	struct comp
	{
		bool operator()(const string &lhs, const string &rhs) const
		{
			int count1 = count(lhs.begin(), lhs.end(), '*');
			int count2 = count(rhs.begin(), rhs.end(), '*');
			if (count1 != count2)
				return count1 > count2;
			return lhs < rhs;
		}
	};

public:
	vector<string> basicCalculatorIV(string expression, vector<string> &evalvars, vector<int> &evalints)
	{
		unordered_map<string, int> evalmap;
		for (int i = 0; i < (int)evalvars.size(); ++i)
			evalmap[evalvars[i]] = evalints[i];
		map<string, int, comp> current;
		map<string, int, comp> pre;
		calculatorDFS(expression, 0, expression.length(), current, pre, evalmap);
		vector<string> res;
		mapToResult(current, res);
		return res;
	}

	map<string, int, comp> calculatSub(string expression, unordered_map<string, int> evalmap)
	{
		map<string, int, comp> current;
		map<string, int, comp> pre;
		calculatorDFS(expression, 0, expression.length(), current, pre, evalmap);
		return current;
	}

	void calculatorDFS(const string &expression, int start, int end, map<string, int, comp> &current, map<string, int, comp> &pre, unordered_map<string, int> &evalmap)
	{
		string symbol = "+";
		int i = start, j = start;
		while (i < end)
		{
			map<string, int, comp> val;
			while (i < end && expression[i] == ' ')
				++i;
			if (isdigit(expression[i]))
			{
				j = i + 1;
				while (j < end && isdigit(expression[j]))
					++j;
				val[""] = stoi(expression.substr(i, j - i));
				calcuMap(current, pre, val, symbol);
				i = j + 1;
			}
			else if (expression[i] == '(')
			{
				j = matchParenthesis(expression, i);
				val = calculatSub(expression.substr(i + 1, j - i - 1), evalmap);
				calcuMap(current, pre, val, symbol);
				i = j + 1;
			}
			else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*')
				symbol = expression[i++];
			else
			{
				j = i + 1;
				while (j < end && isalpha(expression[j]))
					++j;
				string tmp = expression.substr(i, j - i);
				if (evalmap.find(tmp) == evalmap.end())
					val[tmp] = 1;
				else
					val[""] = evalmap[tmp];
				calcuMap(current, pre, val, symbol);
				i = j + 1;
			}
		}
	}

	void mapToResult(map<string, int, comp> &val, vector<string> &res)
	{
		for (auto &n : val)
			if (n.first != "")
				res.push_back(to_string(n.second) + string("*") + n.first);
		if (val.find("") != val.end())
			res.push_back(to_string(val[""]));
	}

	void calcuMap(map<string, int, comp> &current, map<string, int, comp> &pre, map<string, int, comp> &val, const string &symbol)
	{
		if (symbol == "+")
		{
			addMap(current, val);
			map<string, int, comp> tmp;
			tmp[""] = -1;
			multMap(val, tmp);
			pre = val;
		}
		else if (symbol == "-")
		{
			minusMap(current, val);
			map<string, int, comp> tmp;
			pre = val;
		}
		else if (symbol == "*")
		{
			addMap(current, pre);
			multMap(pre, val);
			minusMap(current, pre);
		}
	}

	int matchParenthesis(const string &str, int index)
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

	void addMap(map<string, int, comp> &lhs, map<string, int, comp> &rhs)
	{
		for (auto &n : rhs)
		{
			lhs[n.first] += n.second;
			if (lhs[n.first] == 0)
				lhs.erase(n.first);
		}
	}

	void minusMap(map<string, int, comp> &lhs, map<string, int, comp> &rhs)
	{
		for (auto &n : rhs)
		{
			lhs[n.first] -= n.second;
			if (lhs[n.first] == 0)
				lhs.erase(n.first);
		}
	}

	void multMap(map<string, int, comp> &lhs, map<string, int, comp> &rhs)
	{
		map<string, int, comp> res;
		for (auto &n : rhs)
		{
			if (n.second != 0)
			{
				for (auto &m : lhs)
				{
					string key = sortKey(m.first, n.first);
					res[key] += m.second * n.second;
				}
			}
		}
		lhs = res;
	}

	string sortKey(const string &s1, const string &s2)
	{
		if (s1.empty())
			return s2;
		if (s2.empty())
			return s1;
		map<string, int> valmap;
		int i = 0, j = 0;
		while (i < (int)s1.length())
		{
			j = i + 1;
			while (j < (int)s1.length() && s1[j] != '*')
				++j;
			++valmap[s1.substr(i, j - i)];
			i = j + 1;
		}
		i = 0;
		while (i < (int)s2.length())
		{
			j = i + 1;
			while (j < (int)s2.length() && s2[j] != '*')
				++j;
			++valmap[s2.substr(i, j - i)];
			i = j + 1;
		}
		string res;
		for (auto &n : valmap)
		{
			for (int i = 0; i < n.second; ++i)
				res += "*" + n.first;
		}
		return res.substr(1);
	}
};