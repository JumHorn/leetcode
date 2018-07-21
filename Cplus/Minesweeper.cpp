#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<char> > mineboard;
    vector<vector<char> > updateBoard(vector<vector<char> >& board, vector<int>& click) {
		int m=click[0],n=click[1];
		if(board[m][n]=='M')
		{
			board[m][n]='X';
			return board;
		}
		if(board[m][n]!='E')
		{
			return board;
		}
        this->mineboard.resize(board.size()+2,vector<char>(board[0].size()+2));
		for(vector<vector<char> >::size_type i=0;i<board.size();i++)
		{
			for(vector<vector<char> >::size_type j=0;j<board[0].size();j++)
			{
				mineboard[i+1][j+1]=board[i][j];
			}
		}
		for(vector<vector<char> >::size_type i=0;i<mineboard[0].size();i++)
		{
			mineboard[0][i]='0';
			mineboard[mineboard.size()-1][i]='0';
		}
		for(vector<vector<char> >::size_type i=0;i<mineboard.size();i++)
		{
			mineboard[i][0]='0';
			mineboard[i][mineboard[0].size()-1]='0';
		}
		CalculateDigit(board);
	    //processing Empty
		Reveal(board,m,n);
		return board;
    }

	void CalculateDigit(vector<vector<char> >& board)
	{
		for(vector<vector<char> >::size_type i=1;i<mineboard.size()-1;i++)
		{
			for(vector<vector<char> >::size_type j=1;j<mineboard[0].size()-1;j++)
			{
				if(mineboard[i][j]=='M')
				{
					//上下左右4个方向
					if(mineboard[i-1][j]!='M' && mineboard[i-1][j]!='0')
					{
						if(mineboard[i-1][j]=='E' && board[i-2][j-1]=='E')
						{
							mineboard[i-1][j]='1';
						}
						else if(board[i-2][j-1]=='E')
						{
							mineboard[i-1][j]++;
						}
					}

					if(mineboard[i+1][j]!='M' && mineboard[i+1][j]!='0')
					{
						if(mineboard[i+1][j]=='E' && board[i][j-1]=='E')
						{
							mineboard[i+1][j]='1';
						}
						else if(board[i][j-1]=='E')
						{
							mineboard[i+1][j]++;
						}
					}

					if(mineboard[i][j-1]!='M' && mineboard[i][j-1]!='0')
					{
						if(mineboard[i][j-1]=='E' && board[i-1][j-2]=='E')
						{
							mineboard[i][j-1]='1';
						}
						else if(board[i-1][j-2]=='E')
						{
							mineboard[i][j-1]++;
						}
					}

					if(mineboard[i][j+1]!='M' && mineboard[i][j+1]!='0')
					{
						if(mineboard[i][j+1]=='E' && board[i-1][j]=='E')
						{
							mineboard[i][j+1]='1';
						}
						else if(board[i-1][j]=='E')
						{
							mineboard[i][j+1]++;
						}
					}

					//还有4个倾斜的方向
					if(mineboard[i-1][j-1]!='M' && mineboard[i-1][j-1]!='0')
					{
						if(mineboard[i-1][j-1]=='E' && board[i-2][j-2]=='E')
						{
							mineboard[i-1][j-1]='1';
						}
						else if(board[i-2][j-2]=='E')
						{
							mineboard[i-1][j-1]++;
						}
					}

					if(mineboard[i+1][j-1]!='M' && mineboard[i+1][j-1]!='0')
					{
						if(mineboard[i+1][j-1]=='E' && board[i][j-2]=='E')
						{
							mineboard[i+1][j-1]='1';
						}
						else if(board[i][j-2]=='E')
						{
							mineboard[i+1][j-1]++;
						}
					}

					if(mineboard[i-1][j+1]!='M' && mineboard[i-1][j+1]!='0')
					{
						if(mineboard[i-1][j+1]=='E' && board[i-2][j]=='E')
						{
							mineboard[i-1][j+1]='1';
						}
						else if(board[i-2][j]=='E')
						{
							mineboard[i-1][j+1]++;
						}
					}

					if(mineboard[i+1][j+1]!='M' && mineboard[i+1][j+1]!='0')
					{
						if(mineboard[i+1][j+1]=='E' && board[i][j]=='E')
						{
							mineboard[i+1][j+1]='1';
						}
						else if(board[i][j]=='E')
						{
							mineboard[i+1][j+1]++;
						}
					}

				}
			}
		}
		//print(mineboard);
	}

	void Reveal(vector<vector<char> >& board, int m, int n)
	{
		if(m>=board.size()||n>=board[0].size()||m<0||n<0)	
		{
			return;
		}
		if(board[m][n]!='E')
		{
			return;
		}
		else
		{
			if(mineboard[m+1][n+1]!='E')
			{
				board[m][n]=mineboard[m+1][n+1];
				return;
			}
			board[m][n]='B';
			Reveal(board,m-1,n);
			Reveal(board,m+1,n);
			Reveal(board,m,n-1);
			Reveal(board,m,n+1);
			Reveal(board,m-1,n-1);
			Reveal(board,m+1,n+1);
			Reveal(board,m+1,n-1);
			Reveal(board,m-1,n+1);
		}
	}
	// void print(vector<vector<char> >& board)
	// {
	// 	for(int i=0;i<board.size();i++)
	// 	{
	// 		for(int j=0;j<board[0].size();j++)
	// 		{
	// 			cout<<board[i][j]<< " ";
	// 		}
	// 		cout<<endl;
	// 	}
		
	// }
};
