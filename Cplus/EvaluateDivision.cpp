#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
	typedef unordered_map<string, unordered_map<string, double>> GRAPH;

public:
	vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
	{
		GRAPH graph;
		for (int i = 0; i < (int)equations.size(); ++i)
		{
			graph[equations[i][0]][equations[i][1]] = values[i];
			graph[equations[i][1]][equations[i][0]] = 1.0 / values[i];
		}
		vector<double> res(queries.size(), 1.0);
		for (int i = 0; i < (int)queries.size(); ++i)
		{
			if (graph.find(queries[i][0]) == graph.end() || graph.find(queries[i][1]) == graph.end())
			{
				res[i] = -1.0;
				continue;
			}
			unordered_set<string> seen = {queries[i][0]};
			if (!backTracking(graph, seen, queries[i][0], queries[i][1], res[i]))
				res[i] = -1.0;
		}
		return res;
	}

	bool backTracking(GRAPH &graph, unordered_set<string> &seen, const string &src, const string &dst, double &value)
	{
		if (src == dst)
			return true;
		for (auto &iter : graph[src])
		{
			if (seen.find(iter.first) == seen.end())
			{
				seen.insert(iter.first);
				value *= iter.second;
				if (backTracking(graph, seen, iter.first, dst, value))
					return true;
				value /= iter.second;
				seen.erase(iter.first);
			}
		}
		return false;
	}
};