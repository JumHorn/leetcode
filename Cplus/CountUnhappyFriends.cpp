#include <numeric>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	int unhappyFriends(int n, vector<vector<int>> &preferences, vector<vector<int>> &pairs)
	{
		vector<unordered_map<int, int>> prefer(n);
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n - 1; ++j)
				prefer[i][preferences[i][j]] = j;
		}
		vector<int> seen(n);
		for (int i = 0; i < n / 2; ++i)
		{
			for (int j = 0; j < n / 2; ++j)
			{
				if (i == j)
					continue;

				int x = pairs[i][0], y = pairs[i][1], u = pairs[j][0], v = pairs[j][1];

				if (!seen[x])
				{
					if (getPrefer(prefer, x, y, u, v) || getPrefer(prefer, x, y, v, u))
						seen[x] = 1;
				}

				if (!seen[y])
				{
					if (getPrefer(prefer, y, x, u, v) || getPrefer(prefer, y, x, v, u))
						seen[y] = 1;
				}

				if (!seen[u])
				{
					if (getPrefer(prefer, u, v, x, y) || getPrefer(prefer, u, v, y, x))
						seen[u] = 1;
				}

				if (!seen[v])
				{
					if (getPrefer(prefer, v, u, x, y) || getPrefer(prefer, v, u, y, x))
						seen[v] = 1;
				}
			}
		}
		return accumulate(seen.begin(), seen.end(), 0);
	}

	bool getPrefer(vector<unordered_map<int, int>> &prefer, int x, int y, int u, int v)
	{
		return prefer[x][u] < prefer[x][y] && prefer[u][x] < prefer[u][v];
	}
};