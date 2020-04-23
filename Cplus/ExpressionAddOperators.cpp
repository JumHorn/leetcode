#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
	vector<string> addOperators(string num, int target)
	{
		vector<string> res;
		string sub;
		for (int i = 0; i < (int)num.length(); i++)
		{
			sub.push_back(num[i]);
			long n = stol(sub);
			dfs(res, sub, num, i + 1, n, n, target);
			if (num[0] == '0')
				break;
		}
		return res;
	}

	void dfs(vector<string> &res, string exp, string &num, int index, long cur, long pre, long target)
	{
		if (index >= (int)num.length())
		{
			if (cur == target)
				res.push_back(exp);
			return;
		}
		string sub;
		for (int i = index; i < (int)num.length(); i++)
		{
			sub.push_back(num[i]);
			int n = stol(sub);
			dfs(res, exp + "+" + sub, num, i + 1, cur + n, n, target);
			dfs(res, exp + "-" + sub, num, i + 1, cur - n, -n, target);
			dfs(res, exp + "*" + sub, num, i + 1, cur - pre + n * pre, n * pre, target);
			if (num[index] == '0')
				break;
		}
	}
};