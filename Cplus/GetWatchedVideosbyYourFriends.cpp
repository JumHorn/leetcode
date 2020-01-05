#include <map>
#include <set>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level)
	{
		unordered_set<int> visited;
		set<int> levelfriends;
		visited.insert(id);
		dfs(friends, id, level, visited, levelfriends);
		map<string, int> m;
		for (auto n : levelfriends)
		{
			for (auto v : watchedVideos[n])
				m[v]++;
		}
		map<int, set<string>> tmp;
		for (auto n : m)
			tmp[n.second].insert(n.first);
		vector<string> res;
		for (auto n : tmp)
			for (auto s : n.second)
				res.push_back(s);
		return res;
	}

	void dfs(vector<vector<int>>& friends, int id, int level, unordered_set<int>& visited, set<int>& res)
	{
		if (level == 0)
		{
			res.insert(id);
			return;
		}

		for (int i = 0; i < (int)friends[id].size(); i++)
		{
			if (visited.find(friends[id][i]) == visited.end())
			{
				visited.insert(friends[id][i]);
				dfs(friends, friends[id][i], level - 1, visited, res);
			}
		}
	}
};
