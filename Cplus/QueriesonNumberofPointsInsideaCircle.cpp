#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> countPoints(vector<vector<int>> &points, vector<vector<int>> &queries)
	{
		vector<int> res;
		for (auto &q : queries)
		{
			int count = 0;
			for (auto &p : points)
			{
				if ((p[0] - q[0]) * (p[0] - q[0]) + (p[1] - q[1]) * (p[1] - q[1]) <= q[2] * q[2])
					++count;
			}
			res.push_back(count);
		}
		return res;
	}
};