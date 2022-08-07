#include <queue>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	long long taskSchedulerII(vector<int> &tasks, int space)
	{
		long long res = 0, N = tasks.size();
		queue<pair<int, long long>> q; //{tasks,finish day}
		unordered_set<int> s;		   //tasks in queue

		for (int i = 0; i < N; ++i)
		{
			if (s.count(tasks[i]) == 0)
				++res;
			else
			{
				while (q.front().first != tasks[i])
				{
					s.erase(q.front().first);
					q.pop();
				}
				res = max(space + q.front().second, res) + 1;
				s.erase(q.front().first);
				q.pop();
			}
			s.insert(tasks[i]);
			q.push({tasks[i], res});
		}
		return res;
	}
};