#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
	int maxTaskAssign(vector<int> &tasks, vector<int> &workers, int pills, int strength)
	{
		int res = 0, N = tasks.size(), M = workers.size();
		sort(tasks.begin(), tasks.end(), greater<int>());
		sort(workers.begin(), workers.end(), greater<int>());
		priority_queue<int> q, nopill;
		for (int i = 0, j = 0; j < M && (i < N || !nopill.empty()); ++i)
		{
			while (pills > 0 && !nopill.empty() && workers[j] + strength < nopill.top())
				nopill.pop();
			if (pills > 0 && !nopill.empty() && workers[j] + strength >= nopill.top())
			{
				++res;
				q.push(workers[j]);
				++j;
				--pills;
				if (i != N)
					--i;
				continue;
			}
			if (i >= N)
				break;

			if (workers[j] >= tasks[i])
			{
				++res;
				++j;
			}
			else if (pills > 0 && workers[j] + strength >= tasks[i])
			{
				++res;
				q.push(workers[j]);
				++j;
				--pills;
			}
			else if (!q.empty() && q.top() >= tasks[i])
			{
				++pills;
				q.pop();
			}
			else
				nopill.push(tasks[i]);
		}
		return res;
	}
};