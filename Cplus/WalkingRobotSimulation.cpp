#include <algorithm>
#include <set>
#include <vector>
using namespace std;

class Solution
{
public:
	int robotSim(vector<int> &commands, vector<vector<int>> &obstacles)
	{
		int degree = 0, x = 0, y = 0, res = 0;
		int path[][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
		set<pair<int, int>> ob;
		for (auto &obs : obstacles)
			ob.insert({obs[0], obs[1]});
		for (auto comm : commands)
		{
			if (comm < 0)
			{
				comm == -1 ? ++degree : --degree;
				degree = (degree + 4) % 4;
			}
			else
			{
				for (int j = 1; j <= comm; ++j)
				{
					if (ob.find({x + path[degree][0], y + path[degree][1]}) != ob.end())
						break;
					x += path[degree][0];
					y += path[degree][1];
					res = max(res, x * x + y * y);
				}
			}
		}
		return res;
	}
};