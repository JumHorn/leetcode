#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<string> findHighAccessEmployees(vector<vector<string>> &access_times)
	{
		unordered_map<string, vector<int>> m;
		for (auto &v : access_times)
		{
			int t = ((v[1][0] - '0') * 10 + v[1][1] - '0') * 60 + (v[1][2] - '0') * 10 + v[1][3] - '0';
			m[v[0]].push_back(t);
		}
		vector<string> res;
		int maxt = 0;
		for (auto &[name, v] : m)
		{
			int t = 1, N = v.size();
			sort(v.begin(), v.end());
			for (int i = 1, j = 0; i < N; ++i)
			{
				while (v[i] - v[j] >= 60)
					++j;
				t = max(t, i - j + 1);
			}
			if (t >= 3)
				res.push_back(name);
		}
		return res;
	}
};