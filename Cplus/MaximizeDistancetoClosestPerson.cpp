#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int maxDistToClosest(vector<int> &seats)
	{
		int res = 0, pre = -1, N = seats.size();
		for (int i = 0; i < N; ++i)
		{
			if (seats[i] == 1)
			{
				res = pre < 0 ? i : max(res, (i - pre) / 2);
				pre = i;
			}
		}
		res = max(res, N - 1 - pre);
		return res;
	}
};