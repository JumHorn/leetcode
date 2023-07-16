#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	int longestValidSubstring(string word, vector<string> &forbidden)
	{
		unordered_set<string> fb(forbidden.begin(), forbidden.end());
		int N = word.size(), res = 0, start = 0;
		for (int i = 0; i < N; ++i)
		{
			for (int j = i; j >= start && j > i - 10; --j)
			{
				if (fb.find(word.substr(j, i - j + 1)) != fb.end())
				{
					start = j + 1;
					break;
				}
			}
			res = max(res, i - start + 1);
		}
		return res;
	}
};