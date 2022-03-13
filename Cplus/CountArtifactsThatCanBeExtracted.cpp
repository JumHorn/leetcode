#include <vector>
using namespace std;

class Solution
{
public:
	int digArtifacts(int n, vector<vector<int>> &artifacts, vector<vector<int>> &dig)
	{
		vector<vector<int>> grid(n, vector<int>(n));
		for (auto &v : dig)
			grid[v[0]][v[1]] = 1;
		int res = 0;
		for (auto &v : artifacts)
		{
			bool flag = true;
			for (int i = v[0]; i <= v[2] && flag; ++i)
			{
				for (int j = v[1]; j <= v[3] && flag; ++j)
				{
					if (grid[i][j] == 0)
						flag = false;
				}
			}
			if (flag)
				++res;
		}
		return res;
	}
};