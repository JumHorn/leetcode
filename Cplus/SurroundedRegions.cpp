#include<vector>
using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
		if(board.empty()||board[0].empty())
			return;
		for(int i=0;i<(int)board.size();i++)
		{
			dfs(board,i,0);
			dfs(board,i,board[0].size()-1);
		}
		for(int j=0;j<(int)board[0].size();j++)
		{
			dfs(board,0,j);
			dfs(board,board.size()-1,j);
		}	
		for(int i=0;i<(int)board.size();i++)
			for(int j=0;j<(int)board[0].size();j++)
			{
				if(board[i][j]=='#')
					board[i][j]='O';
				else
					board[i][j]='X';
			}
    }

	void dfs(vector<vector<char>>& board,int i,int j)
	{
		if(i<0||i>=(int)board.size()||j<0||j>=(int)board[0].size()||board[i][j]=='#'||board[i][j]=='X')
			return;
		board[i][j]='#';
		dfs(board,i+1,j);
		dfs(board,i-1,j);
		dfs(board,i,j+1);
		dfs(board,i,j-1);
	}
};
