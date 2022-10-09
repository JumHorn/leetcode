#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int hardestWorker(int n, vector<vector<int>> &logs)
	{
		vector<int> time(n);
		int pre = 0;
		for (auto &log : logs)
		{
			time[log[0]] = max(time[log[0]], log[1] - pre);
			pre = log[1];
		}
		return max_element(time.begin(), time.end()) - time.begin();
	}
};