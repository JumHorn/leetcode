#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
		vector<double> wageperquality(wage.size());        
		for(int i=0;i<(int)wage.size();i++)
			wageperquality[i]=wage[i]*1.0/quality[i];
		double maxratio=0.0,res=INT_MAX;
		vector<int> workers;
		mincostToHireWorkers(quality,wageperquality,K,workers,0,maxratio,res);
		return res;
    }
	
	void mincostToHireWorkers(vector<int>& quality,vector<double>& wageperquality,int K,vector<int>& workers,int start,double& maxratio,double& res)
	{
		if((int)workers.size()==K)
		{
			double tmp=0.0;
			for(int i=0;i<(int)workers.size();i++)
				tmp+=maxratio*quality[workers[i]];
			res=min(res,tmp);
			return;
		}
		for(int i=start;i<(int)quality.size();i++)
		{
			workers.push_back(i);
			maxratio=max(maxratio,wageperquality[i]);
			mincostToHireWorkers(quality,wageperquality,K,workers,i+1,maxratio,res);
			int tmp=workers.back();
			workers.pop_back();
			if(workers.empty())
				maxratio=0.0;
			else if(maxratio==wageperquality[tmp])
			{
				maxratio=0.0;
				for(int j=0;j<(int)workers.size();j++)
					maxratio=max(maxratio,wageperquality[workers[j]]);
			}
		}
	}
};
