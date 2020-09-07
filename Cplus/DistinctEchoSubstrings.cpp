#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

/*
dp[i][j] = k stands for two sub strings that
start from text[i] and text[j] respectively are same at most k characters
*/

class Solution
{
public:
	int distinctEchoSubstrings(string text)
	{
		int N = text.size();
		unordered_set<string> s;
		vector<vector<int>> dp(N + 1, vector<int>(N + 1));
		for (int j = N - 1; j > 0; --j)
		{
			for (int i = j - 1; i >= 0; --i)
			{
				dp[i][j] = text[i] == text[j] ? dp[i + 1][j + 1] + 1 : 0;
				if (dp[i][j] >= j - i)
					s.insert(text.substr(i, j - i));
			}
		}
		return s.size();
	}
};