#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	int minSetSize(vector<int> &arr)
	{
		unordered_map<int, int> m; //value frequence
		for (auto n : arr)
			++m[n];
		priority_queue<int> q;
		for (auto &n : m)
			q.push(n.second);
		int res = 0, N = arr.size();
		for (int count = 0; 2 * count < N;)
		{
			++res;
			count += q.top();
			q.pop();
		}
		return res;
	}
};