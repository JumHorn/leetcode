#include <climits>
#include <queue>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<int>> matrixRankTransform(vector<vector<int>> &matrix)
	{
		int M = matrix.size(), N = matrix[0].size();
		vector<vector<int>> res(M, vector<int>(N));
		priority_queue<pair<int, int>> q;								//{value,pos}
		vector<vector<int>> row(M, {INT_MAX, 1}), col(N, {INT_MAX, 1}); //{value,rank}
		for (int i = 0; i < M; ++i)
		{
			for (int j = 0; j < N; ++j)
				q.push({-matrix[i][j], i * N + j});
		}
		while (!q.empty())
		{
			int x = q.top().second / N, y = q.top().second % N;
			int value = -q.top().first;
			q.pop();
			int rowrank = row[x][1] + (value <= row[x][0] ? 0 : 1);
			int colrank = col[y][1] + (value <= col[y][0] ? 0 : 1);
			res[x][y] = max(rowrank, colrank);
			row[x][0] = col[y][0] = value;
			row[x][1] = col[y][1] = res[x][y];
		}
		return res;
	}
};