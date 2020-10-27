#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<int>> matrixReshape(vector<vector<int>> &nums, int r, int c)
	{
		int M = nums.size(), N = nums[0].size();
		if (M * N != r * c)
			return nums;
		vector<vector<int>> res(r, vector<int>(c));
		for (int i = 0; i < M; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				int index = i * N + j;
				res[index / c][index % c] = nums[i][j];
			}
		}
		return res;
	}
};