#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

/*
state
xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx
每个字节表示对应下标的压缩坐标位置x*8+y
任意位置8个方向的所有可能集合，大于该问题的集合
*/

class Solution
{
public:
	int countCombinations(vector<string> &pieces, vector<vector<int>> &positions)
	{
		dir["rook"] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
		dir["queen"] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
		dir["bishop"] = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
		queue<int> q;
		unordered_set<int> seen;
		vector<int> coord;
		for (auto &p : positions)
		{
			int x = p[0] - 1, y = p[1] - 1;
			coord.push_back(x * 8 + y);
		}
		int state = compress(coord);
		int N = pieces.size();
		q.push(state);
		seen.insert(state);
		while (!q.empty())
		{
			state = q.front();
			q.pop();
			vector<vector<int>> coordinate(N);
			uncompress(state, N, pieces, coordinate);
			dfs(coordinate, 0, 0, q, seen);
		}
		return seen.size();
	}

	void dfs(vector<vector<int>> &coord, int index, int state, queue<int> &q, unordered_set<int> &seen)
	{
		int N = coord.size();
		if (index >= N)
		{
			if (valide(state, N) && seen.count(state) == 0)
			{
				seen.insert(state);
				q.push(state);
			}
			return;
		}
		for (auto p : coord[index])
			dfs(coord, index + 1, state | (p << (index * 8)), q, seen);
	}

	bool valide(int state, int N)
	{
		unordered_set<int> s;
		for (int i = 0; i < N; ++i)
			s.insert((state >> (i * 8)) & 0xFF);
		return s.size() == N;
	}

	int compress(vector<int> &coordinate)
	{
		int res = 0, N = coordinate.size();
		for (int i = 0; i < N; ++i)
			res |= coordinate[i] << (i * 8);
		return res;
	}

	void uncompress(int state, int N, vector<string> &pieces, vector<vector<int>> &coord)
	{
		for (int i = 0; i < N; ++i)
		{
			int co = (0xFF & (state >> (i * 8)));
			int x = co / SIZE, y = co % SIZE;
			for (auto &v : dir[pieces[i]])
			{
				int dx = x + v[0], dy = y + v[1];
				if (dx >= 0 && dx < SIZE && dy >= 0 && dy < SIZE)
					coord[i].push_back(dx * SIZE + dy);
			}
		}
	}

private:
	unordered_map<string, vector<vector<int>>> dir;
	const static int SIZE = 8;
};