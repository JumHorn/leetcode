#include <stdlib.h>
#include <string.h>

//cmp function don't consider overflow
int cmp(const void *lhs, const void *rhs)
{
	int *l = (int *)lhs, *r = (int *)rhs;
	for (int i = 0; i <= 26; ++i)
	{
		if (l[i] != r[i])
			return l[i] - r[i];
	}
	return 0;
}

char *rankTeams(char **votes, int votesSize)
{
	int team[26][27] = {0};  //0-25 rank count last 26 for team name
	int N = strlen(votes[0]);
	for (int i = 0; i < N; ++i)
		team[votes[0][i] - 'A'][26] = votes[0][i];
	for (int i = 0; i < votesSize; ++i)
	{
		for (int j = 0; j < N; ++j)
			--team[votes[i][j] - 'A'][j];
	}
	qsort(team, 26, sizeof(team[0]), cmp);
	char *res = (char *)malloc(sizeof(char) * (N + 1));
	res[N] = '\0';
	for (int i = 0, j = 0; i < N; ++i)
		res[j++] = team[i][26];
	return res;
}
