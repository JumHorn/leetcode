#include <vector>
using namespace std;

class Solution
{
public:
	long long largestSquareArea(vector<vector<int>> &bottomLeft, vector<vector<int>> &topRight)
	{
		long long res = 0;
		int N = bottomLeft.size();
		for (int i = 0; i < N - 1; ++i)
		{
			for (int j = i + 1; j < N; ++j)
				res = max(res, computeArea(bottomLeft[i][0], bottomLeft[i][1], topRight[i][0], topRight[i][1], bottomLeft[j][0], bottomLeft[j][1], topRight[j][0], topRight[j][1]));
		}
		return res;
	}

	long long computeArea(long long A, long long B, long long C, long long D, long long E, long long F, long long G, long long H)
	{
		long long intersection = 0;
		if (E < C && G > A && F < D && H > B)
			intersection = min((min(C, G) - max(A, E)), (min(D, H) - max(B, F)));
		return intersection * intersection;
	}
};