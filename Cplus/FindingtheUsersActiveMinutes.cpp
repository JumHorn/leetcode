#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> findingUsersActiveMinutes(vector<vector<int>> &logs, int k)
	{
		vector<int> res(k);
		sort(logs.begin(), logs.end());
		int id = -1, m = -1, a = 0;
		for (auto &log : logs)
		{
			if (log[0] != id) //new user
			{
				if (id >= 0)
					++res[a - 1];
				id = log[0];
				m = log[1];
				a = 1;
			}
			else
			{
				if (m != log[1])
				{
					m = log[1];
					++a;
				}
			}
		}
		++res[a - 1];
		return res;
	}
};