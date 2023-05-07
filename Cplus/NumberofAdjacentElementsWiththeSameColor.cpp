#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> colorTheArray(int n, vector<vector<int>> &queries)
	{
		vector<int> color(n), res;
		int same = 0;
		for (auto &q : queries)
		{
			int i = q[0], c = q[1];
			if (i > 0 && color[i - 1] == color[i] && color[i] != 0)
				--same;
			if (i < n - 1 && color[i + 1] == color[i] && color[i] != 0)
				--same;
			color[i] = c;
			if (i > 0 && color[i - 1] == color[i] && color[i] != 0)
				++same;
			if (i < n - 1 && color[i + 1] == color[i] && color[i] != 0)
				++same;
			res.push_back(same);
		}
		return res;
	}
};