#include <vector>
using namespace std;

class Solution
{
public:
	int maximumGroups(vector<int> &grades)
	{
		int N = grades.size();
		int lo = 1, hi = N + 1;
		while (lo < hi)
		{
			long long mi = (hi - lo) / 2 + lo;
			if (mi * (mi + 1) / 2 <= N)
				lo = mi + 1;
			else
				hi = mi;
		}
		return lo - 1;
	}
};