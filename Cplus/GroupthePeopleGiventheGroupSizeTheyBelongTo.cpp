#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<int>> groupThePeople(vector<int> &groupSizes)
	{
		unordered_map<int, vector<int>> m; //{group,people label}
		for (int i = 0; i < (int)groupSizes.size(); ++i)
			m[groupSizes[i]].push_back(i);
		vector<vector<int>> res;
		for (auto n : m)
		{
			int size = n.second.size();
			for (int i = 0; i < size; i += n.first)
				res.push_back(vector<int>(n.second.begin() + i, n.second.begin() + i + n.first));
		}
		return res;
	}
};