#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	int largestValsFromLabels(vector<int> &values, vector<int> &labels, int num_wanted, int use_limit)
	{
		priority_queue<pair<int, int>> q;
		unordered_map<int, int> m; //{label,label count}
		for (int i = 0; i < (int)values.size(); ++i)
			q.push({values[i], labels[i]});
		int res = 0;
		while (!q.empty() && num_wanted > 0)
		{
			if (++m[q.top().second] <= use_limit)
			{
				res += q.top().first;
				--num_wanted;
			}
			q.pop();
		}
		return res;
	}
};