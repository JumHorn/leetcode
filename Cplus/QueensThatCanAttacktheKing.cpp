#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<int>> queensAttacktheKing(vector<vector<int>> &queens, vector<int> &king)
	{
		int N = 8;
		unordered_set<int> s;
		for (auto &queen : queens)
			s.insert(queen[0] * N + queen[1]);
		vector<vector<int>> res;
		vector<vector<int>> path = {{-1, -1}, {0, -1}, {1, -1}, {-1, 0}, {1, 0}, {-1, 1}, {0, 1}, {1, 1}};
		vector<int> seen(N);
		for (int i = 1; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (seen[j] == 0)
				{
					int x = king[0] + i * path[j][0], y = king[1] + i * path[j][1];
					if (x < 0 || x >= N || y < 0 || y >= N)
					{
						seen[j] = 1;
						continue;
					}
					if (s.find(x * N + y) != s.end())
					{
						res.push_back({x, y});
						seen[j] = 1;
					}
				}
			}
		}
		return res;
	}
};