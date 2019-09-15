#include<vector>
#include<string>
#include<unordered_set>
#include<queue>
#include<algorithm>
using namespace std;

class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
		unordered_set<string> visited;
		queue<pair<string,pair<int,int>>> q;
 		q.push(boardToString(board));
		visited.insert(q.front().first);
		string finalstate="123450";
		int res=0,M=board.size(),N=board[0].size();
		while(!q.empty())
		{
			int s=q.size();
			while(--s>=0)
			{
				string top=q.front().first;
				if(top==finalstate)
					return res;
				int i=q.front().second.first,j=q.front().second.second;
                q.pop();
				if(i-1>=0)
				{
					swap(top[(i-1)*N+j],top[i*N+j]);
					if(visited.find(top)==visited.end())
					{
						visited.insert(top);
						q.push({top,{i-1,j}});
					}
					swap(top[(i-1)*N+j],top[i*N+j]);
				}
				if(i+1<M)
				{
					swap(top[(i+1)*N+j],top[i*N+j]);
					if(visited.find(top)==visited.end())
					{
						visited.insert(top);
						q.push({top,{i+1,j}});
					}
					swap(top[(i+1)*N+j],top[i*N+j]);
				}
				if(j-1>=0)
				{
					swap(top[i*N+j-1],top[i*N+j]);
					if(visited.find(top)==visited.end())
					{
						visited.insert(top);
						q.push({top,{i,j-1}});
					}
					swap(top[i*N+j-1],top[i*N+j]);
				}
				if(j+1<N)
				{
					swap(top[i*N+j+1],top[i*N+j]);
					if(visited.find(top)==visited.end())
					{
						visited.insert(top);
						q.push({top,{i,j+1}});
					}
					swap(top[i*N+j+1],top[i*N+j]);
				}
			}
			res++;
		}
		return -1;
    }

	pair<string,pair<int,int>> boardToString(vector<vector<int>>& board)
	{
		int x,y;
		string res;
		for(int i=0;i<(int)board.size();i++)
			for(int j=0;j<(int)board[0].size();j++)
			{
				if(board[i][j]==0)
				{
					x=i;
					y=j;
				}
				res+=to_string(board[i][j]);
			}
		return {res,{x,y}};
	}
};