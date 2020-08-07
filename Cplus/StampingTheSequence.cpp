#include <algorithm>
#include <queue>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> movesToStamp(string stamp, string target)
	{
		int M = stamp.length(), N = target.length();
		queue<int> q;
		vector<int> res;
		vector<bool> done(N);
		vector<unordered_set<int>> todo(N - M + 1);
		for (int i = 0; i <= N - M; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				if (target[i + j] != stamp[j])
					todo[i].insert(i + j);
			}
			if (todo[i].empty())
			{
				res.push_back(i);
				for (int j = i; j < i + M; ++j)
				{
					if (!done[j])
					{
						q.push(j);
						done[j] = true;
					}
				}
			}
		}

		while (!q.empty())
		{
			int i = q.front();
			q.pop();
			// For each window that is potentially affected,
			// j: start of window
			for (int j = max(0, i - M + 1); j <= min(N - M, i); ++j)
			{
				if (todo[j].find(i) != todo[j].end())
				{
					todo[j].erase(i);
					if (todo[j].empty())
					{
						res.push_back(j);
						for (int m = j; m < j + M; ++m)
						{
							if (!done[m])
							{
								q.push(m);
								done[m] = true;
							}
						}
					}
				}
			}
		}

		for (auto b : done)
		{
			if (!b)
				return {};
		}
		reverse(res.begin(), res.end());
		return res;
	}
};