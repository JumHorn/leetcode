#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int maxArea(int h, int w, vector<int> &horizontalCuts, vector<int> &verticalCuts)
	{
		horizontalCuts.push_back(h);
		sort(horizontalCuts.begin(), horizontalCuts.end());
		for (int i = (int)horizontalCuts.size() - 1; i > 0; --i)
			horizontalCuts[i] -= horizontalCuts[i - 1];
		verticalCuts.push_back(w);
		sort(verticalCuts.begin(), verticalCuts.end());
		for (int i = (int)verticalCuts.size() - 1; i > 0; --i)
			verticalCuts[i] -= verticalCuts[i - 1];
		long width = *max_element(horizontalCuts.begin(), horizontalCuts.end());
		long height = *max_element(verticalCuts.begin(), verticalCuts.end());
		return (width % MOD) * (height % MOD) % MOD;
	}

private:
	static const int MOD = 1e9 + 7;
};