#include <vector>
using namespace std;

class Solution
{
public:
	int firstCompleteIndex(vector<int> &arr, vector<vector<int>> &mat)
	{
		int M = mat.size(), N = mat[0].size();
		vector<pair<int, int>> index(M * N + 1);
		for (int i = 0; i < M; ++i)
		{
			for (int j = 0; j < N; ++j)
				index[mat[i][j]] = {i, j};
		}
		vector<int> row(M), col(N);
		for (int i = 0; i < arr.size(); ++i)
		{
			int x = index[arr[i]].first, y = index[arr[i]].second;
			if (++row[x] == N)
				return i;
			if (++col[y] == M)
				return i;
		}
		return -1;
	}
};