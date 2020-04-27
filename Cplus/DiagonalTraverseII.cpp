#include <map>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> findDiagonalOrder(vector<vector<int>> &nums)
	{
		vector<int> res;
		int n = nums.size();
		map<int, int> m;
		for (int i = 0; i < n; i++)
		{
			m[i] = 0;
			auto iter = m.end();
			do
			{
				--iter;
				if (iter->second < (int)nums[iter->first].size())
				{
					res.push_back(nums[iter->first][iter->second]);
					if (iter->second + 1 < (int)nums[iter->first].size())
						m[iter->first] = iter->second + 1;
					else
						iter = m.erase(iter);
				}
			} while (iter != m.begin());
		}
		while (!m.empty())
		{
			auto iter = m.end();
			do
			{
				--iter;
				if (iter->second < (int)nums[iter->first].size())
				{
					res.push_back(nums[iter->first][iter->second]);
					if (iter->second + 1 < (int)nums[iter->first].size())
						m[iter->first] = iter->second + 1;
					else
						iter = m.erase(iter);
				}
			} while (iter != m.begin());
		}
		return res;
	}
};