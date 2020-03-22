#include <vector>
using namespace std;

class Solution
{
public:
	int bestRotation(vector<int>& A)
	{
		int n = A.size(), res = 0;
		vector<int> dp(n);
		for (int i = 0; i < n; i++)	 //for A[i] rotate k to lose point
			dp[(i - A[i] + 1 + n) % n] -= 1;
		vector<int> score(n);  //score for every k
		for (int i = 1; i < n; i++)
			score[i] = score[i - 1] + 1 + dp[i];
		int maxscore = score[0];
		for (int i = 1; i < n; i++)
		{
			if (score[i] > maxscore)
			{
				maxscore = score[i];
				res = i;
			}
		}
		return res;
	}
};
