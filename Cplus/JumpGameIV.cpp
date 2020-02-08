#include <map>
#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
	int minJumps(vector<int>& arr)
	{
		if (arr.size() == 1)
			return 0;
		int res = 0, n = arr.size();
		map<int, vector<int>> m;
		for (int i = 0; i < n; i++)
			m[arr[i]].push_back(i);
		vector<int> seen(n);
		queue<int> q;
		q.push(0);
		seen[0] = 1;
		while (!q.empty())
		{
			int size = q.size();
			res++;
			priority_queue<int> newq;
			while (--size >= 0)
			{
				int tmp = q.front();
				q.pop();
				if (tmp - 1 >= 0 && seen[tmp - 1] == 0)
				{
					newq.push(tmp - 1);
					seen[tmp - 1] = 1;
				}
				if (tmp + 1 < n && seen[tmp + 1] == 0)
				{
					if (tmp + 1 == n - 1)
						return res;
					newq.push(tmp + 1);
					seen[tmp + 1] = 1;
				}
				for (auto t : m[arr[tmp]])
				{
					if (seen[t] == 0)
					{
						if (t == n - 1)
							return res;
						seen[t] = 1;
						newq.push(t);
					}
				}
			}
			while (!newq.empty())
			{
				q.push(newq.top());
				newq.pop();
			}
		}
		return res;
	}
};
