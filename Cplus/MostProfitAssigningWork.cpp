#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit, vector<int> &worker)
	{
		int N = difficulty.size();
		vector<pair<int, int>> job; //{difficulty,profit}
		for (int i = 0; i < N; ++i)
			job.push_back({difficulty[i], profit[i]});
		sort(job.begin(), job.end());
		sort(worker.begin(), worker.end());
		int res = 0, d = 0, p = 0;
		for (int i = 0; i < (int)worker.size(); ++i)
		{
			while (d < N && worker[i] >= job[d].first)
			{
				p = max(p, job[d].second);
				++d;
			}
			res += p;
		}
		return res;
	}
};