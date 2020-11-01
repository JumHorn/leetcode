#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
	{
		priority_queue<pair<int, int>> q;
		for (int i = 0; i < (int)mat.size(); ++i)
		{
			int j = 0;
			while (j < (int)mat[i].size() && mat[i][j] == 1)
				++j;
			q.push({-j, -i});
		}
		vector<int> res;
		for (int i = 0; i < k; ++i)
		{
			res.push_back(-q.top().second);
			q.pop();
		}
		return res;
	}
};