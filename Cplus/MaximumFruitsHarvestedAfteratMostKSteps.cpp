#include <vector>
using namespace std;

class Solution
{
public:
	int maxTotalFruits(vector<vector<int>> &fruits, int startPos, int k)
	{
		//left first
		int left = max(startPos - k, 0), right = max(k - startPos, left);
		int N = fruits.size(), res = 0, sum = 0, i = 0, j = 0;
		while (j < N && fruits[j][0] < left)
			++j;
		for (i = j; left <= startPos; ++left, right += 2)
		{
			for (; j < N && fruits[j][0] < left; ++j)
				sum -= fruits[j][1];
			for (; i < N && fruits[i][0] <= right; ++i)
				sum += fruits[i][1];
			res = max(res, sum);
		}

		//right first
		left = startPos + k, right = left;
		sum = 0, i = N - 1, j = N - 1;
		while (j >= 0 && fruits[j][0] > right)
			--j;
		for (i = j; right >= startPos; left -= 2, --right)
		{
			for (; j >= 0 && fruits[j][0] > right; --j)
				sum -= fruits[j][1];
			for (; i >= 0 && fruits[i][0] >= left; --i)
				sum += fruits[i][1];
			res = max(res, sum);
		}

		return res;
	}
};