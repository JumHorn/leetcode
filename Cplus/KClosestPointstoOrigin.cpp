#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<int>> kClosest(vector<vector<int>> &points, int K)
	{
		priority_queue<pair<int, int>> q;
		for (int i = 0; i < (int)points.size(); ++i)
			q.push({-(points[i][0] * points[i][0] + points[i][1] * points[i][1]), i});
		vector<vector<int>> res(K);
		for (int i = 0; i < K; ++i)
		{
			res[i] = points[q.top().second];
			q.pop();
		}
		return res;
	}
};