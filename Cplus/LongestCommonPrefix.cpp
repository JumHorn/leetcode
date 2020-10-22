#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	string longestCommonPrefix(vector<string> &strs)
	{
		if (strs.empty() || strs[0].empty())
			return "";
		int j = 0, M = strs.size(), N = strs[0].length();
		for (; j < N; ++j)
		{
			for (int i = 1; i < M; ++i)
			{
				if (strs[i][j] != strs[0][j])
					return strs[0].substr(0, j);
			}
		}
		return strs[0];
	}
};