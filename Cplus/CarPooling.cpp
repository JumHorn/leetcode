#include <map>
#include <vector>
using namespace std;

class Solution
{
public:
	bool carPooling(vector<vector<int>> &trips, int capacity)
	{
		map<int, int> m;
		for (auto &trip : trips)
		{
			m[trip[1]] -= trip[0];
			m[trip[2]] += trip[0];
		}
		for (auto &n : m)
		{
			capacity += n.second;
			if (capacity < 0)
				return false;
		}
		return true;
	}
};