#include <vector>
using namespace std;

class Solution
{
public:
	int maxArea(int h, int w, vector<int> &horizontalCuts, vector<int> &verticalCuts)
	{
		horizontalCuts.push_back(h);
		sort(horizontalCuts.begin(), horizontalCuts.end());
		for (int i = horizontalCuts.size() - 1; i > 0; --i)
			horizontalCuts[i] -= horizontalCuts[i - 1];
		verticalCuts.push_back(w);
		sort(verticalCuts.begin(), verticalCuts.end());
		for (int i = verticalCuts.size() - 1; i > 0; --i)
			verticalCuts[i] -= verticalCuts[i - 1];
		long a = *max_element(horizontalCuts.begin(), horizontalCuts.end());
		long b = *max_element(verticalCuts.begin(), verticalCuts.end());
		// for(int i=0;i<(int)horizontalCuts.size();i++)
		// {
		//     for(int j=0;j<(int)verticalCuts.size();j++)
		//     {
		//         res=max(res,(long)horizontalCuts[i]*(long)verticalCuts[j]);
		//     }
		// }
		return (a % MOD) * (b % MOD) % MOD;
	}

private:
	static const int MOD = 1e9 + 7;
};
