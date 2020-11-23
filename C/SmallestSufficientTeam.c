#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int skillsBit(char **req_skills, int req_skillsSize, char *skill)
{
	for (int i = 0; i < req_skillsSize; ++i)
	{
		if (strcmp(req_skills[i], skill) == 0)
			return i;
	}
	return 0;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *smallestSufficientTeam(char **req_skills, int req_skillsSize, char ***people, int peopleSize, int *peopleColSize, int *returnSize)
{
	int N = req_skillsSize;
	int dp[1 << N];
	memset(dp, 0, sizeof(dp));
	int path[1 << N][2]; //{previous mask,person id}
	memset(path, -1, sizeof(path));
	bool seen[1 << N];
	memset(seen, 0, sizeof(seen));
	seen[0] = true;
	for (int i = 0; i < peopleSize; ++i)
	{
		int pskill = 0;
		for (int j = 0; j < peopleColSize[i]; ++j)
			pskill |= 1 << skillsBit(req_skills, req_skillsSize, people[i][j]);
		if (pskill == 0)
			continue;

		for (int j = (1 << N) - 1; j >= 0; --j)
		{
			if (!seen[j])
				continue;
			int mask = j | pskill;
			if (!seen[mask] || dp[mask] > 1 + dp[j])
			{
				seen[mask] = true;
				dp[mask] = dp[j] + 1;
				path[mask][0] = j;
				path[mask][1] = i;
			}
		}
	}

	int *res = (int *)malloc(sizeof(int) * peopleSize);
	*returnSize = 0;
	for (int mask = (1 << N) - 1; mask != -1; mask = path[mask][0])
	{
		if (path[mask][1] != -1)
			res[(*returnSize)++] = path[mask][1];
	}
	return res;
}