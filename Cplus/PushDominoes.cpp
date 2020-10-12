#include <string>
using namespace std;

class Solution
{
public:
	string pushDominoes(string dominoes)
	{
		int N = dominoes.size(), pre = -1; //pre right
		for (int i = 0; i < N; ++i)
		{
			if (dominoes[i] == 'R')
				pre = i;
			else if (dominoes[i] == 'L')
			{
				if (pre == -1)
					pushLeft(dominoes, i - 1);
				else
				{
					int middle = (i - pre) / 2 + pre;
					pushLeft(dominoes, middle, i);
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

	void pushLeft(string &dominoes, int index) //push to first not vertical
	{
		while (index >= 0 && dominoes[index] == '.')
			dominoes[index--] = 'L';
	}

	void pushLeft(string &dominoes, int middle, int right) //push to middle
	{
		while (middle < right)
			dominoes[right--] = 'L';
	}
};