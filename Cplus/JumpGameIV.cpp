#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	int minJumps(vector<int> &arr)
	{
		int res = 0, n = arr.size();
		if (n <= 1)
			return res;
		unordered_map<int, vector<int>> m;
		for (int i = 0; i < n; ++i)
			m[arr[i]].push_back(i);
		vector<int> seen(n);
		queue<int> q;
		q.push(0);
		seen[0] = 1;
		while (!q.empty())
		{
			int size = q.size();
			++res;
			while (--size >= 0)
			{
				int front = q.front();
				q.pop();
				if (front == n - 1)
					return res - 1;
				if (front - 1 >= 0 && seen[front - 1] == 0)
				{
					q.push(front - 1);
					seen[front - 1] = 1;
				}
				if (front + 1 < n && seen[front + 1] == 0)
				{
					q.push(front + 1);
					seen[front + 1] = 1;
				}
				for (auto t : m[arr[front]])
				{
					if (seen[t] == 0)
					{
						seen[t] = 1;
						q.push(t);
					}
				}
				m.erase(arr[front]);
			}
		}
		return -1;
	}
};