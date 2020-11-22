#include <algorithm>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<string> braceExpansionII(string expression)
	{
		auto strset = recursive(expression, 0, expression.length());
		vector<string> res(strset.begin(), strset.end());
		sort(res.begin(), res.end());
		return res;
	}

	unordered_set<string> recursive(const string &expr, int start, int end)
	{
		if (start >= end)
			return {};
		unordered_set<string> res;
		while (start < end)
		{
			if (expr[start] == ',')
			{
				res = add(res, recursive(expr, start + 1, end));
				break;
			}

			if (expr[start] == '{')
			{
				while (start < end && expr[start] == '{')
				{
					int i = start + 1;
					for (int count = 1; count != 0; ++i)
					{
						if (expr[i] == '{')
							++count;
						else if (expr[i] == '}')
							--count;
					}
					res = product(res, recursive(expr, start + 1, i - 1));
					start = i;
				}
			}
			else
			{
				int i = start;
				while (i < end && expr[i] != '{' && expr[i] != ',')
					++i;
				unordered_set<string> s;
				string val = expr.substr(start, i - start);
				s.insert(val);
				if (i == end || expr[i] == ',')
				{
					res = product(res, s);
					start = i;
				}
				else if (expr[i] == '{')
				{
					int j = i + 1;
					for (int count = 1; count != 0; ++j)
					{
						if (expr[j] == '{')
							++count;
						else if (expr[j] == '}')
							--count;
					}
					auto tmp = recursive(expr, i + 1, j - 1);
					res = product(res, s);
					res = product(res, tmp);
					start = j;
				}
			}
		}
		return res;
	}

	unordered_set<string> add(const unordered_set<string> &lhs, const unordered_set<string> &rhs)
	{
		unordered_set<string> res;
		for (auto &n : lhs)
			res.insert(n);
		for (auto &m : rhs)
			res.insert(m);
		return res;
	}

	unordered_set<string> product(const unordered_set<string> &lhs, const unordered_set<string> &rhs)
	{
		if (lhs.empty())
			return rhs;
		if (rhs.empty())
			return lhs;
		unordered_set<string> res;
		for (auto &n : lhs)
		{
			for (auto &m : rhs)
				res.insert(n + m);
		}
		return res;
	}
};