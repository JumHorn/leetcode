#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int minStickers(vector<string> &stickers, string target)
	{
		int N = target.length();
		vector<int> dp(1 << N, -1);
		dp[0] = 0;
		for (int mask = 0; mask < 1 << N; ++mask)
		{
			if (dp[mask] == -1)
				continue;
			for (auto &sticker : stickers)
			{
				int next_mask = mask;
				for (auto c : sticker)
				{
					for (int i = 0; i < N; ++i)
					{
						if (((next_mask >> i) & 1) == 1)
							continue;
						if (c == target[i])
						{
							next_mask |= 1u << i;
							break;
						}
					}
				}
				if (dp[next_mask] == -1 || dp[next_mask] > dp[mask] + 1)
					dp[next_mask] = dp[mask] + 1;
			}
		}
		return dp[(1 << N) - 1];
	}
};