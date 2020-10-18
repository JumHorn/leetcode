#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int videoStitching(vector<vector<int>> &clips, int T)
	{
		sort(clips.begin(), clips.end(), *this);
		if (clips[0][0] > 0)
			return -1;
		int maxend = clips[0][1], end = maxend, res = 1;
		int N = clips.size();
		for (int i = 1; i < N && end < T; ++i)
		{
			if (clips[i][0] > end)
			{
				if (clips[i][0] > maxend)
					return -1;
				end = maxend;
				++res;
			}
			maxend = max(maxend, clips[i][1]);
		}
		if (end >= T)
			return res;
		return maxend >= T ? res + 1 : -1;
	}

	bool operator()(vector<int> &lhs, vector<int> &rhs)
	{
		if (lhs[0] != rhs[0])
			return lhs[0] < rhs[0];
		return lhs[1] > rhs[1];
	}
};