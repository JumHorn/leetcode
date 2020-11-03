#include <vector>
using namespace std;

class Solution
{
public:
	int maxScore(vector<int> &cardPoints, int k)
	{
		int N = cardPoints.size();
		vector<int> prefixsum(N + 1);
		for (int i = 0; i < N; ++i)
			prefixsum[i + 1] = prefixsum[i] + cardPoints[i];
		int res = 0;
		for (int i = 0; i <= k; ++i)
			res = max(res, prefixsum[i] + (prefixsum[N] - prefixsum[N - (k - i)]));
		return res;
	}
};