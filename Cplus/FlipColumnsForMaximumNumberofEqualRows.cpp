#include <map>
#include <vector>
using namespace std;

class Solution
{
public:
	int maxEqualRowsAfterFlips(vector<vector<int>> &matrix)
	{
		map<vector<int>, int> m; //{row,count}
		int res = 0;
		for (auto &v : matrix)
		{
			if (v[0] == 1)
				arrayFlip(v);
			res = max(res, ++m[v]);
		}
		return res;
	}

	void arrayFlip(vector<int> &arr)
	{
		for (auto &n : arr)
			n ^= 1;
	}
};