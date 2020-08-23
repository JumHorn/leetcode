#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> smallestSufficientTeam(vector<string> &req_skills, vector<vector<string>> &people)
	{
		int N = req_skills.size();
		unordered_map<int, vector<int>> res; //{skillmask,people}
		unordered_map<string, int> skills;   //{skill,bit}
		for (int i = 0; i < N; ++i)
			skills[req_skills[i]] = 1 << i;
		res[0] = {};
		for (int i = 0; i < (int)people.size(); ++i)
		{
			int pskill = 0;
			for (auto &str : people[i])
				pskill |= skills[str];
			auto old = res;
			for (auto &iter : old)
			{
				int mask = iter.first | pskill;
				if (res.find(mask) == res.end() || res[mask].size() > 1 + iter.second.size())
				{
					res[mask] = iter.second;
					res[mask].push_back(i);
				}
			}
		}
		return res[(1 << N) - 1];
	}
};