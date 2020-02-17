#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<int>> diagonalSort(vector<vector<int>>& mat)
	{
		int m = mat.size(), n = mat[0].size();
		// m rows
		for (int i = 0; i < m; i++)
		{
			vector<int> tmp;
			int j = 0;
			while (i + j < m && j < n)
			{
				tmp.push_back(mat[i + j][j]);
				j++;
			}
			sort(tmp.begin(), tmp.end());
			for (j = 0; j < (int)tmp.size(); j++)
				mat[i + j][j] = tmp[j];
		}
		// n columns
		for (int j = 1; j < n; j++)
		{
			vector<int> tmp;
			int i = 0;
			while (i < m && i + j < n)
			{
				tmp.push_back(mat[i][i + j]);
				i++;
			}
			sort(tmp.begin(), tmp.end());
			for (i = 0; i < (int)tmp.size(); i++)
				mat[i][i + j] = tmp[i];
		}
		return mat;
	}
};
