#include<string>
#include<unordered_map>
#include<climits>
using namespace std;

class Solution {
public:
    int findMinStep(string board, string hand) {
		unordered_map<char,int> handmap;
		for(int i=0;i<(int)hand.length();i++)
			handmap[hand[i]]++;
		int res=minStep(board,handmap);
		if(res>=100)
			return -1;
		return res;
    }

	int minStep(string& board,unordered_map<char,int>& hand)
	{
		int res=100;
		int i=0,j=0;
		while(i<(int)board.length())
		{
			string origin(board);
			unordered_map<char,int> oldhand(hand);
			while(i<(int)board.length()&&board[i]=='V')
				i++;
			j=i+1;
			int same=1;
			char v=board[i];
            board[i]='V';
			while(j<(int)board.length()&&(board[j]=='V'||board[j]==v))
			{
				if(board[j]==v)
				{
					same++;
					board[j]='V';
				}
				j++;
			}
            if(i>=(int)board.length())
                return 0;

			if(same>=3)
				res=min(res,minStep(board,hand));
			else
			{
				if(hand.find(v)!=hand.end())
				{
					if(hand[v]>=3-same)
					{
						hand[v]-=3-same;
                        int tmp=minStep(board,hand)+3-same;
						res=min(res,tmp);
					}
				}
			}

			board=origin;
			hand=oldhand;
			i=j;
		}
		return res;
	}
};