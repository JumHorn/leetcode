#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	bool isPossible(int n, vector<vector<int>> &edges)
	{
		vector<int> degree(n + 1);
		vector<unordered_set<int>> graph(n + 1);
		for (auto &edge : edges)
		{
			++degree[edge[0]];
			++degree[edge[1]];
			graph[edge[0]].insert(edge[1]);
			graph[edge[1]].insert(edge[0]);
		}
		vector<int> odd;
		for (int i = 1; i <= n; ++i)
		{
			if (degree[i] % 2 == 1)
				odd.push_back(i);
		}
		auto check = [&](int n1, int n2)
		{
			return graph[n1].find(n2) == graph[n1].end();
		};
		if (odd.size() == 0)
			return true;

		if (odd.size() > 4)
			return false;
		if (odd.size() == 2)
		{
			if (check(odd[0], odd[1]))
				return true;
			for (int i = 1; i <= n; ++i)
			{
				if (i != odd[0] && i != odd[1])
				{
					if (check(i, odd[0]) && check(i, odd[1]))
						return true;
				}
			}
		}
		if (odd.size() == 4)
		{
			if (check(odd[0], odd[1]) && check(odd[2], odd[3]))
				return true;
			if (check(odd[0], odd[2]) && check(odd[1], odd[3]))
				return true;
			if (check(odd[0], odd[3]) && check(odd[1], odd[2]))
				return true;
		}
		return false;
	}
};