#include <queue>
#include <set>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> busiestServers(int k, vector<int> &arrival, vector<int> &load)
	{
		//{last load,server id}
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
		vector<int> server(k); //server request count
		set<int> s;			   //free serverid
		for (int i = 0; i < k; ++i)
			s.insert(i);
		int maxcount = 0;
		for (int i = 0; i < (int)arrival.size(); ++i)
		{
			while (!q.empty() && q.top().first <= arrival[i])
			{
				s.insert(q.top().second);
				q.pop();
			}
			if (s.empty())
				continue;
			int id = *s.begin();
			auto iter = s.lower_bound(i % k);
			if (iter != s.end())
			{
				id = *iter;
				s.erase(iter);
			}
			else
				s.erase(s.begin());
			maxcount = max(maxcount, ++server[id]);
			q.push({arrival[i] + load[i], id});
		}
		vector<int> res;
		for (int i = 0; i < k; ++i)
		{
			if (server[i] == maxcount)
				res.push_back(i);
		}
		return res;
	}
};