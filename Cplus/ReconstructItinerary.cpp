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
		unordered_map<string, set<string>> graph;
		vector<string> res;
		res.push_back("JFK");
		map<pair<string, string>, int> visited;
		for (auto &v : tickets)
		{
			graph[v[0]].insert(v[1]);
			++visited[{v[0], v[1]}];
		}
		dfs(graph, res, visited, tickets.size());
		return res;
	}

	bool dfs(unordered_map<string, set<string>> &graph, vector<string> &res, map<pair<string, string>, int> &visited, int n)
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
