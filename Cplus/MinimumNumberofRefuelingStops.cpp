#include<vector>
#include<queue>
#include<set>
using namespace std;

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<pair<int,int>> q;
		set<pair<int,int>> visited;
		if(stations.empty())
			return startFuel>=target?0:-1;
		visited.insert({0,startFuel});
		int n=0;
		if(startFuel>=stations[0][0])
		{
			q.push({0,startFuel-stations[0][0]});
			visited.insert({0,startFuel-stations[0][0]});
			q.push({-1,startFuel-stations[0][0]+stations[0][1]});
			visited.insert({-1,startFuel-stations[0][0]+stations[0][1]});
		}
		while(!q.empty())
		{
			int size=q.size();
			++n;
			while(--size>=0&&n<(int)stations.size())
			{
				pair<int,int> tmp=q.top();
				q.pop();
				if(tmp.second>=stations[n][0]-stations[n-1][0])
				{
					tmp.second-=stations[n][0]-stations[n-1][0];
					if(tmp.second>=target-stations[n][0])
						return -tmp.first;
					if(visited.find(tmp)==visited.end())
						q.push(tmp);
					tmp.first--;
					tmp.second+=stations[n][1];
					if(visited.find(tmp)==visited.end())
						q.push(tmp);
				}
			}
		}
		return -1;
    }
};
