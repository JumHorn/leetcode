#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int> >& M) {
 		int iresult=1;
		for(int i=0;i<M.size();i++)
		{
			for(int j=0;j<M[0].size();j++)
			{
				if(M[i][j]==1)
					markfriends(M,++iresult,i,j);
			}
		}
 		return iresult-1;		
    }

	void markfriends(vector<vector<int> >& M,int mark, int i, int j)
	{
		M[i][j]=mark;
		if(i-1<0||M[i-1][j]!=1)
		{
		}
		else
		{
			markfriends(M,mark,i-1,j);
		}

		if(i+1>=M.size()||M[i+1][j]!=1)
		{
		}
		else
		{
			markfriends(M,mark,i+1,j);
		}

		if(j-1<0||M[i][j-1]!=1)
		{
		}
		else
		{
			markfriends(M,mark,i,j-1);
		}

		if(j+1>=M[0].size()||M[i][j+1]!=1)
		{
		}
		else
		{
			markfriends(M,mark,i,j+1);
		}
		return;
	}
};
