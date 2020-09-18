#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int minimumTotal(vector<vector<int>> &triangle)
	{
		int N = triangle.size();
		if (triangle.empty())
			return 0;
		if (N == 1)
			return triangle[0][0];
		for (int i = 1; i < N; ++i)
		{
			triangle[i][0] += triangle[i - 1][0];
			triangle[i][triangle[i].size() - 1] += triangle[i - 1][triangle[i - 1].size() - 1];
		}
		for (int i = 2; i < N; ++i)
		{
			for (int j = 1; j < triangle[i].size() - 1; ++j)
				triangle[i][j] += min(triangle[i - 1][j], triangle[i - 1][j - 1]);
		}
		return *min_element(triangle.back().begin(), triangle.back().end());
	}
};