#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	long long countQuadruplets(vector<int> &nums)
	{
		int N = nums.size();
		// small[j][val] index smaller than k and value smaller than val
		// big[k][val] index greater than k and value greater than val
		vector<vector<int>> small(N, vector<int>(N + 1)), big(N, vector<int>(N + 1));
		for (int k = N - 2; k >= 2; --k)
		{
			copy(big[k + 1].begin(), big[k + 1].end(), big[k].begin());
			for (int v = nums[k + 1] - 1; v >= 0; --v)
				++big[k][v];
		}
		for (int j = 1; j < N - 2; ++j)
		{
			copy(small[j - 1].begin(), small[j - 1].end(), small[j].begin());
			for (int v = nums[j - 1] + 1; v <= N; ++v)
				++small[j][v];
		}

		long long res = 0;
		for (int j = 1; j < N - 2; ++j)
		{
			for (int k = j + 1; k < N - 1; ++k)
			{
				if (nums[k] < nums[j])
					res += small[j][nums[k]] * big[k][nums[j]];
			}
		}
		return res;
	}
};