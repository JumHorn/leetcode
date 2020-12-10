#include <queue>
#include <vector>
using namespace std;

/*
topological sort BFS implement
*/

class Solution
{
public:
	bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
	{
		vector<int> indegree(numCourses);
		queue<int> q; //store no parent node
		vector<vector<int>> graph(numCourses);
		for (auto &pre : prerequisites)
		{
			++indegree[pre[0]];
			graph[pre[1]].push_back(pre[0]);
		}
		for (int i = 0; i < numCourses; ++i)
		{
			if (indegree[i] == 0)
				q.push(i);
		}
		while (!q.empty())
		{
			int node = q.front();
			q.pop();
			--numCourses;
			for (auto n : graph[node])
			{
				if (--indegree[n] == 0)
					q.push(n);
			}
		}
		return numCourses == 0;
	}
};