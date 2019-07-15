#include<vector>
#include<queue>
#include<climits>
#include<algorithm>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<pair<int,int>>> graph(n);
		for(int i=0;i<(int)flights.size();i++)
			graph[flights[i][0]].push_back({flights[i][1],flights[i][2]});
		queue<pair<int,int>> q;
		q.push({src,0});
		int res=INT_MAX;
		while(!q.empty()&&K-->=0)
		{
			int size=q.size();
			while(--size>=0)
			{
				pair<int,int> tmp=q.front();
				q.pop();
				for(int i=0;i<(int)graph[tmp.first].size();i++)
				{
                    int newsrc=graph[tmp.first][i].first;
                    int cost=tmp.second+graph[tmp.first][i].second;
                    if(newsrc==dst)
                        res=min(res,cost);
                    else if(cost<res)
					    q.push({newsrc,cost});
				}
			}
		}
		return res==INT_MAX?-1:res;
    }
};