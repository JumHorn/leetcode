#include <string.h>

int dfs(char *board, int *map)
{
	int res = 100;
	if (!*board)
		return 0;
	char dummy[17];
	for (int i = 0, j = 0; board[i];)
	{
		while (board[j] && board[i] == board[j])
			++j;
		int insert = 3 - (j - i);
		if (insert < 0)
			insert = 0;
		if (map[board[i] - 'A'] >= insert)
		{
			memcpy(dummy, board, i);
			strcpy(&dummy[i], &board[j]);
			map[board[i] - 'A'] -= insert;
			int tmp = dfs(dummy, map) + insert;
			if (tmp < res)
				res = tmp;
			map[board[i] - 'A'] += insert;
		}
		i = j++;
	}
	return res;
}

int findMinStep(char *board, char *hand)
{
	int map[26] = {0};
	while (*hand)
	{
		++map[*hand - 'A'];
		++hand;
	}
	int size = strlen(board);
	int res = dfs(board, map);
	return res == 100 ? -1 : res;
}