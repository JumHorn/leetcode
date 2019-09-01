#include<vector>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<cfloat>
using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int s=points.size();
        if(s<2)
            return s;
		int res=0;
		unordered_map<long double,unordered_map<long double,unordered_set<int>>> data;
		for(int i=0;i<(int)points.size()-1;i++)
			for(int j=i+1;j<(int)points.size();j++)
			{
				if(points[i][0]==points[j][0])
				{
					data[DBL_MAX][points[i][0]*1.0].insert(i);
					data[DBL_MAX][points[i][0]*1.0].insert(j);
					res=max(res,(int)data[DBL_MAX][points[i][0]*1.0].size());
				}
				else
				{
					long double slope=(points[i][1]-points[j][1])*1.0/(points[i][0]-points[j][0]);
					long double intercept=points[i][1]*1.0-points[i][0]*slope;
					data[slope][intercept].insert(i);
					data[slope][intercept].insert(j);
					res=max(res,(int)data[slope][intercept].size());
				}
			}
		return res;
    }
};