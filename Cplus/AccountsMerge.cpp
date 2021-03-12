#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class DSU
{
public:
	string Find(const string &str)
	{
		if (parent.find(str) != parent.end() && str != parent[str])
			parent[str] = Find(parent[str]);
		else
			parent[str] = str;
		return parent[str];
	}

	bool Union(const string &x, const string &y)
	{
		string xr = Find(x), yr = Find(y);
		if (xr == yr)
			return false;
		parent[yr] = xr;
		return true;
	}

private:
	unordered_map<string, string> parent;
};

class Solution
{
public:
	vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
	{
		DSU dsu;
		unordered_map<string, string> emailToName; //{email,name}
		for (auto &account : accounts)
		{
			int N = account.size();
			for (int i = 1; i < N; ++i)
			{
				emailToName[account[i]] = account[0];
				dsu.Union(account[1], account[i]);
			}
		}
		vector<vector<string>> res;
		unordered_map<string, int> emailToIndex; //{email,index}
		for (auto iter : emailToName)
		{
			auto group = dsu.Find(iter.first);
			int index = res.size();
			if (emailToIndex.find(group) != emailToIndex.end())
				index = emailToIndex[group];
			else
				emailToIndex[group] = index;
			if (index < (int)res.size())
				res[index].push_back(iter.first);
			else
				res.push_back({iter.second, iter.first});
		}
		for (auto &account : res)
			sort(account.begin() + 1, account.end());
		return res;
	}
};