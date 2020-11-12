#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))

int dfs(char *board, int *map)
{
	int res = 100;
	char dummy[20] = {0};
	if (!*board)
		return 0;
	for (int i = 0, j = 0; board[i]; i = j++)
	{
		while (board[i] == board[j])
			++j;
		int insert = max(3 - (j - i), 0);
		if (map[board[i] - 'A'] >= insert)
		{
			strncpy(dummy, board, i);
			strcpy(&dummy[i], &board[j]);
			map[board[i] - 'A'] -= insert;
			int insert_needed = dfs(dummy, map) + insert;
			res = min(res, insert_needed);
			map[board[i] - 'A'] += insert;
		}
	}
	return res;
}

int findMinStep(char *board, char *hand)
{
	int map[26] = {0};
	for (; *hand; ++hand)
		++map[*hand - 'A'];
	int res = dfs(board, map);
	return res >= 100 ? -1 : res;
}