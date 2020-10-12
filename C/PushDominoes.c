
void pushToHead(char* dominoes, int index)  //push to first not vertical
{
	while (index >= 0 && dominoes[index] == '.')
		dominoes[index--] = 'L';
}

void pushToMid(char* dominoes, int middle, int right)  //push to middle
{
	while (middle < right)
		dominoes[right--] = 'L';
}

char* pushDominoes(char* dominoes)
{
	int pre = -1;  //pre right
	for (int i = 0; dominoes[i]; ++i)
	{
		if (dominoes[i] == 'R')
			pre = i;
		else if (dominoes[i] == 'L')
		{
			if (pre == -1)
				pushToHead(dominoes, i - 1);
			else
			{
				int middle = (i - pre) / 2 + pre;
				pushToMid(dominoes, middle, i);
				if ((i - pre + 1) % 2 == 1)
					dominoes[middle] = '.';
			}
			pre = -1;
		}
		else if (pre != -1)
			dominoes[i] = 'R';
	}
	return dominoes;
}
