#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	int numSubmatrixSumTarget(vector<vector<int>> &matrix, int target)
	{
		int res = 0, M = matrix.size(), N = matrix[0].size();
		for (int i = 0; i < M; ++i)
		{
			for (int j = 1; j < N; ++j)
				matrix[i][j] += matrix[i][j - 1];
		}
		unordered_map<int, int> m;
		for (int i = 0; i < N; ++i)
		{
			for (int j = i; j < N; ++j)
			{
				m.clear();
				m[0] = 1;
				int add = 0;
				for (int k = 0; k < M; ++k)
				{
					add += matrix[k][j] - (i > 0 ? matrix[k][i - 1] : 0);
					auto it = m.find(add - target);
					if (it != m.end())
						res += it->second;
					++m[add];
				}
			}
		}
		return res;
	}
};