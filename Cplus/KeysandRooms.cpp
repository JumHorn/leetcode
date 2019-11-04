#include<vector>
using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
		int N=rooms.size();        
		vector<bool> visited(N,false);
		dfs(rooms,0,visited);
		for(int i=0;i<N;i++)
			if(!visited[i])
				return false;
		return true;
    }

	void dfs(vector<vector<int>>& rooms,int start,vector<bool>& visited)
	{
		if(visited[start])
			return;
		visited[start]=true;
		for(int i=0;i<(int)rooms[start].size();i++)
			dfs(rooms,rooms[start][i],visited);
	}
};
