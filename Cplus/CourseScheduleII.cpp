#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
	{
		vector<int> res, indegree(numCourses);
		queue<int> q; //store no parent node
		vector<vector<int>> graph(numCourses);
		for (auto &pre : prerequisites)
		{
			++indegree[pre[0]];
			graph[pre[1]].push_back(pre[0]);
		}
		for (int i = 0; i < numCourses; i++)
		{
			if (indegree[i] == 0)
				q.push(i);
		}
		while (!q.empty())
		{
			int node = q.front();
			q.pop();
			res.push_back(node);
			for (auto n : graph[node])
			{
				if (--indegree[n] == 0)
					q.push(n);
			}
		}
		return (int)res.size() == numCourses ? res : vector<int>();
	}
};