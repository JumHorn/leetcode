#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<string> addOperators(string num, int target)
	{
		vector<string> res;
		dfs(num, 0, target, 0, 0, "", res);
		return res;
	}

	void dfs(string &num, int index, int target, long cur, long pre, string instance, vector<string> &res)
	{
		int N = num.length();
		if (index >= N)
		{
			if (cur == target)
				res.push_back(instance);
			return;
		}
		string sub;
		for (int i = index; i < N; ++i)
		{
			sub.push_back(num[i]);
			long n = stol(sub);
			if (index == 0)
				dfs(num, i + 1, target, n, n, sub, res);
			else
			{
				dfs(num, i + 1, target, cur + n, n, instance + "+" + sub, res);
				dfs(num, i + 1, target, cur - n, -n, instance + "-" + sub, res);
				dfs(num, i + 1, target, cur - pre + n * pre, n * pre, instance + "*" + sub, res);
			}
			if (num[index] == '0')
				break;
		}
	}
};