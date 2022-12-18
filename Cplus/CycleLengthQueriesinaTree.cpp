#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> cycleLengthQueries(int n, vector<vector<int>> &queries)
	{
		int N = queries.size();
		vector<int> res;
		for (auto &q : queries)
		{
			int a = q[0], b = q[1], x = 0;
			while (a != b)
			{
				if (a < b)
					swap(a, b);
				a >>= 1;
				++x;
			}
			res.push_back(x + 1);
		}
		return res;
	}
};