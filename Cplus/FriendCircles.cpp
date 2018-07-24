#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int> >& M) {
 		int iresult=1;
		for(int i=0;i<M.size();i++)
		{
			for(int j=i;j<M.size();j++)
			{
				if(M[i][j]==1)
					markfriends(M,++iresult,i,j);
			}
		}
 		return iresult-1;		
    }

	void markfriends(vector<vector<int> >& M,int mark, int i, int j)
	{
		if(i<0||j<0||i>=M.size()||j>=M.size()||j<i)
		{
			return;
		}
		if(M[i][j]!=1)
		{
			return;
		}
		M[i][j]=mark;
		for(int m=i;m<M.size();m++)
		{
			if(M[i][m]==1)
			{
				M[i][m]=mark;
				for(int n=0;n<=m;n++)
					markfriends(M,mark,n,m);
			}
		}
	}
};
