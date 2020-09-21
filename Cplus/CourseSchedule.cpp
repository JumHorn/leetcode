#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
	{
		vector<int> done(numCourses), seen(numCourses);
		vector<vector<int>> graph(numCourses);
		for (auto &pre : prerequisites)
			graph[pre[0]].push_back(pre[1]);
		for (int i = 0; i < numCourses; ++i)
		{
			if (done[i] == 0 && !dfs(graph, i, seen, done))
				return false;
		}
		return true;
	}

	bool dfs(vector<vector<int>> &graph, int at, vector<int> &seen, vector<int> &done)
	{
		if (seen[at] == 1)
			return false;
		if (done[at] == 1)
			return true;
		done[at] = seen[at] = 1;
		for (int i = 0; i < (int)graph[at].size(); i++)
		{
			if (!dfs(graph, graph[at][i], seen, done))
				return false;
		}
		seen[at] = 0;
		return true;
	}
};