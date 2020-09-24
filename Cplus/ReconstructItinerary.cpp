#include <algorithm>
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
		unordered_map<string, multiset<string>> graph;
		for (auto &ticket : tickets)
			graph[ticket[0]].insert(ticket[1]);
		vector<string> res;
		dfs(graph, "JFK", res);
		return vector<string>(res.rbegin(), res.rend());
	}

	void dfs(unordered_map<string, multiset<string>> &graph, string at, vector<string> &res)
	{
		while (!graph[at].empty())
		{
			string to = *graph[at].begin();
			graph[at].erase(graph[at].begin());
			dfs(graph, to, res);
		}
		res.push_back(at);
	}
};