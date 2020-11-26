#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	int minJumps(vector<int> &arr)
	{
		int res = 0, N = arr.size();
		if (N <= 1)
			return res;
		unordered_map<int, vector<int>> m;
		for (int i = 0; i < N; ++i)
			m[arr[i]].push_back(i);
		vector<int> seen(N);
		queue<int> q;
		q.push(0);
		seen[0] = 1;
		while (!q.empty())
		{
			++res;
			int size = q.size();
			while (--size >= 0)
			{
				int front = q.front();
				q.pop();
				if (front == N - 1)
					return res - 1;
				if (front - 1 >= 0 && seen[front - 1] == 0)
				{
					q.push(front - 1);
					seen[front - 1] = 1;
				}
				if (front + 1 < N && seen[front + 1] == 0)
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