#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats)
	{
		int res = n * 2;
		unordered_map<int, int> m;
		for (auto& seat : reservedSeats)
		{
			m[seat[0]] |= 1 << seat[1];
		}
		for (auto& tmp : m)
		{
			if ((tmp.second & 0x03fc) == 0)
				continue;
			if ((tmp.second & 0x0f0) == 0)
				res--;
			else if ((tmp.second & 0x03c) == 0)
				res--;
			else if ((tmp.second & 0x03c0) == 0)
				res--;
			else
				res -= 2;
		}
		return res;
	}
};
