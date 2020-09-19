#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	bool isPrintable(vector<vector<int>> &targetGrid)
	{
		int M = targetGrid.size(), N = targetGrid[0].size();
		while (true)
		{
			unordered_set<int> turn = getTurn(targetGrid);
			if (turn.empty())
				return true;
			bool success = false;
			for (auto t : turn)
			{
				int left = N, right = 0, top = 0, bottom = M;
				for (int i = 0; i < M; ++i)
				{
					for (int j = 0; j < N; ++j)
					{
						if (targetGrid[i][j] == t)
						{
							left = min(left, j);
							right = max(right, j);
							top = max(top, i);
							bottom = min(bottom, i);
						}
					}
				}
				bool flag = true;
				for (int i = bottom; i <= top; ++i)
				{
					for (int j = left; j <= right; ++j)
					{
						if (targetGrid[i][j] != t && targetGrid[i][j] != -1)
							flag = false;
					}
				}
				if (flag)
				{
					success = true;
					color(targetGrid, t);
				}
			}
			if (success == false)
				return false;
		}
		return false;
	}

	void color(vector<vector<int>> &targetGrid, int turn)
	{
		for (auto &v : targetGrid)
		{
			for (auto &n : v)
			{
				if (n == turn)
					n = -1;
			}
		}
	}

	unordered_set<int> getTurn(vector<vector<int>> &targetGrid)
	{
		unordered_set<int> res;
		for (auto &v : targetGrid)
		{
			for (auto n : v)
			{
				if (n != -1)
					res.insert(n);
			}
		}
		return res;
	}
};