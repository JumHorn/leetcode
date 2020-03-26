#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
/*
1. create dp[s.size+1][p.size+1] array and dp[i][j] standard for s[0~i] is match p[0-j]
2. p[j]=='.' dp[i+1][j+1] dp[i+1][j+1]=dp[i][j]
   p[j]=='*' dp[i+1][j+1] p[j-1] is match s[i] dp[i + 1][j + 1] = dp[i][j - 1] else dp[i + 1][j + 1] = dp[i + 1][j] || dp[i + 1][j - 1]
   p[j]==(a-z) if s[i]==s[j] dp[i+1][j+1]=dp[i][j] else dp[i][j]=false
3. initialize dp[1~i][0]=false dp[0][1~j]=false dp[0][0]=true
*/

bool isMatch(char *s, char *p)
{
	int len1 = strlen(s), len2 = strlen(p);
	bool dp[len1 + 1][len2 + 1];
	memset(dp, 0, sizeof(dp));
	dp[0][0] = true;
	for (int j = 0; j < len2; j++)
		dp[0][j + 1] = (p[j] == '*' && dp[0][j - 1]);

	for (int i = 0; i < len1; i++)
	{
		for (int j = 0; j < len2; j++)
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
	return dp[len1][len2];
}