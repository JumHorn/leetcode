#include <climits>
#include <vector>
using namespace std;

class Solution
{
public:
	int partitionDisjoint(vector<int> &A)
	{
		int N = A.size();
		vector<int> minright(N + 1);
		minright[N] = INT_MAX;
		for (int i = N - 1; i >= 0; --i)
			minright[i] = min(minright[i + 1], A[i]);
		int res = 0, maxleft = 0;
		for (int i = 0; i < N; ++i)
		{
			maxleft = max(maxleft, A[i]);
			if (maxleft <= minright[i + 1])
				return i + 1;
		}
		return 0;
	}
};