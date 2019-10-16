#include<vector>
#include<set>
#include<queue>
using namespace std;

class Solution {
public:
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        set<pair<int,int>> block,visited;
		for(int i=0;i<(int)blocked.size();i++)
			block.insert({blocked[i][0],blocked[i][1]});
		queue<pair<int,int>> q;
		q.push({source[0],source[1]});
		visited.insert({source[0],source[1]});
		int count=1;
		int dir[][2]={{1,0},{-1,0},{0,1},{0,-1}};
		while(count<(int)block.size()&&!q.empty())
		{
			int size=q.size();
			while(--size>=0)
			{
				for(int i=0;i<4;i++)
				{
					int x=q.front().first+dir[i][0],y=q.front().second+dir[i][1];
					if(target[0]==x&&target[1]==y)
						return true;
					if(x>=0&&x<1e6&&y>=0&&y<1e6&&block.find({x,y})==block.end()&&visited.find({x,y})==visited.end())
					{
						q.push({x,y});
						visited.insert({x,y});
					}
				}
				q.pop();
			}
            count++;
		}
		if(q.empty())
			return false;

		count=1;
		queue<pair<int,int>> q1;
		q1.push({target[0],target[1]});
		visited.clear();
		visited.insert({target[0],target[1]});
		while(count<(int)block.size()&&!q1.empty())
		{
			int size=q1.size();
			while(--size>=0)
			{
				for(int i=0;i<4;i++)
				{
					int x=q1.front().first+dir[i][0],y=q1.front().second+dir[i][1];
					if(source[0]==x&&source[1]==y)
						return true;
					if(x>=0&&x<1e6&&y>=0&&y<1e6&&block.find({x,y})==block.end()&&visited.find({x,y})==visited.end())
					{
						visited.insert({x,y});
						q1.push({x,y});
					}
				}
				q1.pop();
			}
            count++;
		}
		if(q1.empty())
			return false;
		return true;
    }
};

