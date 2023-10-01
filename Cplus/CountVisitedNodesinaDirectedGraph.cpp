#include <functional>
#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> countVisitedNodes(vector<int> &edges)
	{
		int N = edges.size();
		vector<int> res(N), time(N);
		for (int i = 0, clock = 1; i < N; ++i)
		{
			if (time[i])
				continue;
			for (int x = i, start_time = clock; x >= 0; x = edges[x])
			{
				if (time[x]) // repeat visited
				{
					if (time[x] >= start_time)
					{
						// set to ring size
						int ring = clock - time[x];
						for (int t = x; res[t] == 0; t = edges[t])
							res[t] = ring;
						break;
					}
				}
				time[x] = clock++;
			}
		}

		function<int(int)> dfs = [&](int at)
		{
			if (res[at] != 0)
				return res[at];
			return res[at] = dfs(edges[at]) + 1;
		};

		for (int i = 0; i < N; ++i)
			dfs(i);

		return res;
	}
};