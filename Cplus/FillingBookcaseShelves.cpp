#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

class Solution
{
public:
	int minHeightShelves(vector<vector<int>> &books, int shelf_width)
	{
		int N = books.size();
		vector<int> dp(N + 1, INT_MAX);
		dp[0] = 0;
		for (int i = 0; i < N; ++i)
		{
			int height = 0, width = 0;
			for (int j = i; j >= 0 && width + books[j][0] <= shelf_width; --j)
			{
				width += books[j][0];
				height = max(height, books[j][1]);
				dp[i + 1] = min(dp[i + 1], dp[j] + height);
			}
		}
		return dp[N];
	}
};