#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int longestIncreasingPath(vector<vector<int> >& matrix) {
        int res=0;
        if(matrix.empty())
            return res;
		for(int i=0;i<(int)matrix.size();i++)
			for(int j=0;j<(int)matrix[0].size();j++)
				res=max(res,longestIncreasingPath(matrix,i,j));
		return res+1;
    }

	int longestIncreasingPath(vector<vector<int> >& matrix,int i,int j)
	{
		if(i<0||i>=(int)matrix.size()||j<0||j>=(int)matrix[0].size())
			return 0;
		int res=0;
		int tmp[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
		for(int k=0;k<4;k++)
		{
			int x=i+tmp[k][0],y=j+tmp[k][1];
			if(x>=0&&x<(int)matrix.size()&&y>=0&&y<(int)matrix[0].size()&&matrix[x][y]>matrix[i][j])
				res=max(res,1+longestIncreasingPath(matrix,x,y));
		}
		return res;
	}
};
