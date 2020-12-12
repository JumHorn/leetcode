#include <vector>
using namespace std;

class Solution
{
public:
	int stoneGameVI(vector<int> &aliceValues, vector<int> &bobValues)
	{
		int N = aliceValues.size();
		vector<pair<int, int>> diff(N);
		for (int i = 0; i < N; ++i)
		{
			diff[i].first = aliceValues[i] + bobValues[i];
			diff[i].second = i;
		}
		sort(diff.begin(), diff.end(), greater<pair<int, int>>());
		int alice = 0, bob = 0;
		for (int i = 0; i < N; ++i)
		{
			if (i % 2 == 0)
				alice += aliceValues[diff[i].second];
			else
				bob += bobValues[diff[i].second];
		}
		if (alice == bob)
			return 0;
		return alice > bob ? 1 : -1;
	}
};