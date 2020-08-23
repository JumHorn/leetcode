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
		unordered_map<string, int> skills;
		int allskills = 0;
		for (int i = 0; i < (int)req_skills.size(); i++)
		{
			skills[req_skills[i]] = (1 << i);
			allskills |= (1 << i);
		}
		vector<int> peopleskill(people.size());
		for (int i = 0; i < (int)people.size(); i++)
		{
			for (int j = 0; j < (int)people[i].size(); j++)
				peopleskill[i] |= skills[people[i][j]];
			if ((peopleskill[i] ^ allskills) == 0)
				return {i};
		}

		queue<pair<int, unordered_set<int>>> q; //{skills, people's index}
		unordered_set<int> seen;
		for (int i = 0; i < (int)peopleskill.size(); i++)
		{
			if (seen.find(peopleskill[i]) == seen.end())
			{
				q.push({peopleskill[i], {i}});
				seen.insert(peopleskill[i]);
			}
		}
		while (!q.empty())
		{
			int size = q.size();
			while (--size >= 0)
			{
				for (int i = 0; i < (int)peopleskill.size(); i++)
				{
					int pskill = q.front().first;
					pskill |= peopleskill[i];
					if (seen.find(pskill) == seen.end())
					{
						if ((pskill ^ allskills) == 0)
						{
							q.front().second.insert(i);
							return vector<int>(q.front().second.begin(), q.front().second.end());
						}
						seen.insert(pskill);
						q.push(q.front()); //append new result to the queue
						q.back().first = pskill;
						q.back().second.insert(i);
					}
				}
				q.pop();
			}
		}
		return {};
	}
};