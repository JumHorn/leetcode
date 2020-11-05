#include <numeric>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	int unhappyFriends(int n, vector<vector<int>> &preferences, vector<vector<int>> &pairs)
	{
		vector<unordered_map<int, int>> m(n);
		vector<int> dist(n);
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < preferences[i].size(); ++j)
				m[i][preferences[i][j]] = j;
		}
		for (auto &p : pairs)
		{
			dist[p[0]] = m[p[0]][p[1]];
			dist[p[1]] = m[p[1]][p[0]];
		}
		int res = 0;
		for (int i = 0; i < n; ++i)
		{
			for (int d = 0; d < dist[i]; ++d)
			{
				int j = preferences[i][d];
				for (int d1 = 0; d1 < dist[j]; ++d1)
				{
					if (i == preferences[j][d1])
					{
						++res;
						d = d1 = n;
					}
				}
			}
		}
		return res;
	}
};