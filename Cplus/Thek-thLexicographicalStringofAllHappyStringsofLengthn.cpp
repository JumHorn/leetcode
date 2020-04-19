#include <string>
using namespace std;

class Solution
{
public:
	string getHappyString(int n, int k)
	{
		string res(n, 'a');
		if (dfs(res, 0, n, k))
			return res;
		return "";
	}

	bool dfs(string &res, int index, int n, int &k)
	{
		if (index >= n)
			return --k == 0;
		for (char c = 'a'; c <= 'c'; ++c)
		{
			if (index != 0 && c == res[index - 1])
				continue;
			res[index] = c;
			if (dfs(res, index + 1, n, k))
				return true;
		}
		return false;
	}
};