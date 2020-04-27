#include <vector>
using namespace std;

class Solution
{
public:
	int maxScore(vector<int> &cardPoints, int k)
	{
		int n = cardPoints.size();
		vector<int> leftsum(n), rightsum(n);
		leftsum[0] = cardPoints[0];
		rightsum[0] = cardPoints[n - 1];
		int res = 0;
		for (int i = 1; i < n; i++)
		{
			leftsum[i] += leftsum[i - 1] + cardPoints[i];
			rightsum[i] += rightsum[i - 1] + cardPoints[n - 1 - i];
		}
		res = max(leftsum[k - 1], rightsum[k - 1]);
		for (int i = 0; i < k - 1; i++)
			res = max(res, leftsum[i] + rightsum[k - i - 2]);
		return res;
	}
};