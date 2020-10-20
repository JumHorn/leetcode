#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))

int minHeightShelves(int** books, int booksSize, int* booksColSize, int shelf_width)
{
	int dp[booksSize + 1];
	memset(dp, 1 << 6, sizeof(dp));
	dp[0] = 0;
	for (int i = 0; i < booksSize; ++i)
	{
		int height = 0, width = 0;
		for (int j = i; j >= 0 && width + books[j][0] <= shelf_width; --j)
		{
			width += books[j][0];
			height = max(height, books[j][1]);
			dp[i + 1] = min(dp[i + 1], dp[j] + height);
		}
	}
	return dp[booksSize];
}
