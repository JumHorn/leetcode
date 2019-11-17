#include <map>
#include <vector>
using namespace std;

class Solution
{
public:
	bool carPooling(vector<vector<int>>& trips, int capacity)
	{
		map<int, int> m;
		for (int i = 0; i < (int)trips.size(); i++)
		{
			m[trips[i][1]] -= trips[i][0];
			m[trips[i][2]] += trips[i][0];
		}
		for (auto& n : m)
		{
			capacity += n.second;
			if (capacity < 0)
				return false;
		}
		return true;
	}
};
