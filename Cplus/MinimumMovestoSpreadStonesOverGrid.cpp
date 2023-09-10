#include <queue>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	int minimumMoves(vector<vector<int>> &grid)
	{
		string state;
		for (auto &v : grid)
		{
			for (auto n : v)
				state.push_back('0' + n);
		}
		unordered_set<string> seen;
		queue<string> q;
		q.push(state);
		seen.insert(state);
		int res = 0, M = grid.size(), N = grid[0].size();
		int path[] = {-1, 0, 1, 0, -1};
		while (!q.empty())
		{
			++res;
			int size = q.size();
			while (--size >= 0)
			{
				state = q.front();
				q.pop();
				for (int k = 0; k < state.size(); ++k)
				{
					if (state[k] > '1')
					{
						int i = k / N, j = k % N;
						for (int l = 0; l < 4; ++l)
						{
							int dx = i + path[l], dy = j + path[l + 1];
							if (dx >= 0 && dx < M && dy >= 0 && dy < N)
							{
								string newstate = state;
								--newstate[k];
								++newstate[dx * N + dy];
								if (check(newstate))
									return res;
								if (seen.find(newstate) == seen.end())
								{
									q.push(newstate);
									seen.insert(newstate);
								}
							}
						}
					}
				}
			}
		}
		return -1;
	}

	bool check(string &state)
	{
		for (auto c : state)
		{
			if (c != '1')
				return false;
		}
		return true;
	}
};