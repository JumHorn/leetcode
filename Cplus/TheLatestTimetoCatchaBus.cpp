#include <algorithm>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	int latestTimeCatchTheBus(vector<int> &buses, vector<int> &passengers, int capacity)
	{
		sort(buses.begin(), buses.end());
		sort(passengers.begin(), passengers.end());
		int M = buses.size(), N = passengers.size();
		long long pass = 0, res = 0;
		vector<int> pre(N);
		int t = passengers[0] - 1;
		for (int i = 0; i < N;)
		{
			pre[i] = t;
			for (++i; i < N && passengers[i] - passengers[i - 1] == 1; ++i)
				pre[i] = t;
			if (i < N)
				t = passengers[i] - 1;
		}
		unordered_map<int, int> p; //{time,index}
		for (int i = 0; i < N; ++i)
			p[passengers[i]] = i;
		for (int i = 0, j = 0; i < M; ++i)
		{
			for (; j < N && passengers[j] <= buses[i]; ++j)
				++pass;
			if (pass >= capacity)
			{
				pass -= capacity;
				res = max(res, (long long)pre[j - pass - 1]);
			}
			else
			{
				if (p.count(buses[i]) == 0)
					res = buses[i];
				else
					res = max(res, (long long)pre[p[buses[i]]]);
				pass = 0;
			}
		}
		return res;
	}
};