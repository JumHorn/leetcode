#include <climits>
#include <vector>
using namespace std;

class Solution
{
public:
	int minFallingPathSum(vector<vector<int>> &arr)
	{
		int M = arr.size(), N = arr[0].size();
		for (int i = 1; i < M; ++i)
		{
			int first = INT_MAX, second = INT_MAX, firstindex = -1;
			for (int j = 0; j < N; ++j)
			{
				if (arr[i - 1][j] < first)
				{
					second = first;
					first = arr[i - 1][j];
					firstindex = j;
				}
				else if (arr[i - 1][j] < second)
					second = arr[i - 1][j];
			}
			for (int j = 0; j < N; ++j)
				arr[i][j] += (j == firstindex ? second : first);
		}
		int res = INT_MAX;
		for (int j = 0; j < N; ++j)
			res = min(res, arr[M - 1][j]);
		return res;
	}
};