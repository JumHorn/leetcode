#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	int numberOfBoomerangs(vector<vector<int>> &points)
	{
		int N = points.size(), res = 0;
		unordered_map<long, int> m; //{distance,count}
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (i != j)
					++m[distance(points[i], points[j])];
			}
			for (auto &n : m)
				res += n.second * (n.second - 1);
			m.clear();
		}
		return res;
	}

	long distance(vector<int> &p1, vector<int> &p2)
	{
		return long(p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]);
	}
};