#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
	int eliminateMaximum(vector<int> &dist, vector<int> &speed)
	{
		priority_queue<double, vector<double>, greater<double>> q;
		int N = dist.size();
		for (int i = 0; i < N; ++i)
			q.push(dist[i] * 1.0 / speed[i]);
		int time = 0, res = 0;
		while (!q.empty() && time < q.top())
		{
			q.pop();
			++res;
			++time;
		}
		return res;
	}
};