#include <vector>
#include <queue>
#include <set>
using namespace std;

class Solution
{
public:
	int minRefuelStops(int target, int startFuel, vector<vector<int>> &stations)
	{
		priority_queue<int> q;
		int res = 0, N = stations.size();
		for (int i = 0; startFuel < target; ++res)
		{
			while (i < N && startFuel >= stations[i][0])
				q.push(stations[i++][1]);

			if (q.empty())
				return -1;
			startFuel += q.top();
			q.pop();
		}
		return res;
	}
};