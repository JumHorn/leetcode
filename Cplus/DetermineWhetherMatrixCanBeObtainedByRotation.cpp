#include <vector>
using namespace std;

class Solution
{
public:
	bool findRotation(vector<vector<int>> &mat, vector<vector<int>> &target)
	{
		for (int i = 0; i < 4; ++i)
		{
			mat = rotate(mat);
			if (checkEqual(mat, target))
				return true;
		}
		return false;
	}

	vector<vector<int>> rotate(vector<vector<int>> &mat)
	{
		int N = mat.size();
		vector<vector<int>> res(N, vector<int>(N));
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
				res[j][N - 1 - i] = mat[i][j];
		}
		return res;
	}

	bool checkEqual(vector<vector<int>> &mat, vector<vector<int>> &target)
	{
		int N = mat.size();
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (mat[i][j] != target[i][j])
					return false;
			}
		}
		return true;
	}
};