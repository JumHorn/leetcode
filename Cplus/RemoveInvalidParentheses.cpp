#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<string> removeInvalidParentheses(string s)
	{
		int invalid_open = 0, invalid_closed = 0, count = 0;
		for (auto c : s)
		{
			if (c == '(')
				++count;
			else if (c == ')')
			{
				if (count > 0)
					--count;
				else
					++invalid_closed;
			}
		}
		invalid_open = count;

		unordered_set<string> res;
		string possible;
		dfs(res, possible, 0, invalid_open, invalid_closed, s, 0);
		return vector<string>(res.begin(), res.end());
	}

	void dfs(unordered_set<string> &res, string &possible, int count, int open, int closed, const string &s, int index)
	{
		if (open < 0 || closed < 0 || count < 0)
			return;
		if (index > (int)s.length())
		{
			if (open == 0 && closed == 0 && count == 0)
				res.insert(possible);
			return;
		}
		if (open == 0 && closed == 0)
		{
			if (isValid(s, index, count))
				res.insert(possible + s.substr(index));
			return;
		}
		if (s[index] == '(')
		{
			dfs(res, possible, count, open - 1, closed, s, index + 1);
			possible.push_back('(');
			dfs(res, possible, count + 1, open, closed, s, index + 1);
			possible.pop_back();
		}
		else if (s[index] == ')')
		{
			dfs(res, possible, count, open, closed - 1, s, index + 1);
			possible.push_back(')');
			dfs(res, possible, count - 1, open, closed, s, index + 1);
			possible.pop_back();
		}
		else
		{
			possible.push_back(s[index]);
			dfs(res, possible, count, open, closed, s, index + 1);
			possible.pop_back();
		}
	}

	bool isValid(const string &s, int index, int count)
	{
		for (int i = index; i < (int)s.length(); ++i)
		{
			if (s[i] == '(')
				++count;
			else if (s[i] == ')')
			{
				--count;
				if (count < 0)
					return false;
			}
		}
		return count == 0;
	}
};