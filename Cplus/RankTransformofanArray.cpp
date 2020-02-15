#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> arrayRankTransform(vector<int>& arr)
	{
		priority_queue<pair<int, int>> q;
		for (int i = 0; i < (int)arr.size(); i++)
			q.push({-arr[i], i});
		int rank = 0, value = INT_MIN;
		while (!q.empty())
		{
			auto tmp = q.top();
			q.pop();
			if (tmp.first != value)
			{
				++rank;
				value = tmp.first;
			}
			arr[tmp.second] = rank;
		}
		return arr;
	}
};
