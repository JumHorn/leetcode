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
*/

class Solution
{
public:
	int countCombinations(vector<string> &pieces, vector<vector<int>> &positions)
	{
		unordered_map<string, vector<vector<int>>> dir;
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
		int res = 0, N = pieces.size();
		q.push(state);
		seen.insert(state);
		while (!q.empty())
		{
			state = q.front();
			q.pop();
		}
		return res;
	}

	int compress(vector<int> &coordinate)
	{
		int res = 0, N = coordinate.size();
		for (int i = 0; i < N; ++i)
			res |= coordinate[i] << (i * 8);
		return res;
	}

	vector<int> uncompress(int coord, int n)
	{
		vector<int> res;
		for (int i = 0; i < n; ++i)
			res.push_back(0xFF & (coord >> (i * 8)));
		return res;
	}
};