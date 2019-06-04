#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    vector<vector<int> > getSkyline(vector<vector<int> >& buildings) {
        vector<vector<int> > res;
        if(buildings.empty())
            return res;
		vector<int> v(buildings.size());
		priority_queue<int> q;
		for(int i=0;i<(int)buildings.size();i++)
		{
			q.push(buildings[i][0]);
			q.push(buildings[i][1]);
		}
		int sweepline=q.top();
		while(!q.empty())
		{
			sweepline=q.top();
			q.pop();
			int maxsky=0,secondsky=0;
			for(int i=0;i<(int)v.size();i++)
			{
				if(v[i]==-1)
					continue;
				if(buildings[i][0]>sweepline)
					continue;
				if(buildings[i][1]<sweepline)
				{
					v[i]=-1;
					continue;
				}
				if(buildings[i][2]>maxsky)
				{
					secondsky=maxsky;
					maxsky=buildings[i][2];
				}
			}
            if(res.empty()||res.back()[1]!=maxsky)
                res.push_back({sweepline,maxsky});
			else
				res.push_back({sweepline,secondsky});
		}
		return res;
    }
};
