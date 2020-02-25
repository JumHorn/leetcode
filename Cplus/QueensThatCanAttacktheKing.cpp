#include <set>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<int>> queensAttacktheKing(vector<vector<int>> &queens, vector<int> &king)
	{
		set<vector<int>> s(queens.begin(), queens.end());
		vector<vector<int>> res;
		int direction[8][2] = {{-1, -1}, {0, -1}, {1, -1}, {-1, 0}, {1, 0}, {-1, 1}, {0, 1}, {1, 1}};
		int seen[8] = {0};
		for (int i = 1; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (seen[j] == 0)
				{
					int x = king[0] + i * direction[j][0], y = king[1] + i * direction[j][1];
					if (x < 0 || x >= 8 || y < 0 || y >= 8)
					{
						seen[j] = 1;
						continue;
					}
					auto iter = s.find({x, y});
					if (iter != s.end())
					{
						res.push_back(*iter);
						seen[j] = 1;
					}
				}
			}
		}
		return res;
	}
};