#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<int>> queensAttacktheKing(vector<vector<int>> &queens, vector<int> &king)
	{
		const int N = 8;
		unordered_set<int> s;
		for (auto &queen : queens)
			s.insert(queen[0] * N + queen[1]);
		vector<vector<int>> res;
		for (int i = -1; i <= 1; ++i)
		{
			for (int j = -1; j <= 1; ++j)
			{
				for (int k = 1; k < N; ++k)
				{
					int x = king[0] + i * k, y = king[1] + j * k;
					if (x < 0 || x >= N || y < 0 || y >= N) //越界后x*N+y编码就错误了
						continue;
					if (s.find(x * N + y) != s.end())
					{
						res.push_back({x, y});
						break;
					}
				}
			}
		}
		return res;
	}
};