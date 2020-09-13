#include <vector>
using namespace std;

//for 45 and horizantal symmetry
class Solution
{
public:
	void rotate(vector<vector<int>> &matrix)
	{
		int N = matrix.size();
		//vertival flip
		for (int i = 0; i < N / 2; ++i)
		{
			for (int j = 0; j < N; ++j)
				swap(matrix[i][j], matrix[N - i - 1][j]);
		}
		//diagonal flip
		for (int i = 0; i < N - 1; ++i)
		{
			for (int j = i + 1; j < N; ++j)
				swap(matrix[i][j], matrix[j][i]);
		}
	}
};