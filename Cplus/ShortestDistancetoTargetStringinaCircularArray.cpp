#include <algorithm>
#include <climits>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int closetTarget(vector<string> &words, string target, int startIndex)
	{
		int N = words.size(), res = INT_MAX;
		for (int i = 0; i < N; ++i)
		{
			if (words[i] == target)
				res = min({res, abs(i - startIndex), N - abs(i - startIndex)});
		}
		return res == INT_MAX ? -1 : res;
	}
};