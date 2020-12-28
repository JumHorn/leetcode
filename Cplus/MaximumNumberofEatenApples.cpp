#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
	int eatenApples(vector<int> &apples, vector<int> &days)
	{
		int N = apples.size();
		int res = 0, day = 0;
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q; //{rot day,count}
		for (int i = 0; i < N || !q.empty(); ++i)
		{
			if (i < N && apples[i] > 0)
				q.push({i + days[i], apples[i]});
			while (!q.empty() && q.top().first <= day)
				q.pop();
			if (!q.empty())
			{
				++res;
				auto top = q.top();
				q.pop();
				if (--top.second > 0)
					q.push(top);
			}
			++day;
		}
		return res;
	}
};