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
	vector<string> watchedVideosByFriends(vector<vector<string>> &watchedVideos, vector<vector<int>> &friends, int id, int level)
	{
		vector<bool> seen(friends.size());
		queue<int> q;
		seen[id] = true;
		q.push(id);
		while (!q.empty() && --level >= 0)
		{
			int size = q.size();
			while (--size >= 0)
			{
				int node = q.front();
				q.pop();
				for (auto n : friends[node])
				{
					if (!seen[n])
					{
						seen[n] = true;
						q.push(n);
					}
				}
			}
		}
		map<string, int> m; //{video ,freq}
		while (!q.empty())
		{
			for (auto &video : watchedVideos[q.front()])
				++m[video];
			q.pop();
		}
		map<int, set<string>> video; //{freq,video}
		for (auto &n : m)
			video[n.second].insert(n.first);
		vector<string> res;
		for (auto &v : video)
		{
			for (auto &s : v.second)
				res.push_back(s);
		}
		return res;
	}
};