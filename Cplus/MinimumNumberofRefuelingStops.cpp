#include<vector>
#include<queue>
#include<set>
using namespace std;

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> q;
		if(stations.empty())
			return startFuel>=target?0:-1;
        if(startFuel>=target)
				return 0;
		int n=0,res=0;
		while(n<(int)stations.size())
		{
			if(startFuel>=stations[n][0])
            {
				q.push(stations[n][1]);
                n++;
            }
			else
			{
				if(q.empty())
					return -1;
				startFuel+=q.top();
				++res;
				q.pop();
                if(startFuel>=target)
				    return res;
			}
		}
        while(!q.empty())
        {
            startFuel+=q.top();
            ++res;
            q.pop();
            if(startFuel>=target)
                return res;
        }
		return -1;
    }
};
