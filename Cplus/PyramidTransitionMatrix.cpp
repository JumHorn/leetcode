#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	bool pyramidTransition(string bottom, vector<string> &allowed)
	{
		for (auto n : allowed)
			dp[n[0] - 'A'][n[1] - 'A'][n[2] - 'A'] = 1;
		string layer(bottom.size(), 'a');
		unordered_set<string> seen;
		return backTrace(bottom, bottom.size(), layer, 0, seen);
	}

	bool backTrace(string bottom, int len, string &tmp, int index, unordered_set<string> &seen)
	{
		if (len == 1)
			return true;
		if (seen.find(bottom.substr(0, len)) != seen.end())
			return false;
		if (index == len - 1)
		{
			for (int i = 0; i < index; i++)
				bottom[i] = tmp[i];
			return backTrace(bottom, len - 1, tmp, 0, seen);
		}
		for (int i = index + 1; i < len; i++)
		{
			int j = 0;
			for (; j < 7; j++)
			{
				if (dp[bottom[i - 1] - 'A'][bottom[i] - 'A'][j] == 1)
				{
					tmp[i - 1] = 'A' + j;
					if (backTrace(bottom, len, tmp, index + 1, seen))
						return true;
					seen.insert(tmp.substr(0, index + 1));
				}
			}
			if (j == 7)
				return false;
		}
		return false;
	}

private:
	int dp[7][7][7];
};