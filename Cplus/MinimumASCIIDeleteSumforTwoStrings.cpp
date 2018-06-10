#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
		int m = s1.length();
		int n = s2.length();
        //int **dp = new (int*)[m+1];//no parenthesis 
        int **dp = new int *[m+1]; 
		for(int i=0;i<m+1;i++)
		{
			dp[i] = new int[n+1];
		}
		dp[0][0] = 0;
		for(int i=0;i<m;i++)
		{
			dp[i+1][0] = dp[i][0] + s1[i];
		}
		for(int i=0;i<n;i++)
		{
			dp[0][i+1] = dp[0][i] + s2[i];
		}
		for(int j=1;j<n+1;j++)
		{
			for(int i=1;i<m+1;i++)
			{
				if(s1[i-1]==s2[j-1])
				{
					dp[i][j] = dp[i-1][j-1];
				}
				else
				{
					dp[i][j]=(dp[i-1][j]+s1[i-1]<dp[i][j-1]+s2[j-1])?dp[i-1][j]+s1[i-1]:dp[i][j-1]+s2[j-1];
				}
			}
		}
		return dp[m][n];
    }
};
