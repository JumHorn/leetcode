#include <string>
#include <unordered_set>
using namespace std;

class Solution
{
public:
	int maxUniqueSplit(string s)
	{
		unordered_set<string> uset;
		int res = 0;
		dfs(s, 0, uset, res);
		return res;
	}

	void dfs(string& s, int index, unordered_set<string>& uset, int& res)
	{
		int N = s.length();
		if (index >= N)
			res = max(res, (int)uset.size());
		for (int i = index; i < N; ++i)
		{
			string str = s.substr(index, i - index + 1);
			if (uset.find(str) == uset.end())
			{
				uset.insert(str);
				dfs(s, i + 1, uset, res);
				uset.erase(str);
			}
		}
	}
};
