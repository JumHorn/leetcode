#include <vector>
using namespace std;

class Solution
{
public:
	int maxStudents(vector<vector<char>>& seats)
	{
		vector<pair<int, int>> good;
		for (int i = 0; i < (int)seats.size(); i++)
		{
			for (int j = 0; j < (int)seats[i].size(); j++)
			{
				if (seats[i][j] == '.')
					good.push_back({i, j});
			}
		}
		int n = good.size();
		vector<vector<int>> dp(n, vector<int>(2));
		dp[0][0] = 0;
		dp[0][1] = 1;
		for (int i = 1; i < n; i++)
		{
			int row = good[i].first, column = good[i].second;
			if (row == 0)  //first row
			{
				int take = 1;
				if (column - 1 >= 0)
				{
					if (seats[row][column - 1])
					{
					}
				}
			}
			else
			{
			}
		}
		return max(dp[n - 1][0], dp[n - 1][1]);
	}
};
