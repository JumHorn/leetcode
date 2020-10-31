#include <vector>
using namespace std;

class Solution
{
public:
	bool checkStraightLine(vector<vector<int>> &coordinates)
	{
		for (int i = 2; i < coordinates.size(); ++i)
		{
			if (!threePointOnALine(coordinates[0], coordinates[1], coordinates[i]))
				return false;
		}
		return true;
	}

	bool threePointOnALine(vector<int> &p0, vector<int> &p1, vector<int> &p2)
	{
		return (p0[0] - p1[0]) * (p0[1] - p2[1]) ==
			   (p0[0] - p2[0]) * (p0[1] - p1[1]);
	}
};