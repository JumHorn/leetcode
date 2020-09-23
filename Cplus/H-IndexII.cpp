#include <vector>
using namespace std;

class Solution
{
public:
	int hIndex(vector<int> &citations)
	{
		int N = citations.size(), lo = 0, hi = N - 1;
		while (lo <= hi)
		{
			int mi = (hi - lo) / 2 + lo;
			if (citations[mi] < N - mi)
				lo = mi + 1;
			else
				hi = mi - 1;
		}
		return N - lo;
	}
};