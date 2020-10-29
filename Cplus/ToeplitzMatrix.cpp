#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	bool isToeplitzMatrix(vector<vector<int>> &matrix)
	{
		unordered_map<int, int> m;
		int M = matrix.size(), N = matrix[0].size();
		for (int i = 0; i < M; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (m.find(i - j) == m.end())
					m[i - j] = matrix[i][j];
				else if (m[i - j] != matrix[i][j])
					return false;
			}
		}
		return true;
	}
};