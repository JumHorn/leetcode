#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
	int lastStoneWeight(vector<int> &stones)
	{
		priority_queue<int> q(stones.begin(), stones.end());
		while (q.size() > 1u)
		{
			int first = q.top();
			q.pop();
			int second = q.top();
			q.pop();
			if (first - second > 0)
				q.push(first - second);
		}
		return q.empty() ? 0 : q.top();
	}
};