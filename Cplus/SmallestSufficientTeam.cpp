#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> smallestSufficientTeam(vector<string> &req_skills, vector<vector<string>> &people)
	{
		int N = req_skills.size();
		vector<vector<int>> dp(1 << N); //{skillmask as index,people as vector<int>}
		vector<bool> seen(1 << N);
		unordered_map<string, int> skills; //{skill,bit}
		for (int i = 0; i < N; ++i)
			skills[req_skills[i]] = 1 << i;

		seen[0] = true;
		for (int i = 0; i < (int)people.size(); ++i)
		{
			int pskill = 0;
			for (auto &str : people[i])
				pskill |= skills[str];
			if (pskill == 0)
				continue;

			for (int j = (1 << N) - 1; j >= 0; --j)
			{
				if (!seen[j])
					continue;
				int mask = j | pskill;
				if (!seen[mask] || dp[mask].size() > 1 + dp[j].size())
				{
					seen[mask] = true;
					dp[mask] = dp[j];
					dp[mask].push_back(i);
				}
			}
		}
		return dp[(1 << N) - 1];
	}
};