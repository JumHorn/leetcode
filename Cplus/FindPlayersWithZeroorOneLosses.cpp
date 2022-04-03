#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<int>> findWinners(vector<vector<int>> &matches)
	{
		vector<int> degree(1e5 + 1), seen(1e5 + 1);
		int maxplayer = 0;
		vector<int> res0, res1;
		for (auto &v : matches)
		{
			maxplayer = max({maxplayer, v[0], v[1]});
			++degree[v[1]];
			seen[v[0]] = seen[v[1]] = 1;
		}
		for (int i = 0; i <= maxplayer; ++i)
		{
			if (seen[i] != 0)
			{
				if (degree[i] == 0)
					res0.push_back(i);
				else if (degree[i] == 1)
					res1.push_back(i);
			}
		}
		return {res0, res1};
	}
};