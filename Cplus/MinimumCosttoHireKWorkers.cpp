#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
		vector<vector<double> > expect(wage.size());
		for(int i=0;i<(int)wage.size();i++)
		{
			expect[i].push_back(wage[i]*1.0/quality[i]);
			expect[i].push_back(quality[i]);
		}
		sort(expect.begin(),expect.end());
		priority_queue<int> workers;
		double res=INT_MAX,qualitysum=0.0;
		for(int i=0;i<(int)expect.size();i++)
		{
			qualitysum+=expect[i][1];
            workers.push(expect[i][1]);
            if (workers.size() > K)
            {
                qualitysum -= workers.top();
                workers.pop();
            }
            if (workers.size() == K)
                res = min(res, qualitysum * expect[i][0]);
		}
		return res;
    }
};
