#include <vector>
using namespace std;

class Solution
{
public:
	int numTeams(vector<int> &rating)
	{
		int N = rating.size(), res = 0;
		vector<int> dp_up(N), dp_down(N);
		for (int i = 1; i < N; ++i)
		{
			for (int j = 0; j < i; ++j)
			{
				if (rating[j] < rating[i])
				{
					++dp_up[i];
					res += dp_up[j];
				}
				if (rating[j] > rating[i])
				{
					++dp_down[i];
					res += dp_down[j];
				}
			}
		}
		return res;
	}
};