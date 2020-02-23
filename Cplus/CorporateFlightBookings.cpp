#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n)
	{
		vector<int> res(n);
		for (int i = 0; i < (int)bookings.size(); i++)
		{
			for (int j = bookings[i][0]; j <= bookings[i][1]; j++)
				res[j - 1] += bookings[i][2];
		}
		return res;
	}
};
