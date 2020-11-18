#include <algorithm>
#include <climits>
#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
	double mincostToHireWorkers(vector<int> &quality, vector<int> &wage, int K)
	{
		vector<pair<double, double>> expect;
		for (int i = 0; i < (int)wage.size(); ++i)
			expect.push_back({wage[i] * 1.0 / quality[i], quality[i]});
		sort(expect.begin(), expect.end());
		priority_queue<int> workers; //store workers quality
		double res = INT_MAX, qualitysum = 0.0;
		for (auto exp : expect)
		{
			qualitysum += exp.second;
			workers.push(exp.second);
			if ((int)workers.size() > K)
			{
				qualitysum -= workers.top();
				workers.pop();
			}
			if ((int)workers.size() == K)
				res = min(res, qualitysum * exp.first);
		}
		return res;
	}
};