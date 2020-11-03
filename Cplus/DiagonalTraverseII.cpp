#include <map>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> findDiagonalOrder(vector<vector<int>> &nums)
	{
		map<int, vector<int>> m; //{row+col,{val}}
		for (int i = 0; i < (int)nums.size(); ++i)
		{
			for (int j = 0; j < (int)nums[i].size(); ++j)
				m[i + j].push_back(nums[i][j]);
		}
		vector<int> res;
		for (auto &n : m)
		{
			auto &v = n.second;
			for (int i = (int)v.size() - 1; i >= 0; --i)
				res.push_back(v[i]);
		}
		return res;
	}
};