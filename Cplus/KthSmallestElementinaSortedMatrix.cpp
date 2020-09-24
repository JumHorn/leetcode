#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
	int kthSmallest(vector<vector<int>> &matrix, int k)
	{
		priority_queue<pair<int, int>> q;
		int M = matrix.size(), N = matrix[0].size();
		for (int i = 0; i < M; ++i)
			q.push({-matrix[i][0], i});
		vector<int> index(M);
		int res = 0;
		while (--k >= 0)
		{
			res = -q.top().first;
			int i = q.top().second;
			q.pop();
			if (++index[i] < N)
				q.push({-matrix[i][index[i]], i});
		}
		return res;
	}
};