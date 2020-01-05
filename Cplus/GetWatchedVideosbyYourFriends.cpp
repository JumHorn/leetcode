#include <map>
#include <queue>
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
		vector<bool> visited(friends.size(), false);
		queue<int> q;
		visited[id] = true;
		q.push(id);
		while (!q.empty() && level > 0)
		{
			level--;
			int size = q.size();
			while (--size >= 0)
			{
				int tmp = q.front();
				q.pop();
				for (auto n : friends[tmp])
				{
					if (!visited[n])
					{
						q.push(n);
						visited[n] = true;
					}
				}
			}
		}
		map<string, int> m;
		while (!q.empty())
		{
			for (auto v : watchedVideos[q.front()])
				m[v]++;
			q.pop();
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
};

