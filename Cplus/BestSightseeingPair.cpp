#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int maxScoreSightseeingPair(vector<int> &A)
	{
		int res = A[0] + A[1] + 0 - 1, maxscore = max(A[0], A[1] + 1);
		for (int i = 2; i < (int)A.size(); ++i)
		{
			res = max(res, maxscore + A[i] - i);
			maxscore = max(maxscore, A[i] + i);
		}
		return res;
	}
};