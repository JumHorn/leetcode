#include<vector>
#include<cmath>
using namespace std;

class Solution {
public:
    int shortestBridge(vector<vector<int> >& A) {
		bool flag=true;
		vector<vector<int> > island;
		int res=INT_MAX;
		for(int i=0;i<(int)A.size();i++)
			for(int j=0;j<(int)A[0].size();j++)
			{
				if(A[i][j]==1)
				{
					if(flag)
					{
						findIslands(A,island,i,j);
						flag=false;
					}
					else
						for(int k=0;k<(int)island.size();k++)
							res=min(res,abs(island[k][0]-i)+abs(island[k][1]-j)-1);
				}
			}
		return res;
    }

	void findIslands(vector<vector<int> >& A,vector<vector<int> >& island,int i,int j)
	{
		if(i<0||j<0||i>=(int)A.size()||j>=(int)A[0].size()||A[i][j]==0)
			return;
		vector<int> tmp(2);
		tmp[0]=i;
		tmp[1]=j;
		island.push_back(tmp);
		A[i][j]=0;
		findIslands(A,island,i+1,j);
		findIslands(A,island,i-1,j);
		findIslands(A,island,i,j+1);
		findIslands(A,island,i,j-1);
	}
};
