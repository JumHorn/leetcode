#include <map>
#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
	int minSetSize(vector<int>& arr)
	{
		map<int, int> m;  //value frequence
		for (int i = 0; i < (int)arr.size(); i++)
			++m[arr[i]];
		priority_queue<int> q;
		for (auto n : m)
			q.push(n.second);
		int res = 0, count = 0;
		while (2 * count < (int)arr.size())
		{
			count += q.top();
			q.pop();
			res++;
		}
		return res;
	}
};
