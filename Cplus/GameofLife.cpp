#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int> >& board) {
		if(board.empty()||board[0].empty())
			return;
		if(board.size()==1)//only one row
		{
			if(board[0].size()==1)
			{
				board[0][0]=0;
				return;
			}
			int tmp=getNext(board[0][0],board[0][1]);
			int i;
			for(i=1;i<(int)(board[0].size()-1);i++)
			{
				int t=getNext(board[0][i],board[0][i-1]+board[0][i+1]);
				board[0][i-1]=tmp;
				tmp=t;
			}
			board[0][i]=getNext(board[0][i],board[0][i-1]);
			board[0][i-1]=tmp;
			return;
		}
        vector<int> v(board[0].size());
        vector<int> tmp(board[0].size());
		int i=0,j=0;
		v[j]=getNext(board[i][j],board[i+1][j]+board[i][j+1]+board[i+1][j+1]);
		for(j=1;j<(int)(board[0].size()-1);j++)
		{
			v[j]=getNext(board[i][j],board[i][j+1]+board[i][j-1]+board[i+1][j]+board[i+1][j-1]+board[i+1][j+1]);
		}
		v[j]=getNext(board[i][j],board[i+1][j]+board[i][j-1]+board[i+1][j-1]);
		for(i=1;i<(int)(board.size()-1);i++)//the first and last row not included
		{
			j=0;
			tmp[j]=getNext(board[i][j],board[i-1][j]+board[i+1][j]+board[i][j+1]+board[i-1][j+1]+board[i+1][j+1]);
			for(j=1;j<(int)(board[0].size()-1);j++)//the first and last column not included
			{
				int sum=0;
				for(int m=i-1;m<=i+1;m++)
					for(int n=j-1;n<=j+1;n++)
						sum+=board[m][n];
				tmp[j]=getNext(board[i][j],sum-board[i][j]);
			}
			tmp[j]=getNext(board[i][j],board[i-1][j]+board[i+1][j]+board[i][j-1]+board[i-1][j-1]+board[i+1][j-1]);
			board[i-1]=v;
			v=tmp;
		}
		j=0;
		tmp[j]=getNext(board[i][j],board[i-1][j]+board[i][j+1]+board[i-1][j+1]);
		for(j=1;j<(int)(board[0].size()-1);j++)
		{
			tmp[j]=getNext(board[i][j],board[i][j+1]+board[i][j-1]+board[i-1][j]+board[i-1][j-1]+board[i-1][j+1]);
		}
        tmp[j]=getNext(board[i][j],board[i-1][j]+board[i][j-1]+board[i-1][j-1]);
		board[i-1]=v;
        board[i]=tmp;
    }

	int getNext(int cell,int live)
	{
		if(cell==1)
		{
			if(live<2)
				return 0;
			else if(live>3)
				return 0;
			else
				return 1;
		}
		else
		{
			if(live==3)
				return 1;
			else
				return 0;
		}
	}
};
