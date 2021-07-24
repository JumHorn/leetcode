#include <algorithm>
#include <queue>
#include <set>
#include <vector>
using namespace std;

class Solution
{
public:
	int smallestChair(vector<vector<int>> &times, int targetFriend)
	{
		int N = times.size();
		set<int> chair;
		for (int i = 0; i < N; ++i)
		{
			times[i].push_back(i); //store friend id
			chair.insert(i);
		}
		sort(times.begin(), times.end());
		int t = 0;
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q; //{leave time,seat id}
		for (int i = 0; i < N; ++i)
		{
			t = times[i][0];
			while (!q.empty() && t >= q.top().first)
			{
				chair.insert(q.top().second);
				q.pop();
			}
			int seat = *chair.begin();
			chair.erase(seat);
			q.push({times[i][1], seat});
			if (times[i][2] == targetFriend)
				return seat;
		}
		return -1;
	}
};