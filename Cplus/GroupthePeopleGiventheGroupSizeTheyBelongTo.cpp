#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<int>> groupThePeople(vector<int>& groupSizes)
	{
		unordered_map<int, vector<int>> m;
		for (int i = 0; i < (int)groupSizes.size(); i++)
			m[groupSizes[i]].push_back(i);
		vector<vector<int>> res;
		for (auto n : m)
		{
			int i = 0, size = n.second.size();
			while (i < size)
			{
				res.push_back(vector<int>(n.second.begin() + i, n.second.begin() + i + n.first));
				i += n.first;
			}
		}
		return res;
	}
};
