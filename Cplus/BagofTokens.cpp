#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int bagOfTokensScore(vector<int> &tokens, int P)
	{
		sort(tokens.begin(), tokens.end());
		int res = 0, i = 0, j = tokens.size() - 1, score = 0;
		while (i <= j)
		{
			if (P - tokens[i] >= 0)
			{
				P -= tokens[i++];
				++score;
				res = max(res, score);
			}
			else
			{
				if (score <= 0)
					break;
				--score;
				P += tokens[j--];
			}
		}
		return res;
	}
};