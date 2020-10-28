#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	string rankTeams(vector<string> &votes)
	{
		vector<vector<int>> team(26, vector<int>(27)); //0-25 rank count last 26 for team name
		int N = votes[0].size();
		for (auto c : votes[0])
			team[c - 'A'][26] = c;
		for (auto &vote : votes)
		{
			for (int i = 0; i < N; ++i)
				--team[vote[i] - 'A'][i];
		}
		sort(team.begin(), team.end());
		string res;
		for (int i = 0; i < N; ++i)
			res.push_back(team[i][26]);
		return res;
	}
};