#include <string>
#include <vector>
using namespace std;

/*
1. create dp[s.size+1][p.size+1] array and dp[i][j] standard for s[0~i] is match p[0-j]
2. p[j]=='.' dp[i+1][j+1] dp[i+1][j+1]=dp[i][j]
   p[j]=='*'
   p[j-1] is match s[i]
   dp[i + 1][j + 1] = dp[i][j + 1] || dp[i + 1][j - 1] || dp[i + 1][j]
   p[j-1] is not match s[i]
   dp[i + 1][j + 1] = dp[i + 1][j - 1]
   p[j]==(a-z) if s[i]==s[j] dp[i+1][j+1]=dp[i][j] else dp[i][j]=false
3. initialize dp[0][0]=true dp[0][j]=(p[j] == '*' && dp[0][j - 1])

using example tabular to show the dp function
Y stand for true N stand for false
s=aab
p=c*a*b

	0	c	*	a	*	b
0	Y	N	Y	N	Y	N
a	N	N	N	Y	Y	N
a	N	N	N	N	Y	N
b	N	N	N	N	N	Y

if p[j]=='*' we will choose the previous two dp in the same row and the above one
*/

class Solution
{
public:
	bool isMatch(string s, string p)
	{
		int M = s.length(), N = p.length();
		vector<vector<bool>> dp(M + 1, vector<bool>(N + 1));
		dp[0][0] = true;
		for (int j = 0; j < N; ++j)
			dp[0][j + 1] = (p[j] == '*' && dp[0][j - 1]);

		for (int i = 0; i < M; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (p[j] == '.' || p[j] == s[i])
					dp[i + 1][j + 1] = dp[i][j];
				else if (p[j] == '*')
				{
					if (p[j - 1] == '.' || p[j - 1] == s[i])
						dp[i + 1][j + 1] = dp[i][j + 1] || dp[i + 1][j - 1] || dp[i + 1][j];
					else
						dp[i + 1][j + 1] = dp[i + 1][j - 1];
				}
			}
		}
		return dp[M][N];
	}
};