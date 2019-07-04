#include<vector>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty())
            return 0;
		int edge=1,M=matrix.size(),N=matrix[0].size();
		vector<vector<int>> v(M+1,vector<int>(N+1));
		for(int i=1;i<=M;i++)
			for(int j=1;j<=N;j++)
				v[i][j]=v[i-1][j]+v[i][j-1]-v[i-1][j-1]+(matrix[i-1][j-1]-'0');
		for(int i=1;i<=M;i++)
		{
			int m=i+edge-1;
			if(m>M)
				break;
			for(int j=1;j<=N;j++)
			{
				int n=j+edge-1;
				if(n>N||m>M)
					break;
				if(matrix[i-1][j-1]=='0'||matrix[m-1][n-1]=='0')
					continue;
				if(edge*edge==v[m][n]+v[i-1][j-1]-v[m][j-1]-v[i-1][n])
				{
					++edge;
                    m=i+edge-1;
					j--;
				}
			}
		}
		return (edge-1)*(edge-1);		
    }
};