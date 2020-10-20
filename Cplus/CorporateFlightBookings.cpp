#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> corpFlightBookings(vector<vector<int>> &bookings, int n)
	{
		vector<int> res(n);
		for (auto book : bookings)
		{
			res[book[0] - 1] += book[2];
			if (book[1] < n)
				res[book[1]] -= book[2];
		}
		for (int i = 1; i < n; ++i)
			res[i] += res[i - 1];
		return res;
	}
};