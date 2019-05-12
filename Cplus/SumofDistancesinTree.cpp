#include<vector>
#include<set>
using namespace std;

class Solution {
public:
    vector<int> sumOfDistancesInTree(int N, vector<vector<int> >& edges) {
        vector<vector<int> > graph(N,vector<int>()),dp(N,vector<int>(N));
		for(int i=0;i<(int)edges.size();i++)
		{
			graph[edges[i][0]].push_back(edges[i][1]);
			graph[edges[i][1]].push_back(edges[i][0]);
            dp[edges[i][0]][edges[i][1]]=1;
            dp[edges[i][1]][edges[i][0]]=1;
		}
		for(int i=0;i<N;i++)
			for(int j=i+1;j<N;j++)
			{
		 		set<pair<int,int> > visited;
		 		if(dp[i][j]==0)
		 			sumOfDistancesInTree(graph,dp,visited,i,j);
		    }
		vector<int> res(N);
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++)
				res[i]+=dp[i][j];
		return res;
    }

	int sumOfDistancesInTree(vector<vector<int> >& graph,vector<vector<int> >& dp,set<pair<int,int> >& visited,int i,int j)
	{
		if(i==j)
			return 0;
		if(dp[i][j]!=0)
			return dp[i][j];
		if(visited.find({i,j})!=visited.end())
			return -1;
        visited.insert({i,j});
		int res=-1;
		for(int m=0;m<(int)graph[i].size();m++)
		{
			int tmp=sumOfDistancesInTree(graph,dp,visited,graph[i][m],j);
			if(tmp!=-1)
			{
				res=dp[j][i]=dp[i][j]=1+tmp;
				break;
			}
		}
		return res;
	}
};
