#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<int>> generate(int numRows)
	{
		if (numRows == 0)
			return {};
		vector<vector<int>> res = {{1}};
		for (int i = 1; i < numRows; ++i)
		{
			res.push_back({1});
			for (int j = 1; j < i; ++j)
				res[i].push_back(res[i - 1][j - 1] + res[i - 1][j]);
			res.back().push_back(1);
		}
		return res;
	}
};