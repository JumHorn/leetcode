#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
	string crackSafe(int n, int k)
	{
		unordered_set<string> seen;
		string node(n - 1, '0'), res;
		dfs(node, k, seen, res);
		return res + node;
	}

	void dfs(string &node, int k, unordered_set<string> &seen, string &res)
	{
		for (int i = 0; i < k; i++)
		{
			node.push_back('0' + i);
			if (seen.find(node) == seen.end())
			{
				seen.insert(node);
				string next = node.substr(1);
				dfs(next, k, seen, res);
				res.push_back('0' + i);
			}
			node.pop_back();
		}
	}
};