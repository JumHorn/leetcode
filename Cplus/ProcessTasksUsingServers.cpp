#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> assignTasks(vector<int> &servers, vector<int> &tasks)
	{
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> processq, idleq; //{time,index} ,{weight,index}
		int N = servers.size(), M = tasks.size();
		for (int i = 0; i < N; ++i)
			idleq.push({servers[i], i});
		int time = 0;
		vector<int> res;
		for (int i = 0; i < M; ++i)
		{
			if (idleq.empty())
				time = processq.top().first;
			time = max(time, i + 1);
			while (!processq.empty() && processq.top().first <= time)
			{
				idleq.push({servers[processq.top().second], processq.top().second});
				processq.pop();
			}
			res.push_back(idleq.top().second);
			processq.push({time + tasks[i], idleq.top().second});
			idleq.pop();
		}
		return res;
	}
};