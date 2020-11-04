#include <algorithm>
#include <functional>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	int findLeastNumOfUniqueInts(vector<int> &arr, int k)
	{
		unordered_map<int, int> m;
		for (auto n : arr)
			++m[n];
		priority_queue<int, vector<int>, greater<int>> q;
		for (auto n : m)
			q.push(n.second);
		int res = m.size();
		while (!q.empty() && k >= q.top())
		{
			--res;
			k -= q.top();
			q.pop();
		}
		return res;
	}
};