#include <vector>
using namespace std;

class NumMatrix
{
public:
	NumMatrix(vector<vector<int>> &matrix)
	{
		if (matrix.empty() || matrix[0].empty())
			return;
		int M = matrix.size(), N = matrix[0].size();
		m_matrix = vector<vector<int>>(M + 1, vector<int>(N + 1));
		for (int i = 0; i < M; ++i)
		{
			for (int j = 0; j < N; ++j)
				m_matrix[i + 1][j + 1] = m_matrix[i + 1][j] + m_matrix[i][j + 1] - m_matrix[i][j] + matrix[i][j];
		}
	}

	int sumRegion(int row1, int col1, int row2, int col2)
	{
		return m_matrix[row2 + 1][col2 + 1] - m_matrix[row2 + 1][col1] - m_matrix[row1][col2 + 1] + m_matrix[row1][col1];
	}

private:
	vector<vector<int>> m_matrix;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */