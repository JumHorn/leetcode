#include<vector>
#include<list>
#include<unordered_map>
using namespace std;
/*
dp[i][j]
	1	2	3	4	5	6	7	8
1	X	X	X	X	X	X	X	X			
2	2	X	X	X	X	X	X	X
3	2	3	X	X	X	X	X	X
4	2			X	X	X	X	X
5	2				X	X	X	X
6	2					X	X	X
7	2						X	X
8	2							X
*/

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) {
		unordered_map<int,int> index;
		for(int i=0;i<A.size();i++)
			index[A[i]]=i;
		int res=0;
		vector<vector<int> > dp(A.size(),vector<int>(A.size(),2));
		for(int i=1;i<A.size();i++)
		{
			for(int j=0;j<i;j++)
			{
				if(A[i]-A[j]<A[j]&&index.count(A[i]-A[j]))
				{
					int k=index[A[i]-A[j]];
					dp[i][j]=dp[j][k]+1;
					if(dp[i][j]>res)
						res=dp[i][j];
				}
				else
				{
					dp[i][j]=2;
				}
			}
		}
		return res==2?0:res;
    }
};
