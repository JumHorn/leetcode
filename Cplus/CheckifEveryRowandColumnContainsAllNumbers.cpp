#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	bool checkValid(vector<vector<int>> &matrix)
	{
		int M = matrix.size(), N = matrix[0].size();
		for (int j = 0; j < N; ++j)
		{
			vector<int> v;
			for (int i = 0; i < M; ++i)
				v.push_back(matrix[i][j]);
			sort(v.begin(), v.end());
			int pre = 1;
			for (auto n : v)
			{
				if (n != pre)
					return false;
				++pre;
			}
		}

		for (auto &v : matrix)
		{
			sort(v.begin(), v.end());
			int pre = 1;
			for (auto n : v)
			{
				if (n != pre)
					return false;
				++pre;
			}
		}
		return true;
	}
};