#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

class Solution {
public:
    int totalNQueens(int n) {
		if(n<2)
			return 1;
		vector<int> queen(n);
 		return totalNQueens(queen,0,0);
    }

	int totalNQueens(vector<int>& queen,int row,int column)
	{
		if(row==0&&column==queen.size())
			return 0;
		queen[row]=column;
		for(int i=column;i<queen.size();i++)
			if(queenCheck(queen,row,i))
			{
				queen[row]=i;
				if(row==queen.size()-1)
					return 1+totalNQueens(queen,row-1,queen[row-1]+1);
				else
					return totalNQueens(queen,row+1,0);
			}
		return totalNQueens(queen,row-1,queen[row-1]+1);
	}

	bool queenCheck(vector<int>& queen,int row,int column)
	{
		for(int i=0;i<row;i++)
			if(column==queen[i]||(abs(row-i)==abs(column-queen[i])))
				return false;
		return true;
	}
};
