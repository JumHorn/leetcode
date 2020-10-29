#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	int maxNumberOfFamilies(int n, vector<vector<int>> &reservedSeats)
	{
		int res = n * 2;
		unordered_map<int, int> m;
		for (auto &seat : reservedSeats)
			m[seat[0]] |= 1 << (seat[1] - 1);
		for (auto &seat : m)
		{
			if ((seat.second & 0b0111111110) == 0)
				continue;
			if ((seat.second & 0b0001111000) == 0)
				--res;
			else if ((seat.second & 0b0111100000) == 0)
				--res;
			else if ((seat.second & 0b0000011110) == 0)
				--res;
			else
				res -= 2;
		}
		return res;
	}
};