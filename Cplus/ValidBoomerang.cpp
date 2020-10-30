#include <vector>
using namespace std;

/*
calculate the slope of AB and AC to avoid zero fraction
*/

class Solution
{
public:
	bool isBoomerang(vector<vector<int>> &points)
	{
		return (points[0][0] - points[1][0]) * (points[0][1] - points[2][1]) !=
			   (points[0][0] - points[2][0]) * (points[0][1] - points[1][1]);
	}
};