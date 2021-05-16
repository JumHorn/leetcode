#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<char>> rotateTheBox(vector<vector<char>> &box)
	{
		int M = box.size(), N = box[0].size();
		for (int i = 0; i < M; ++i)
		{
			int count = 0;
			for (int j = N - 1; j >= 0; --j)
			{
				if (box[i][j] == '.')
					++count;
				else if (box[i][j] == '*')
					count = 0;
				else if (box[i][j] == '#' && count > 0)
				{
					box[i][j] = '.';
					box[i][j + count] = '#';
				}
			}
		}

		vector<vector<char>> res(N, vector<char>(M));
		for (int i = 0; i < M; ++i)
		{
			for (int j = 0; j < N; ++j)
				res[j][M - i - 1] = box[i][j];
		}
		return res;
	}
};