#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int minProcessingTime(vector<int> &processorTime, vector<int> &tasks)
	{
		sort(tasks.begin(), tasks.end());
		vector<int> v;
		int N = tasks.size();
		for (int i = 3; i < N; i += 4)
			v.push_back(tasks[i]);
		N = v.size();
		sort(processorTime.begin(), processorTime.end(), greater<int>());
		sort(v.begin(), v.end());
		long long res = 0;
		for (int i = 0; i < N; ++i)
			res = max(res, (long long)v[i] + processorTime[i]);
		return res;
	}
};