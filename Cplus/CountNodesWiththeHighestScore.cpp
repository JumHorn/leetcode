#include <vector>
using namespace std;

class Solution
{
public:
	int countHighestScoreNodes(vector<int> &parents)
	{
		int N = parents.size();
		vector<vector<int>> graph(N);
		for (int i = 1; i < N; ++i)
			graph[parents[i]].push_back(i);
		vector<int> node(N);
		nodeCount(graph, 0, node);
		long long maxscore = 1, res = 1;
		//remove 0 node
		for (auto v : graph[0])
			maxscore *= node[v];
		for (int i = 1; i < N; ++i)
		{
			long long count = N - 1, score = 1;
			for (auto v : graph[i])
			{
				count -= node[v];
				score *= node[v];
			}
			score *= count;
			if (score > maxscore)
			{
				maxscore = score;
				res = 1;
			}
			else if (score == maxscore)
				++res;
		}
		return res;
	}

	int nodeCount(vector<vector<int>> &graph, int at, vector<int> &node)
	{
		int res = 1;
		for (auto to : graph[at])
			res += nodeCount(graph, to, node);
		return node[at] = res;
	}
};