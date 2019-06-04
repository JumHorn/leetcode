#include<vector>
#include<queue>
#include<set>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<int> > getSkyline(vector<vector<int> >& buildings) {
        vector<vector<int> > res;
        if(buildings.empty())
            return res;
		vector<int> v(buildings.size());
		unordered_map<int,int> mergemap;
		for(int i=0;i<(int)buildings.size();i++)
		{
			if(mergemap.find(buildings[i][2])==mergemap.end())
				mergemap[buildings[i][2]]=i;
			else
			{
				int index=mergemap[buildings[i][2]];
				if(buildings[index][1]>=buildings[i][0])
				{
					if(buildings[index][1]<buildings[i][1])
						buildings[index][1]=buildings[i][1];
					buildings[i][0]=-1;
				}
				else
					mergemap[buildings[i][2]]=i;
			}
		}
		priority_queue<pair<int,int> > q;
		for(int i=0;i<(int)buildings.size();i++)
		{
			if(buildings[i][0]!=-1)
			{
				q.push({-buildings[i][0],i});
				q.push({-buildings[i][1],i});
			}
		}
		while(!q.empty())
		{
			int sweepline=-q.top().first;
            int index=q.top().second;
			q.pop();
            bool flag=true;
			bool flag1=false;
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
				if(buildings[i][2]>buildings[index][2])
                {
                    flag=false;
					break;
                }
				if(buildings[i][2]>maxsky)
				{
					if(flag1)
                    	secondsky=maxsky;
					maxsky=buildings[i][2];
					flag1=(sweepline!=buildings[i][1]);
				}
                if(maxsky!=buildings[i][2]&&buildings[i][2]>secondsky&&sweepline!=buildings[i][1])
				{
					secondsky=buildings[i][2];
				}
			}
            if(flag)
            {
                if(res.empty()||res.back()[1]!=maxsky)
                    res.push_back({sweepline,maxsky});
                else
                    res.push_back({sweepline,secondsky});
            }
		}
		return res;
    }
};
