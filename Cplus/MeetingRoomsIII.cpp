#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
	int mostBooked(int n, vector<vector<int>> &meetings)
	{
		sort(meetings.begin(), meetings.end());
		priority_queue<pair<long, int>, vector<pair<long, int>>, greater<pair<long, int>>> busy; //{not avaliable time,room id}
		priority_queue<int, vector<int>, greater<int>> idle;									 //avaliable meeting id;
		vector<int> count(n);
		for (int i = 0; i < n; ++i)
			idle.push(i);
		for (auto &m : meetings)
		{
			while (!busy.empty() && busy.top().first <= m[0])
			{
				idle.push(busy.top().second);
				busy.pop();
			}
			long id = 0, t = 0;
			if (idle.empty())
			{
				long time = busy.top().first;
				id = busy.top().second;
				busy.pop();
				t = time + m[1] - m[0];
			}
			else
			{
				id = idle.top();
				idle.pop();
				t = m[1];
			}
			++count[id];
			busy.push({t, id});
		}

		int res = 0;
		for (int i = 0; i < n; ++i)
		{
			if (count[res] < count[i])
				res = i;
		}
		return res;
	}
};