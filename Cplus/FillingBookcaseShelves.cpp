#include <algorithm>
#include <climits>
#include <numeric>
#include <vector>
using namespace std;

class Solution
{
public:
	int minHeightShelves(vector<vector<int>> &books, int shelf_width)
	{
		int n = books.size();
		if (n == 1)
			return books[0][1];
		vector<int> dp(n + 1, INT_MAX);
		dp[n] = 0;
		dp[n - 1] = books[n - 1][1];
		if (books[n - 1][0] + books[n - 2][0] <= shelf_width)
			dp[n - 2] = max(books[n - 1][1], books[n - 2][1]);
		else
			dp[n - 2] = books[n - 1][1] + books[n - 2][1];
		for (int i = n - 3; i >= 0; i--)
		{
			int height = 0, width = 0;
			for (int j = i; j < n; j++)
			{
				width += books[j][0];
				if (width > shelf_width)
					break;
				height = max(height, books[j][1]);
				dp[i] = min(dp[i], height + dp[j + 1]);
			}
		}
		return dp[0];
	}
};
