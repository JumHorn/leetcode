#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> leftmostBuildingQueries(vector<int> &heights, vector<vector<int>> &queries)
	{
		int N = heights.size(), M = queries.size();
		for (int i = 0; i < M; ++i)
		{
			queries[i].push_back(i);
			if (queries[i][0] > queries[i][1])
				swap(queries[i][0], queries[i][1]);
		}
		sort(queries.begin(), queries.end(), [](vector<int> &lhs, vector<int> &rhs)
			 { return lhs[1] > rhs[1]; });

		vector<int> s, res(M, -1);
		for (int i = N - 1, j = 0; i >= 0 && j < M; --i)
		{
			for (; j < M && queries[j][1] >= i; ++j)
			{
				int a = queries[j][0], b = queries[j][1], index = queries[j][2];
				int lo = 0, hi = s.size();
				while (lo < hi)
				{
					int mi = (hi - lo) / 2 + lo, h = max(heights[a], heights[b]);
					if (heights[s[mi]] > h)
						lo = mi + 1;
					else
						hi = mi;
				}
				if (lo > 0)
					res[index] = s[lo - 1];
				if (a == b || heights[a] < heights[b]) // jump directly to b
					res[index] = b;
			}
			while (!s.empty() && heights[s.back()] < heights[i])
				s.pop_back();
			s.push_back(i);
		}
		return res;
	}
};