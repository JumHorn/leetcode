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
		vector<int> dp(n, INT_MAX);
		return recursive(books, dp, 0, 0, shelf_width, 0, 0);
	}

	int recursive(vector<vector<int>> &books, vector<int> &dp, int index, int width, int shelf_width, int height, int allheight)
	{
		int n = books.size();
		if (index >= n)
			return allheight;
		// if (dp[index] != INT_MAX)
		// 	return dp[index];
		int res = INT_MAX;
		if (books[index][0] + width <= shelf_width)
		{
			int tmp = height;
			if (books[index][1] > height)
				tmp = books[index][1];
			res = min(res, recursive(books, dp, index + 1, books[index][0] + width, shelf_width, tmp, allheight + tmp - height));
		}
		res = min(res, recursive(books, dp, index + 1, books[index][0], shelf_width, books[index][1], allheight + books[index][1]));
		// dp[index] = res;
		return res;
	}
};