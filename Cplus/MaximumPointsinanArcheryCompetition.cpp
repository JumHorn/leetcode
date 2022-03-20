#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> maximumBobPoints(int numArrows, vector<int> &aliceArrows)
	{
		int N = aliceArrows.size(), maxscore = 0, mask = 0;
		for (int i = (1 << N) - 1; i > 0; --i)
		{
			int sum = 0, score = 0;
			for (int j = 0; j < N; ++j)
			{
				if (i & (1 << j))
				{
					sum += aliceArrows[j] + 1;
					score += j;
				}
			}
			if (sum <= numArrows && maxscore < score)
			{
				maxscore = score;
				mask = i;
			}
		}
		vector<int> res(N);
		int sum = 0;
		for (int i = 0; i < N; ++i)
		{
			if (mask & (1 << i))
				res[i] = aliceArrows[i] + 1;
			sum += res[i];
		}
		res[0] += numArrows - sum;
		return res;
	}
};