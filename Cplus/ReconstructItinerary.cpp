#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<string> findItinerary(vector<vector<string>> &tickets)
	{
		unordered_map<int, set<int>> graph;
		vector<int> res;
		map<pair<int, int>, int> visited;
		unordered_map<string, int> m;
		set<string> s;
		for (auto &v : tickets)
		{
			s.insert(v[0]);
			s.insert(v[1]);
		}
		vector<string> pos(s.begin(), s.end());
		for (int i = 0; i < (int)pos.size(); i++)
			m[pos[i]] = i;
		res.push_back(m["JFK"]);
		for (auto &v : tickets)
		{
			graph[m[v[0]]].insert(m[v[1]]);
			++visited[{m[v[0]], m[v[1]]}];
		}
		dfs(graph, res, visited, tickets.size());
		vector<string> res1(res.size());
		for (int i = 0; i < (int)res.size(); i++)
			res1[i] = pos[res[i]];
		return res1;
	}

	bool dfs(unordered_map<int, set<int>> &graph, vector<int> &res, map<pair<int, int>, int> &visited, int n)
	{
		if (n == 0)
			return true;
		for (auto &t : graph[res.back()])
		{
			if (visited.find({res.back(), t}) != visited.end() && visited[{res.back(), t}] > 0)
			{
				--visited[{res.back(), t}];
				res.push_back(t);
				if (dfs(graph, res, visited, n - 1))
					return true;
				res.pop_back();
				++visited[{res.back(), t}];
			}
		}
		return false;
	}
};
