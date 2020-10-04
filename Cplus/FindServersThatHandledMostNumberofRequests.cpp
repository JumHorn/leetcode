#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> busiestServers(int k, vector<int> &arrival, vector<int> &load)
	{
		vector<pair<int, int>> v(k); //{last load,count}
		int maxcount = 0;
		for (int i = 0; i < (int)arrival.size(); ++i)
		{
			for (int j = i; j - i < (int)arrival.size(); ++j)
			{
				int server = j % k;
				if (v[server].first <= arrival[i])
				{
					maxcount = max(maxcount, ++v[server].second);
					v[server].first = arrival[i] + load[i];
					break;
				}
			}
		}
		vector<int> res;
		for (int i = 0; i < k; ++i)
		{
			if (v[i].second == maxcount)
				res.push_back(i);
		}
		return res;
	}
};